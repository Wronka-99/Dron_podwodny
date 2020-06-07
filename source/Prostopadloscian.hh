#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Bryla.hh"
#include "Wektor.hh"
#include <vector>
#include "Dr3D_gnuplot_api.hh"

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Prostopadloscian:public Bryla{

protected:
        Wektor<double,3> tablica_wierzcholkow[8];
        double wymiar_x;
        double wymiar_y;
        double wymiar_z;
        Wektor<double,3> prawa_sruba;
        Wektor<double,3> lewa_sruba;
        
public:
    int stworz_prostopadloscian(Wektor<double,3> srodek, double x, double y, double z);
    int przesuniecie_prostopadlscianu(Wektor<double,3> wektor_przesuniecia);
    int rysuj_prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> api);
    int zmaz_prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> api, int a);
    int obroc(double alfa, char os);
    double promien();
    double zwroc_wymiar_z(){ return wymiar_z;};
};

/*

*/
#endif