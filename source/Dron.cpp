#include "Dron.hh"
#include <iostream>


using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;



int Dron_podwodny::rysowanie_drona(std::shared_ptr<drawNS::Draw3DAPI> api, Wektor<double,3> srodek, int wymiar_x, int wymiar_y, int wymiar_z){
    
    double x=wymiar_x/2;
    double y=wymiar_y/2;
    double z=wymiar_z/2;

    Wektor<double,3> tab_wierzch[8];

        tab_wierzch[0][0]=srodek[0]-x;
        tab_wierzch[0][1]=srodek[1]-y;
        tab_wierzch[0][2]=srodek[2]-z;

        tab_wierzch[1][0]=srodek[0]-x;
        tab_wierzch[1][1]=srodek[1]-y;
        tab_wierzch[1][2]=srodek[2]+z;
        

        tab_wierzch[2][0]=srodek[0]+x;
        tab_wierzch[2][1]=srodek[1]-y;
        tab_wierzch[2][2]=srodek[2]+z;

        tab_wierzch[3][0]=srodek[0]+x;
        tab_wierzch[3][1]=srodek[1]-y;
        tab_wierzch[3][2]=srodek[2]-z;

        tab_wierzch[4][0]=srodek[0]-x;
        tab_wierzch[4][1]=srodek[1]+y;
        tab_wierzch[4][2]=srodek[2]-z;

        tab_wierzch[5][0]=srodek[0]-x;
        tab_wierzch[5][1]=srodek[1]+y;
        tab_wierzch[5][2]=srodek[2]+z;

        tab_wierzch[6][0]=srodek[0]+x;
        tab_wierzch[6][1]=srodek[1]+y;
        tab_wierzch[6][2]=srodek[2]+z;

        tab_wierzch[7][0]=srodek[0]+x;
        tab_wierzch[7][1]=srodek[1]+y;
        tab_wierzch[7][2]=srodek[2]-z;

    api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(tab_wierzch[0][0],tab_wierzch[0][1],tab_wierzch[0][2]), drawNS::Point3D(tab_wierzch[1][0],tab_wierzch[1][1],tab_wierzch[1][2]), drawNS::Point3D(tab_wierzch[2][0],tab_wierzch[2][1],tab_wierzch[2][2]), drawNS::Point3D(tab_wierzch[3][0],tab_wierzch[3][1],tab_wierzch[3][2])
      },{
	drawNS::Point3D(tab_wierzch[4][0],tab_wierzch[4][1],tab_wierzch[4][2]), drawNS::Point3D(tab_wierzch[5][0],tab_wierzch[5][1],tab_wierzch[5][2]), drawNS::Point3D(tab_wierzch[6][0],tab_wierzch[6][1],tab_wierzch[6][2]), drawNS::Point3D(tab_wierzch[7][0],tab_wierzch[7][1],tab_wierzch[7][2])       
	  }},"blue");
 /**
 * Rysuje niebieski prostopadloscian
 */
    }



