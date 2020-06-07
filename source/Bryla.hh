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
    
    
    void przesun_o_wektor(Wektor<double,3> Wektor){srodek_bryly=srodek_bryly+Wektor;};
    int obroc_bryle(double kat, char os){  Orientacja.obracanie(kat,os); return 1; };
    Wektor<double,3> zwroc_srodek(){ return srodek_bryly;};
    double zwroc_wspolrzedna_srodka(int x){ return srodek_bryly[x];};
    
};

#endif