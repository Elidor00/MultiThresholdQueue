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

#include "ServerExt.h"

using namespace mtq;

Define_Module(ServerExt);

ServerExt::ServerExt() {
    // TODO Auto-generated constructor stub

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
    Server::numInitStages();
}

void ServerExt::handleMessage(cMessage *msg)
{
    Server::handleMessage(msg);
}

void ServerExt::refreshDisplay()
{
    Server::refreshDisplay();
}

void ServerExt::finish()
{
    Server::finish();
}



