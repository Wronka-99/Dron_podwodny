#ifndef BRYLA_HH
#define BRYLA_HH
#include "Wektor.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Macierz_obrotu.hh"
#include <vector>

class Bryla{
    
protected:
<<<<<<< HEAD:source/Bryla.hh
    Wektor<double,3> srodek_bryly;
    Macierz_obrotu Orientacja;
public:
    
    void przesun_o_wektor(Wektor<double,3> Wektor);
    void obroc(double kat);
=======
    Wektor3D srodek_bryly;
    Macierz_obrotu polozenie_wzgledem plaszczyzn;
public:
    
    void obracanie(double kat);
    void przesun_bryle(Wektor3D Wektor);
    
>>>>>>> d55486512a7a5ca923904e369512848c63290882:source/inc/Bryla.hh
    
};

#endif
