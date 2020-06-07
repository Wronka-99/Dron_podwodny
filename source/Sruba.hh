#ifndef SRUBA_HH
#define SRUBA_HH

#include "Bryla.hh"
#include "Wektor.hh"
#include <vector>
#include "Dr3D_gnuplot_api.hh"
#include "Graniastoslup.hh"

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Sruba:public Graniastoslup{

protected:
        
        
public:
    int polacz_z_dronem(Wektor<double,3> wierzcholek)
    {
            srodek_bryly=wierzcholek;
    };

    
    
};

/*

*/
#endif