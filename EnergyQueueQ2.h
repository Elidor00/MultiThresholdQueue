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


#ifndef ENERGYQUEUEQ2_H_
#define ENERGYQUEUEQ2_H_

#include <omnetpp.h>
#include "PassiveQueue.h"
#include "EnergyJob.h"
#include "Job.h"
#include "ServerExt.h"

//using namespace omnetpp;
using namespace queueing;

namespace mtq {
/**
 * TODO - Generated class
 */
class EnergyQueueQ2 : public PassiveQueue
{
    private:
        int energyRequested;
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        virtual void refreshDisplay();
    public:
        EnergyQueueQ2();
        virtual ~EnergyQueueQ2();
        // The following methods are called from IServer:
        virtual int length() override;
        virtual void request(int gateIndex, int amount);

};

};


#endif
