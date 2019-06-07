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

#include "EnergyQueueQ2.h"

namespace mtq {

Define_Module(EnergyQueueQ2);

EnergyQueueQ2::EnergyQueueQ2() : PassiveQueue() {
    // TODO Auto-generated constructor stub
    energyRequested = 0;
}

EnergyQueueQ2::~EnergyQueueQ2() {
    // TODO Auto-generated destructor stub
}

void EnergyQueueQ2::initialize()
{
    PassiveQueue::initialize();
}

void EnergyQueueQ2::handleMessage(cMessage *msg)
{
    Job *job = check_and_cast<Job *>(msg);
        job->setTimestamp();

        // check for container capacity
        if (capacity >= 0 && queue.getLength() >= capacity) {
            EV << "Queue full! Job dropped.\n";
            if (hasGUI())
                bubble("Dropped!");
            emit(droppedSignal, 1);
            delete msg;
            return;
        }

       if (!check_and_cast<ServerExt *>(this->gate("out",0)->getNextGate()->getOwnerModule())->needEnergy()){
            queue.insert(job);
            emit(queueLengthSignal, length());
            job->setQueueCount(job->getQueueCount() + 1);
        }
        else if (length() == 0) {
            // send through without queueing
            sendJob(job,0);
        }
        else
            throw cRuntimeError("This should not happen. Queue is NOT empty and there is an IDLE server attached to us.");

}

void EnergyQueueQ2::refreshDisplay()
{
    PassiveQueue::refreshDisplay();
}

int EnergyQueueQ2::length()
{
    return PassiveQueue::length();
}

void EnergyQueueQ2::request(int gateIndex, int amount)
{
    this->energyRequested = amount;
    //PassiveQueue::request(gateIndex);

    Enter_Method("request()!");
    ASSERT(!queue.isEmpty());
    EnergyJob *job;

    while(energyRequested>0  && !queue.isEmpty()){

        job = (EnergyJob *)queue.pop();

        emit(queueLengthSignal, length());

        job->setQueueCount(job->getQueueCount()+1);
        simtime_t d = simTime() - job->getTimestamp();
        job->setTotalQueueingTime(job->getTotalQueueingTime() + d);
        emit(queueingTimeSignal, d);
        energyRequested -= job->getEnergyForPacket();
        sendJob(job, gateIndex);
    }

}

}

/* namespace mtq */
