#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Bryla.hh"
#include "Wektor.hh"
#include <vector>

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Prostopadloscian:public Bryla{

protected:
        Wektor<double,3> tablica_wierzcholkow[8];
        
public:
    
    int stworz_prostopadloscian(Wektor<double,3> srodek, int x, int y, int z);
    int przesuniecie_prostopadlscianu(Wektor<double,3> wektor_przesuniecia);
    int rysuj_prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> api);
    int obroc(double alfa, char os);
};

/*

*/
#endif