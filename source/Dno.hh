#ifndef DNO_HH
#define DNO_HH

#include "Przeszkoda.hh"

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Dno{
    
protected:
       double polozenie;
public:

    double zwroc_glebokosc(){ return polozenie;}  
    void tworzenie_dna(double glebokosc,std::shared_ptr<drawNS::Draw3DAPI> api){
     
    polozenie=glebokosc;
          
     api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(10,-10,glebokosc),  drawNS::Point3D(-10,-10,glebokosc)        
	  },{
	 drawNS::Point3D(10,10,glebokosc), drawNS::Point3D(-10,10,glebokosc)       
	  }},"red");

           // drawNS::Point3D(10,-10,glebokosc), drawNS::Point3D(-10,-10,glebokosc), drawNS::Point3D(10,10,glebokosc), drawNS::Point3D(-10,10,glebokosc)
           // ,"blue";//rysuje niebieski prostopadloscian

    }
    
    
};

#endif