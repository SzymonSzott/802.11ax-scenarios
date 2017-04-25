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

int countAPs(int layers); // Count the number of APs per layer

int main (int argc, char *argv[])
{

	/* Initialize parameters */
	double simulationTime = 10; //seconds
    int layers=3; 
    bool debug=false;

	/* Command line parameters */

	CommandLine cmd;
	cmd.AddValue ("simulationTime", "Simulation time [s]", simulationTime);
    cmd.AddValue ("layers", "Number of layers in hex grid", layers);
    cmd.AddValue ("debug", "Enable debug mode", debug);
	cmd.Parse (argc,argv);

	/* Position APs */
    if(debug){
        std::cout << "There are "<< countAPs(layers) << " APs in " << layers << " layers.\n";
    }
  
	
/*
// calculate_AP_position function
	double **calculate_AP_positions(double first_x, double first_y, int h, int layers){

    float sq=sqrt(3);

    float x=0;
    float y=0;

    int dimension=2; //number of dimensions: x and y
    int APnum=AP_number(layers); //number of AP calculated by the AP_number function

    cout<<APnum<<endl;


    vector <float> x_co;
    vector <float> y_co;

    x_co.push_back(first_x);
    y_co.push_back(first_y);

        for(int lay=1; lay<layers;lay++){
            for(int k=1;k<=7;k++){
                if(k==1){
                        x=x+h*sq;
                        y=y+h;

                        x_co.push_back(x);
                        y_co.push_back(y);

                    }
                else if(k==2){
                    for(int hex_lay=1; hex_lay<=lay; hex_lay++){

                        x=x-h*sq;
                        y=y+h;

                        x_co.push_back(x);
                        y_co.push_back(y);
                    }

                    }

                else if(k==3){
                    for(int hex_lay=1; hex_lay<=lay; hex_lay++){

                        x=x-h*sq;
                        y=y-h;

                        x_co.push_back(x);
                        y_co.push_back(y);
                    }
                    }
                else if(k==4){
                    for(int hex_lay=1; hex_lay<=lay; hex_lay++){

                        y=y-2*h;

                        x_co.push_back(x);
                        y_co.push_back(y);
                    }
                    }
                else if(k==5){
                    for(int hex_lay=1; hex_lay<=lay; hex_lay++){

                        x=x+h*sq;
                        y=y-h;

                        x_co.push_back(x);
                        y_co.push_back(y);
                    }
                    }
                else if(k==6){
                    for(int hex_lay=1; hex_lay<=lay; hex_lay++){

                        x=x+h*sq;
                        y=y+h;

                        x_co.push_back(x);
                        y_co.push_back(y);
                    }
                    }
                else if(k==7){
                        for(int hex_lay=1; hex_lay<=lay; hex_lay++){
                            y=y+2*h;
                            if(hex_lay<lay){
                                x_co.push_back(x);
                                y_co.push_back(y);
                            }
                }
                }
            }
            }


    string file_name="coord.ods";

    std::ofstream coordfile;
    coordfile.open (file_name.c_str(), ios::app);



 double** AP_co=0;
    AP_co = new double*[2];
    AP_co[0]=new double[APnum];
    AP_co[1]=new double[APnum];

    for (int p=0;p<APnum;p++){
        AP_co[0][p]=x_co[p];
        AP_co[1][p]=y_co[p];
    }


      for ( int m = 0; m < APnum; ++m){
      coordfile<<x_co[m]<<"\t"<<y_co[m]<<endl;
      }

    coordfile.close();
    return AP_co;
    }
*/
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

int countAPs(int layers){ 
    int APsum=1; //if 1 layer then 1 AP
    if(layers>1) {
        for(int i=0; i<layers; i++) {
              APsum=APsum+6*i;
        }
    }
    return APsum;
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
