#ifndef BRYLA_HH
#define BRYLA_HH
#include "Wektor.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Macierz_obrotu.hh"
#include <vector>
#include <unistd.h>

class Bryla{
    
protected:
    Wektor<double,3> srodek_bryly;
    Macierz_obrotu Orientacja;
public:
    
    
    void przesun_o_wektor(Wektor<double,3> Wektor);
    void obroc(double kat);
    
};

#endif