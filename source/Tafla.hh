#ifndef TAFLA_HH
#define TAFLA_HH

#include "Przeszkoda.hh"

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Tafla{
    
protected:
       
public:
    
    void tworzenie_tafli(double wysokosc,std::shared_ptr<drawNS::Draw3DAPI> api){
        
            
     api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(10,-10,wysokosc),  drawNS::Point3D(-10,-10,wysokosc)        
	  },{
	 drawNS::Point3D(10,10,wysokosc), drawNS::Point3D(-10,10,wysokosc)       
	  }},"red");

           // drawNS::Point3D(10,-10,wysokosc), drawNS::Point3D(-10,-10,wysokosc), drawNS::Point3D(10,10,wysokosc), drawNS::Point3D(-10,10,wysokosc)
           // ,"blue";//rysuje niebieski prostopadloscian

    }
    
    
};

#endif