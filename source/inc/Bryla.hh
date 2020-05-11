#ifndef BRYLA_HH
#define BRYLA_HH
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Macierz_obrotu.hh"

class Bryla{
    
protected:
    Wektor3D srodek_bryly;
    Macierz_obrotu polozenie_wzgledem plaszczyzn;
public:
    
    void obracanie(double kat);
    void przesun_bryle(Wektor3D Wektor);
    
    
};

#endif
