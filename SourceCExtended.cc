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

#include "SourceCExtended.h"

using namespace mtq;

Define_Module(SourceCExtended);

void SourceCExtended::initialize()
{
    Source::initialize();
}

void SourceCExtended::handleMessage(cMessage *msg)
{
    Source::handleMessage(msg);
}

CustomerJob *SourceCExtended::createJob()
{
    char buf[80];
    sprintf(buf, "%.60s-%d", jobName.c_str(), ++jobCounter);
    EV << "Energia richiesta:" << par("needEnergy").doubleValue();
    CustomerJob *job = new CustomerJob(buf);
    job -> setEnergy(par("needEnergy"));
    return (CustomerJob*) job;
}


