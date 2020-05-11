#ifndef BRYLA_HH
#define BRYLA_HH
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Macierz_obrotu.hh"

class Bryla{
    
protected:
    Wektor3D srodek_bryly;
    Macierz_obrotu Orientacja;
public:
    
    void przesun_o_wektor(Wektor3D Wektor);
    void obroc(double kat);
    
};

#endif