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

#ifndef SERVEREXT_H_
#define SERVEREXT_H_

#include <omnetpp.h>
#include "Server.h"

//using namespace omnetpp;
using namespace queueing;

namespace mtq {

class ServerExt : public Server
{
    protected:
       virtual void initialize() override;
       virtual int numInitStages();
       virtual void handleMessage(cMessage *msg) override;
       virtual void refreshDisplay();
       virtual void finish() override;
    public:
        ServerExt();
        virtual ~ServerExt();

};

} /* namespace mtq */

#endif /* SERVEREXT_H_ */
