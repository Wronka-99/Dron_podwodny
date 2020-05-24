#ifndef MACIERZ_OBROTU_HH
#define MACIERZ3_OBROTU_HH

#include "Macierz.hh"

class Macierz_obrotu: public Macierz<double,3>
{

    protected:
            double stopnie;
            char os_obrotu;


    public:
    

    
    Macierz_obrotu obracanie(double stopnie,char os_obrotu){

            
        
    double kat = M_PI*stopnie/180;
        
            switch (os_obrotu){

                
                case 'x':
                        tab[1][1]=cos(kat);
                        tab[1][2]=sin(kat);
                        tab[2][1]=-sin(kat);
                        tab[2][2]=cos(kat);
                        tab[0][2]=0;
                        tab[0][1]=0;
                        tab[2][0]=0;
                        tab[1][0]=0;
                        tab[0][0]=1;
                break;

                case 'y':
                        tab[2][2]=cos(kat);
                        tab[2][0]=sin(kat);
                        tab[0][2]=-sin(kat);
                        tab[0][0]=cos(kat);
                        tab[1][0]=0;
                        tab[2][1]=0;
                        tab[0][1]=0;
                        tab[1][2]=0;
                        tab[1][1]=1;

                case 'z':
                        tab[0][0]=cos(kat);
                        tab[1][0]=-sin(kat);
                        tab[0][1]=sin(kat);
                        tab[1][1]=cos(kat);
                        tab[2][0]=0;
                        tab[0][2]=0;
                        tab[1][2]=0;
                        tab[2][1]=0;
                        tab[2][2]=1;
                break;
            }
                return (*this);
            }
};

#endif
