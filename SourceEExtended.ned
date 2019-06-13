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

package mtq;
import org.omnetpp.queueing.Source;

//
// TODO auto-generated type
//
simple SourceEExtended extends Source
{
    parameters:
    	@class(SourceEExtended);
    	
    	@signal[nEnergyPacket](type="double");
    	//@statistic[nEnergyPacket](title = "number of a energy packets");
    	volatile double nEnergyPacket @unit();
    	
    	@signal[energyForPacket](type="int");
    	//@statistic[energyForPacket](title = "amount of energy for a single packet");
    	volatile int energyForPacket @unit();
}