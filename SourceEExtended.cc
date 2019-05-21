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

#include "SourceEExtended.h"

using namespace mtq;

Define_Module(SourceEExtended);

void SourceEExtended::initialize()
{
    Source::initialize();
}

void SourceEExtended::handleMessage(cMessage *msg)
{
        double generate_n = par("nEnergyPacket").doubleValue();
        ASSERT(msg->isSelfMessage());

        if ((numJobs < 0 || numJobs > jobCounter) && (stopTime < 0 || stopTime > simTime())) {
            // reschedule the timer for the next message
            scheduleAt(simTime() + par("interArrivalTime").doubleValue(), msg);

            for (int i = 0; i < generate_n; i++){
                Job *job = createJob();
                send(job, "out");
            };
        }
        else {
            // finished
            delete msg;
        }

}

EnergyJob *SourceEExtended::createJob()
{
    char buf[80];
    sprintf(buf, "%.60s-%d", jobName.c_str(), ++jobCounter);
    EnergyJob *job = new EnergyJob(buf);
    job -> setEnergyForPacket(par("energyForPacket"));
    return (EnergyJob*) job;
}

/* namespace mtq */
