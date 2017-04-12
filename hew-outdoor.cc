/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
* Copyright (c) 2017
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation;
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
* Authors: Szymon Szott <szott@kt.agh.edu.pl>
*/

#include "ns3/core-module.h"
#include "ns3/applications-module.h"
#include "ns3/wifi-module.h"
#include "ns3/mobility-module.h"
#include "ns3/internet-module.h"


// This is an implementation of the TGax (HEW) outdoor scenario.

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("hew-outdoor");

int main (int argc, char *argv[])
{

	/* Initialize parameters */
	double simulationTime = 10; //seconds

	/* Command line parameters */

	CommandLine cmd;
	cmd.AddValue ("simulationTime", "Simulation time [s]", simulationTime);
	cmd.Parse (argc,argv);

	/* Position APs */

	//(x, y) = calculateAPpositions(nAP);
	//placeAP(x, y, NodeContainer);

	/* Position STAs */

	//foreach (AP) {placeSTA(Xap, Yap, nSta, radius (=ICD/2))}

	/* Configure propagation model */

	/* Configure MAC and PHY */

	//PopulateArpCache ();

	/* Configure Internet stack */

	/* Configure applications */

	/* Configure tracing */

	//EnablePcap ();

	/* Run simulation */

	Simulator::Stop (Seconds (simulationTime));
	Simulator::Run ();

	/* Calculate results */


       /* End of simulation */
        Simulator::Destroy ();
        return 0;
}

/*      Geovani's  Part
void placeAP(double x,double y,NodeContainer &accessPoint)
{

    MobilityHelper mobility;
    Ptr<ListPositionAllocator> positionAlloc = CreateObject<ListPositionAllocator> ();


         positionAlloc->Add (Vector (x,y, 0.0));
         positionAlloc->Add (Vector (50.0,0.0, 0.0));
         positionAlloc->Add (Vector (-50.0,0.0, 0.0));
         positionAlloc->Add (Vector (0.0,50.0, 0.0));
         positionAlloc->Add (Vector (0.0,-50.0, 0.0));


    mobility.SetPositionAllocator (positionAlloc);

    mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
    mobility.Install (accessPoint);

}

void showPosition(NodeContainer &accessPoint)
{

     int APnumber = 1;
    for(NodeContainer::Iterator nAP = accessPoint.Begin (); nAP !=accessPoint .End (); ++nAP)
    {
        Ptr<Node> object = *nAP;
        Ptr<MobilityModel> position = object->GetObject<MobilityModel> ();
        NS_ASSERT (position != 0);
        Vector pos = position->GetPosition ();
        std::cout <<"AP"<<"("<<APnumber<<")"<<" has coordinates "<< "(" << pos.x << ", " << pos.y <<")" << std::endl;
        ++APnumber;

    }

}
*/
