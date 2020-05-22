#include "Prostopadloscian.hh"
#include "Bryla.hh"
#include "Wektor.hh"
#include <vector>
#include <iostream>


using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

int Prostopadloscian::stworz_prostopadloscian(Wektor<double,3> srodek, int x, int y, int z)
{
    
     x=x/2;
     y=y/2;
     z=z/2;
    
    srodek_bryly=srodek;
    

    

        tablica_wierzcholkow[0][0]=srodek_bryly[0]-x;
        tablica_wierzcholkow[0][1]=srodek_bryly[1]-y;
        tablica_wierzcholkow[0][2]=srodek_bryly[2]-z;

        tablica_wierzcholkow[1][0]=srodek_bryly[0]-x;
        tablica_wierzcholkow[1][1]=srodek_bryly[1]-y;
        tablica_wierzcholkow[1][2]=srodek_bryly[2]+z;
        

        tablica_wierzcholkow[2][0]=srodek_bryly[0]+x;
        tablica_wierzcholkow[2][1]=srodek_bryly[1]-y;
        tablica_wierzcholkow[2][2]=srodek_bryly[2]+z;

        tablica_wierzcholkow[3][0]=srodek_bryly[0]+x;
        tablica_wierzcholkow[3][1]=srodek_bryly[1]-y;
        tablica_wierzcholkow[3][2]=srodek_bryly[2]-z;

        tablica_wierzcholkow[4][0]=srodek_bryly[0]-x;
        tablica_wierzcholkow[4][1]=srodek_bryly[1]+y;
        tablica_wierzcholkow[4][2]=srodek_bryly[2]-z;

        tablica_wierzcholkow[5][0]=srodek_bryly[0]-x;
        tablica_wierzcholkow[5][1]=srodek_bryly[1]+y;
        tablica_wierzcholkow[5][2]=srodek_bryly[2]+z;

        tablica_wierzcholkow[6][0]=srodek_bryly[0]+x;
        tablica_wierzcholkow[6][1]=srodek_bryly[1]+y;
        tablica_wierzcholkow[6][2]=srodek_bryly[2]+z;

        tablica_wierzcholkow[7][0]=srodek_bryly[0]+x;
        tablica_wierzcholkow[7][1]=srodek_bryly[1]+y;
        tablica_wierzcholkow[7][2]=srodek_bryly[2]-z;

    
}


int Prostopadloscian::rysuj_prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> api)
{


        
        api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(tablica_wierzcholkow[0][0],tablica_wierzcholkow[0][1],tablica_wierzcholkow[0][2]), drawNS::Point3D(tablica_wierzcholkow[1][0],tablica_wierzcholkow[1][1],tablica_wierzcholkow[1][2]), drawNS::Point3D(tablica_wierzcholkow[2][0],tablica_wierzcholkow[2][1],tablica_wierzcholkow[2][2]), drawNS::Point3D(tablica_wierzcholkow[3][0],tablica_wierzcholkow[3][1],tablica_wierzcholkow[3][2])
      },{
	drawNS::Point3D(tablica_wierzcholkow[4][0],tablica_wierzcholkow[4][1],tablica_wierzcholkow[4][2]), drawNS::Point3D(tablica_wierzcholkow[5][0],tablica_wierzcholkow[5][1],tablica_wierzcholkow[5][2]), drawNS::Point3D(tablica_wierzcholkow[6][0],tablica_wierzcholkow[6][1],tablica_wierzcholkow[6][2]), drawNS::Point3D(tablica_wierzcholkow[7][0],tablica_wierzcholkow[7][1],tablica_wierzcholkow[7][2])       
	  }},"blue");//rysuje niebieski prostopadloscian
}



int Prostopadloscian::przesuniecie_prostopadlscianu(Wektor<double,3> wektor_przesuniecia)
{      
        
        srodek_bryly=wektor_przesuniecia+srodek_bryly;
        
        for(int i=0; i<8; i++)
        {

        tablica_wierzcholkow[i]=wektor_przesuniecia+tablica_wierzcholkow[i];
        }



}


int Prostopadloscian::obroc(double alfa, char os)
{
        Wektor<double,3> pomoc;
        pomoc[0]=0;
        pomoc[1]=0;
        pomoc[2]=0;

        for(int i=0; i<8;i++)
        {              
                pomoc=Orientacja.obracanie(alfa,os)*tablica_wierzcholkow[i];
                
                tablica_wierzcholkow[i]=tablica_wierzcholkow[i]+pomoc*4;
        }
}