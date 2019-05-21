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

#include "EnergyJob.h"

namespace mtq {

EnergyJob::EnergyJob(const char *name, int kind, JobList *table) : Job(name, kind, table) {
    // TODO Auto-generated constructor stub

}

EnergyJob::~EnergyJob() {
    // TODO Auto-generated destructor stub
}

void EnergyJob::setEnergyForPacket(int ParEnergyForPacket)
{
    energyForPacket = ParEnergyForPacket;
}

int EnergyJob::getEnergyForPacket()
{
    return energyForPacket;
}

}
