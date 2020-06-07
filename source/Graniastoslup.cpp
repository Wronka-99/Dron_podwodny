#include "Bryla.hh"
#include "Wektor.hh"
#include "Graniastoslup.hh"
#include <vector>
#include "Dr3D_gnuplot_api.hh"
#include <iostream>

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;




    int Graniastoslup::stworz_graniastoslup(Wektor<double,3> srodek, double x, double y)
    {

            Wektor<double,3> srodek1;
            Wektor<double,3> srodek2;
            double x2=-x;
            srodek1=srodek_bryly;
            srodek2=srodek_bryly;

            srodek1[2]=srodek_bryly[2]+0.5*y;
            srodek2[2]=srodek_bryly[2]-0.5*y;

            tablica_wierzcholkow[0][0]=x+srodek1[0];
            tablica_wierzcholkow[0][1]=srodek1[1];
            tablica_wierzcholkow[0][2]=srodek1[2];

            tablica_wierzcholkow[1][0]=0.5*x+srodek1[0];
            tablica_wierzcholkow[1][1]=srodek1[1]+x*sqrt(3)/2;
            tablica_wierzcholkow[1][2]=srodek1[2];

            tablica_wierzcholkow[2][0]=-0.5*x+srodek1[0];
            tablica_wierzcholkow[2][1]=srodek1[1]+x*sqrt(3)/2;
            tablica_wierzcholkow[2][2]=srodek1[2];

            tablica_wierzcholkow[3][0]=srodek1[0]-x;
            tablica_wierzcholkow[3][1]=srodek1[1];
            tablica_wierzcholkow[3][2]=srodek1[2];

            tablica_wierzcholkow[4][0]=-0.5*x+srodek1[0];
            tablica_wierzcholkow[4][1]=srodek1[1]-x*sqrt(3)/2;
            tablica_wierzcholkow[4][2]=srodek1[2];

            tablica_wierzcholkow[5][0]=0.5*x+srodek1[0];
            tablica_wierzcholkow[5][1]=srodek1[1]-x*sqrt(3)/2;
            tablica_wierzcholkow[5][2]=srodek1[2];





            tablica_wierzcholkow[6][0]=x+srodek2[0];
            tablica_wierzcholkow[6][1]=srodek2[1];
            tablica_wierzcholkow[6][2]=srodek2[2];

            tablica_wierzcholkow[7][0]=0.5*x+srodek2[0];
            tablica_wierzcholkow[7][1]=srodek2[1]+x*sqrt(3)/2;
            tablica_wierzcholkow[7][2]=srodek2[2];

            tablica_wierzcholkow[8][0]=-0.5*x+srodek2[0];
            tablica_wierzcholkow[8][1]=srodek2[1]+x*sqrt(3)/2;
            tablica_wierzcholkow[8][2]=srodek2[2];

            tablica_wierzcholkow[9][0]=srodek2[0]-x;
            tablica_wierzcholkow[9][1]=srodek2[1];
            tablica_wierzcholkow[9][2]=srodek2[2];

            tablica_wierzcholkow[10][0]=-0.5*x+srodek2[0];
            tablica_wierzcholkow[10][1]=srodek2[1]-x*sqrt(3)/2;
            tablica_wierzcholkow[10][2]=srodek2[2];

            tablica_wierzcholkow[11][0]=0.5*x+srodek2[0];
            tablica_wierzcholkow[11][1]=srodek2[1]-x*sqrt(3)/2;
            tablica_wierzcholkow[11][2]=srodek2[2];

            

            

       

    }





    int Graniastoslup::przesuniecie_graniastoslupa(Wektor<double,3> wektor_przesuniecia)
    {

                srodek_bryly=wektor_przesuniecia+srodek_bryly; 


    }






    int Graniastoslup::rysuj_graniastoslup(std::shared_ptr<drawNS::Draw3DAPI> api)
    {


                 Wektor<double,3> tablica_wierzcholkow_tmp[12];
                 Wektor<double,3> przesuniecie;
                 int c;

                
                srodek_bryly=Orientacja*srodek_bryly;
                
                for(int a=0; a<12; a++)
                {
                        tablica_wierzcholkow_tmp[a]=srodek_bryly+Orientacja*tablica_wierzcholkow[a];

                }

                
                c=api->draw_polyhedron(vector<vector<Point3D> > {{

                        drawNS::Point3D(tablica_wierzcholkow_tmp[0][0],tablica_wierzcholkow_tmp[0][1],tablica_wierzcholkow_tmp[0][2]), 
                        drawNS::Point3D(tablica_wierzcholkow_tmp[1][0],tablica_wierzcholkow_tmp[1][1],tablica_wierzcholkow_tmp[1][2]),
                        drawNS::Point3D(tablica_wierzcholkow_tmp[2][0],tablica_wierzcholkow_tmp[2][1],tablica_wierzcholkow_tmp[2][2]), 
                        drawNS::Point3D(tablica_wierzcholkow_tmp[3][0],tablica_wierzcholkow_tmp[3][1],tablica_wierzcholkow_tmp[3][2]),
                        drawNS::Point3D(tablica_wierzcholkow_tmp[4][0],tablica_wierzcholkow_tmp[4][1],tablica_wierzcholkow_tmp[4][2]), 
                        drawNS::Point3D(tablica_wierzcholkow_tmp[5][0],tablica_wierzcholkow_tmp[5][1],tablica_wierzcholkow_tmp[5][2])
                },
                
                
                {
                        drawNS::Point3D(tablica_wierzcholkow_tmp[6][0],tablica_wierzcholkow_tmp[6][1],tablica_wierzcholkow_tmp[6][2]),
                        drawNS::Point3D(tablica_wierzcholkow_tmp[7][0],tablica_wierzcholkow_tmp[7][1],tablica_wierzcholkow_tmp[7][2]),
                        drawNS::Point3D(tablica_wierzcholkow_tmp[8][0],tablica_wierzcholkow_tmp[8][1],tablica_wierzcholkow_tmp[8][2]),
                        drawNS::Point3D(tablica_wierzcholkow_tmp[9][0],tablica_wierzcholkow_tmp[9][1],tablica_wierzcholkow_tmp[9][2]),
                        drawNS::Point3D(tablica_wierzcholkow_tmp[10][0],tablica_wierzcholkow_tmp[10][1],tablica_wierzcholkow_tmp[10][2]), 
                        drawNS::Point3D(tablica_wierzcholkow_tmp[11][0],tablica_wierzcholkow_tmp[11][1],tablica_wierzcholkow_tmp[11][2])     
                }}
                
                ,"red");//rysuje niebieski prostopadloscian

    

        
        return c;

    }




    int Graniastoslup::zmaz_graniastoslup(std::shared_ptr<drawNS::Draw3DAPI> api, int a)
    {


            api->erase_shape(a); //usuwa kształt o id a 


    }




    int Graniastoslup::obroc_graniastoslup(double alfa, char os)
    {



            Orientacja.obracanie(alfa,os);



    }



