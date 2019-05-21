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

#ifndef CUSTOMERJOB_H_
#define CUSTOMERJOB_H_

#include <omnetpp.h>
#include "Job.h"

//using namespace omnetpp;
using namespace queueing;

namespace mtq {

class CustomerJob : public Job  {
private:
    int needEnergy;
public:
    void setEnergy(double energy);
    int getEnergy();
    CustomerJob();
    CustomerJob(const char *name=nullptr, int kind=0, JobList *table=nullptr);
    virtual ~CustomerJob ();
};

} /* namespace mtq */

#endif /* CUSTOMERJOB_H_ */
