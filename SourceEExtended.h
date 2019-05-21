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

#ifndef SOURCEEEXTENDED_H_
#define SOURCEEEXTENDED_H_

#include <omnetpp.h>
#include "Source.h"
#include "EnergyJob.h"

//using namespace omnetpp;
using namespace queueing;

namespace mtq {
/**
 * TODO - Generated class
 */
class SourceEExtended : public Source {
protected:
   virtual void initialize() override;
   virtual void handleMessage(cMessage *msg) override;
   virtual EnergyJob *createJob() override;
};

} /* namespace mtq */

#endif /* SOURCEEEXTENDED_H_ */
