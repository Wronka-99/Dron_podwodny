#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>

template <class Typ, int Wymiar>
class Wektor {
  protected:
  Typ tab[Wymiar];
  
  public:
  Wektor() { for (Typ &tab_i: tab) tab_i = 0; };

  //Funkcja dodająca dwa wektory
  Wektor<Typ,Wymiar> operator + (const Wektor<Typ,Wymiar> & W2) const; 
  //Funkcja odejumujaca dwa wektory
  Wektor<Typ,Wymiar> operator - (const Wektor<Typ,Wymiar> & W2) const;
  //Mnożenie skalarnie
  Typ operator * (const Wektor<Typ,Wymiar> & W2) const; 
  Wektor<Typ,Wymiar> operator * (double liczba) const; 
  Wektor<Typ,Wymiar> operator / (double) const; 

  //Przeciążenia operatorów
  Typ  operator [] (int ind) const { return tab[ind]; }
  Typ &operator [] (int ind)       { return tab[ind]; }

};



//Funkcja wczytująca wektor
template <class Typ, int Wymiar>
std::istream& operator >> (std::istream &Strm, Wektor<Typ,Wymiar> &W){
  for(int i=0; i<Wymiar; ++i){
    Strm >> W[i];
  }
  return Strm;
}

//Funkcja wyświetlajaca wektor
template <class Typ, int Wymiar>
std::ostream & operator << (std::ostream &Strm, const Wektor<Typ,Wymiar> &W) {

    for(int i=0; i<Wymiar; ++i){
    Strm << W[i] << " ";
    }
    return Strm;
}

//Dodaje wektory
template <class Typ, int Wymiar>
Wektor<Typ,Wymiar> Wektor<Typ,Wymiar>::operator + (const Wektor<Typ,Wymiar> & W2) const {
    
    Wektor<Typ,Wymiar> wynik;
    
    for(int i=0; i < Wymiar; ++i) {
    wynik[i] = tab[i] + W2[i];
    }
    return wynik;
}
//Odejmuje wektory
template <class Typ, int Wymiar>
Wektor<Typ,Wymiar> Wektor<Typ,Wymiar>::operator - (const Wektor<Typ,Wymiar> & W2) const {
    
    Wektor<Typ,Wymiar> wynik;
    
    for(int i=0; i < Wymiar; ++i) {
    wynik[i] = tab[i] - W2[i];
    }
    return wynik;
}

//Mnozy wektor przez liczbe
template <class Typ, int Wymiar>
Wektor<Typ,Wymiar> Wektor<Typ,Wymiar>::operator * (double  liczba) const {
    Wektor<Typ,Wymiar> wynik;

    for(int i=0; i<Wymiar; ++i) {
        wynik[i] = tab[i] * liczba;
    }
    return wynik;
}

//Dzieli wektor przez liczbe
template <class Typ, int Wymiar>
Wektor<Typ,Wymiar> Wektor<Typ,Wymiar>::operator / (double  liczba) const {
    Wektor<Typ,Wymiar> wynik;

    if(liczba == 0) {
        std::cerr << "Nie można dzielić przez zero" << std::endl;
    } else {
    for(int i=0; i<Wymiar; ++i) {
        wynik[i] = tab[i] / liczba;
    }
    }
    return wynik;
}

//Mnozy wektor przez wektor
template<class Typ,int Wymiar>
Typ Wektor<Typ,Wymiar>::operator * (const Wektor<Typ,Wymiar> & W2) const {
    Typ wynik;
    wynik=0;
    for(int i=0; i<Wymiar; ++i){
    wynik += W2[i]*tab[i];
    }
    return wynik;
}

#endif
