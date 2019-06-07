//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 
#include<iostream>
#include "ServerExt.h"
#include "Job.h"
#include "SelectionStrategies.h"
#include "IPassiveQueue.h"
#include "PassiveQueue.h"
#include "CustomerJob.h"
#include "EnergyQueueQ2.h"

using namespace mtq;

Define_Module(ServerExt);

ServerExt::ServerExt() {
    // TODO Auto-generated constructor stub
    needEn = false;
}

ServerExt::~ServerExt() {
    // TODO Auto-generated destructor stub
}

void ServerExt::initialize()
{
    Server::initialize();
}

int ServerExt::numInitStages()
{
    return Server::numInitStages();
}

void ServerExt::handleMessage(cMessage *msg)
{
    if (msg == endServiceMsg) {
            ASSERT(jobServiced != nullptr);
            ASSERT(allocated);
            simtime_t d = simTime() - endServiceMsg->getSendingTime();
            jobServiced->setTotalServiceTime(jobServiced->getTotalServiceTime() + d);
            send(jobServiced, "out");
            jobServiced = nullptr;
            allocated = false;
            emit(busySignal, false);

            // examine all input queues, and request a new job from a non empty queue
            EV << "requesting from customer " << endl;


            cGate *gate = this->gate("inCustomer");//   selectionStrategy->selectableGate(k);

            //queueing::PassiveQueue Q = check_and_cast<queueing::PassiveQueue *>(gate->getPreviousGate()->getOwnerModule());
            if (check_and_cast<queueing::PassiveQueue *>(gate->getPreviousGate()->getOwnerModule())->length() > 0) {
                check_and_cast<queueing::PassiveQueue *>(gate->getPreviousGate()->getOwnerModule())->request(gate->getIndex());
            }

        }
        else {
            std::string type=msg->getClassName();
            if( type  == "mtq::EnergyJob") {

                   return;
            }
            if (!allocated)
                error("job arrived, but the sender did not call allocate() previously");
            if (jobServiced)
                throw cRuntimeError("a new job arrived while already servicing one");

            mtq::CustomerJob *cj = check_and_cast<mtq::CustomerJob *>(msg);
            cj->getEnergy();
            cGate *gate = this->gate("inEnergy");
            check_and_cast<EnergyQueueQ2 *>(gate->getPreviousGate()->getOwnerModule())->request(gate->getIndex(),cj->getEnergy());

            jobServiced = check_and_cast<Job *>(msg);
            simtime_t serviceTime = par("serviceTime");
            scheduleAt(simTime()+serviceTime, endServiceMsg);
            emit(busySignal, true);
        }
}

bool ServerExt::needEnergy()
{
    EV << "need energy?" << needEn << endl;
    return needEn;
}

void ServerExt::refreshDisplay()
{
    Server::refreshDisplay();
}

void ServerExt::finish()
{
    Server::finish();
}


