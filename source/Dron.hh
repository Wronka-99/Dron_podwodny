#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "Prostopadloscian.hh"
#include "Wektor.hh"

class Dron_podwodny:public Prostopadloscian{
protected:
        
public:

        Wektor<double,3> zwroc_wierzcholek_prawy(){ return prawa_sruba;};
        Wektor<double,3> zwroc_wierzcholek_lewy(){ return lewa_sruba;};
        
    
};

#endif
