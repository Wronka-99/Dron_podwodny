#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include <iostream>
#include "Bryla.hh"
#include "Wektor.hh"
#include <vector>
#include "Dr3D_gnuplot_api.hh"

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Graniastoslup:public Bryla{

protected:
        Wektor<double,3> tablica_wierzcholkow[12];
        
public:


    int stworz_graniastoslup(Wektor<double,3> srodek, double x, double y);
    int przesuniecie_graniastoslupa(Wektor<double,3> wektor_przesuniecia);
    int rysuj_graniastoslup(std::shared_ptr<drawNS::Draw3DAPI> api);
    int zmaz_graniastoslup(std::shared_ptr<drawNS::Draw3DAPI> api, int a);
    int obroc_graniastoslup(double alfa, char os);
};




/*

*/
#endif