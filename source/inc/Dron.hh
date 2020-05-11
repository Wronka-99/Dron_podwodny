#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "Prostopadloscian.hh"
#include "Wektor3D.hh"

class Dron_podwodny:public Prostopadloscian{
protected:
    double kat;
public:
    int rysowanie_drona(std::shared_ptr<drawNS::Draw3DAPI> api, Wektor3D srodek, int wymiar_x, int wymiar_y, int wymiar_z);
    
    
};

#endif
