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

#include "CustomerQueueQ1.h"

using namespace mtq;

Define_Module(CustomerQueueQ1);

CustomerQueueQ1::CustomerQueueQ1() : PassiveQueue()
{

}

CustomerQueueQ1::~CustomerQueueQ1()
{

}

void CustomerQueueQ1::initialize()
{
    PassiveQueue::initialize();
}

void CustomerQueueQ1::handleMessage(cMessage *msg)
{
    PassiveQueue::handleMessage(msg);
}

void CustomerQueueQ1::refreshDisplay()
{
    PassiveQueue::refreshDisplay();
}

int CustomerQueueQ1::length()
{
    return PassiveQueue::length();
}

void CustomerQueueQ1::request(int gateIndex)
{
    Enter_Method("request()!");

    ASSERT(!queue.isEmpty());

    CustomerJob* tmp_min = ((CustomerJob *) queue.get(0));
    for (int i=1; i < queue.length(); i++){
        if (((CustomerJob *) queue.get(i))->getEnergy()  < tmp_min->getEnergy()) {
            tmp_min = ((CustomerJob *) queue.get(i));
        }

    }
    queue.remove(tmp_min);

    emit(queueLengthSignal, length());

    tmp_min->setQueueCount(tmp_min->getQueueCount()+1);
    simtime_t d = simTime() - tmp_min->getTimestamp();
    tmp_min->setTotalQueueingTime(tmp_min->getTotalQueueingTime() + d);
    emit(queueingTimeSignal, d);

    sendJob(tmp_min, gateIndex);

}
