#include "Prostopadloscian.hh"
#include "Bryla.hh"
#include "Wektor.hh"
#include <vector>
#include <iostream>


using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

int Prostopadloscian::stworz_prostopadloscian(Wektor<double,3> srodek, double x, double y, double z)
{
    
     x=x/2;
     y=y/2;
     z=z/2;

     wymiar_x=x;
     wymiar_y=y;
     wymiar_z=z;
    
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

double Prostopadloscian::promien()
{

        double x=wymiar_x/2;
        double y=wymiar_y/2;
        double z=wymiar_z/2;

        double promien=pow(x,2)+pow(y,2)+pow(z,2);
        promien=sqrt(promien);


}
int Prostopadloscian::rysuj_prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> api)
{
        Wektor<double,3> tablica_wierzcholkow_tmp[8];
        
        
        int c;



                
                srodek_bryly=Orientacja*srodek_bryly;
                
                for(int a=0; a<8; a++)
                {
                        tablica_wierzcholkow_tmp[a]=srodek_bryly+Orientacja*tablica_wierzcholkow[a];
                        
                }


                lewa_sruba=tablica_wierzcholkow_tmp[0];
                prawa_sruba=tablica_wierzcholkow_tmp[3];
                
                c=api->draw_polyhedron(vector<vector<Point3D> > {{
                drawNS::Point3D(tablica_wierzcholkow_tmp[0][0],tablica_wierzcholkow_tmp[0][1],tablica_wierzcholkow_tmp[0][2]), drawNS::Point3D(tablica_wierzcholkow_tmp[1][0],tablica_wierzcholkow_tmp[1][1],tablica_wierzcholkow_tmp[1][2]), drawNS::Point3D(tablica_wierzcholkow_tmp[2][0],tablica_wierzcholkow_tmp[2][1],tablica_wierzcholkow_tmp[2][2]), drawNS::Point3D(tablica_wierzcholkow_tmp[3][0],tablica_wierzcholkow_tmp[3][1],tablica_wierzcholkow_tmp[3][2])
                },{
                drawNS::Point3D(tablica_wierzcholkow_tmp[4][0],tablica_wierzcholkow_tmp[4][1],tablica_wierzcholkow_tmp[4][2]), drawNS::Point3D(tablica_wierzcholkow_tmp[5][0],tablica_wierzcholkow_tmp[5][1],tablica_wierzcholkow_tmp[5][2]), drawNS::Point3D(tablica_wierzcholkow_tmp[6][0],tablica_wierzcholkow_tmp[6][1],tablica_wierzcholkow_tmp[6][2]), drawNS::Point3D(tablica_wierzcholkow_tmp[7][0],tablica_wierzcholkow_tmp[7][1],tablica_wierzcholkow_tmp[7][2])       
                }},"blue");//rysuje niebieski prostopadloscian

    

        
        return c;
}


int Prostopadloscian::zmaz_prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> api,int a)
{
      api->erase_shape(a); //usuwa kształt o id a          
        
}


int Prostopadloscian::przesuniecie_prostopadlscianu(Wektor<double,3> wektor_przesuniecia)
{      
        
        srodek_bryly=wektor_przesuniecia+srodek_bryly;      

}

int Prostopadloscian::obroc(double alfa, char os)
{
        

        Orientacja.obracanie(alfa,os);

        
}