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

import org.omnetpp.queueing.Allocate;
import org.omnetpp.queueing.Deallocate;
import org.omnetpp.queueing.PassiveQueue;
import org.omnetpp.queueing.ResourcePool;
import org.omnetpp.queueing.Server;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;
import org.omnetpp.queueing.SourceOnce;


//
// TODO auto-generated type
//
network MTQ
{
    @display("bgb=629,247");
    submodules:
        sourceEExtended: SourceEExtended {
            @display("p=73,148");
        }
        customerQueueQ1: CustomerQueueQ1 {
            @display("p=233,53");
        }
        sink: Sink {
            @display("p=514,109");
        }
        sourceCExtended: SourceCExtended {
            @display("p=73,53");
        }
        serverExt: ServerExt {
            @display("p=387,109");
        }
        energyQueueQ2: EnergyQueueQ2 {
            @display("p=233,148");
        }
    connections:
        sourceCExtended.out --> customerQueueQ1.in++;
        sourceEExtended.out --> energyQueueQ2.in++;
        energyQueueQ2.out++ --> serverExt.inEnergy;
        customerQueueQ1.out++ --> serverExt.inCustomer;
        serverExt.out --> sink.in++;
}
