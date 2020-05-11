#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Bryla.hh"
#include "Wektor3D.hh"

class Prostopadloscian:public Bryla{

protected:
        Wektor3D tablica_wierzcholkow[8];

public:
    void ustaw_prostopadloscian(double rozmiar_x, double rozmiar_y, double rozmiar_z, Wektor3D wektor_srodek);
    
    void przesuniecie_prostopadlscianu(Wektor3D wektor_przesuniecia);
    void wymaz(std::shared_ptr<drawNS::Draw3DAPI>);
    void obroc(double alfa);
};

/*
void Prostopadloscian::ustaw_prostopadloscian(double rozmiar_x, double rozmiar_y, double rozmiar_z, Wektor3D wektor_srodek)
{

double x=0;
double y=0;
double z=0;

x=rozmiar_x/2;
y=rozmiar_y/2;
z=rozmiar_z/2;

        tablica_wierzcholkow[0][0]=srodek_bryly[0]+x;
        tablica_wierzcholkow[0][1]=srodek_bryly[1]+y;
        tablica_wierzcholkow[0][2]=srodek_bryly[2]-z;

        tablica_wierzcholkow[1][0]=srodek_bryly[0]+x;
        tablica_wierzcholkow[1][1]=srodek_bryly[1]-y;
        tablica_wierzcholkow[1][2]=srodek_bryly[2]-z;

        tablica_wierzcholkow[2][0]=srodek_bryly[0]-x;
        tablica_wierzcholkow[2][1]=srodek_bryly[1]-y;
        tablica_wierzcholkow[2][2]=srodek_bryly[2]-z;

        tablica_wierzcholkow[3][0]=srodek_bryly[0]-x;
        tablica_wierzcholkow[3][1]=srodek_bryly[1]+y;
        tablica_wierzcholkow[3][2]=srodek_bryly[2]-z;

        tablica_wierzcholkow[4][0]=srodek_bryly[0]+x;
        tablica_wierzcholkow[4][1]=srodek_bryly[1]+y;
        tablica_wierzcholkow[4][2]=srodek_bryly[2]+z;

        tablica_wierzcholkow[5][0]=srodek_bryly[0]+x;
        tablica_wierzcholkow[5][1]=srodek_bryly[1]-y;
        tablica_wierzcholkow[5][2]=srodek_bryly[2]+z;

        tablica_wierzcholkow[6][0]=srodek_bryly[0]-x;
        tablica_wierzcholkow[6][1]=srodek_bryly[1]-y;
        tablica_wierzcholkow[6][2]=srodek_bryly[2]+z;

        tablica_wierzcholkow[7][0]=srodek_bryly[0]-x;
        tablica_wierzcholkow[7][1]=srodek_bryly[1]+y;
        tablica_wierzcholkow[7][2]=srodek_bryly[2]+z;

        

}



void Prostopadloscian::przesuniecie_prostopadlscianu(Wektor3D wektor_przesuniecia)
{


        for(int i=0; i<8; i++)
        {
            tablica_wierzcholkow[i][0]=tablica_wierzcholkow[i][0]+wektor_przesuniecia[0];
            tablica_wierzcholkow[i][1]=tablica_wierzcholkow[i][1]+wektor_przesuniecia[1];
            tablica_wierzcholkow[i][2]=tablica_wierzcholkow[i][2]+wektor_przesuniecia[2];

        }



}*/
#endif