#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "Wektor.hh"


template<class Typ, int Wymiar>
class Macierz {
  protected:
  Wektor<Typ,Wymiar> tab[Wymiar];
  public:
  Macierz();

  Typ wyznacznik();

  //Transpozycja
  void transponuj();

  Macierz<Typ,Wymiar> operator * (const Macierz<Typ,Wymiar> & M2);
  Macierz<Typ,Wymiar> operator+(const Macierz<Typ,Wymiar> & M2);
  Macierz<Typ,Wymiar> operator-(const Macierz<Typ,Wymiar> & M2);
  Macierz<Typ,Wymiar> operator*(double l);
  Wektor<Typ,Wymiar> operator*(const Wektor<Typ,Wymiar> & W2) const;

  const Wektor<Typ,Wymiar> & operator[](int indeks) const{
    return tab[indeks];
  }
  Wektor<Typ,Wymiar> &operator[](int indeks){
    return tab[indeks];
  }
  
};

template<class Typ, int Wymiar>
Macierz<Typ,Wymiar>::Macierz(){
  for(int i=0;i<Wymiar; ++i){
    for(int j=0;j<Wymiar;++j){
      tab[i][j]=0;
    }
  }
}
template<class Typ, int Wymiar>
std::istream& operator >> (std::istream &Strm, Macierz<Typ,Wymiar> &Mac){
  for(int i=0; i<Wymiar; ++i){
    Strm>>Mac[i];
  }
  return Strm;
}
template<class Typ, int Wymiar>
std::ostream& operator << (std::ostream &Strm, const Macierz<Typ,Wymiar> &Mac){
  for(int i=0;i<Wymiar;++i){
    Strm << Mac[i] << " " << std::endl;
  }
  return Strm;
}

template<class Typ,int Wymiar>
void Macierz<Typ,Wymiar>::transponuj() {
   Macierz<Typ,Wymiar> wynik;
   for(int i=0; i<Wymiar; ++i){
    for(int j=0; j<Wymiar; ++j){
      wynik[i][j]=tab[j][i]; 
    }
 }
  for(int i=0; i<Wymiar; ++i){
    for(int j=0; j<Wymiar; ++j){
      tab[i][j]=wynik[i][j];
    }
 }
}

template<class Typ,int Wymiar>
Typ Macierz<Typ,Wymiar>::wyznacznik() {
  Typ wsp;
  Typ wynik;
  wsp = 0;
  wynik = 1;

  for(int i=0; i<Wymiar-1; ++i){    
    for(int j=i+1; j<Wymiar; ++j){   
      wsp = tab[j][i]*(-1) / tab[i][i];
      for(int k=i;k<Wymiar;++k){  
      tab[j][k] = tab[j][k] + (wsp*tab[i][k]);    //zerowanie kolumny
      }
    }  
  }
  for(int l=0; l<Wymiar; ++l){
    wynik = tab[l][l] * wynik;  //obliczanie wyznacznik
  }
  return wynik;
}


template<class Typ,int Wymiar>
Wektor<Typ,Wymiar> Macierz<Typ,Wymiar>::operator * (const Wektor<Typ,Wymiar> & W2) const {
  Typ iloczyn;
  Wektor<Typ,Wymiar> wynik;
  for(int i=0; i<Wymiar; ++i){
    for(int j=0; j<Wymiar; ++j){
      iloczyn=tab[i][j]*W2[j];
      wynik[i]= wynik[i] + iloczyn;
    }
  }
  return wynik;
 }

#endif
