#include <iostream>
#include "Dron.hh"
#include "Prostopadloscian.hh"
#include "Dr3D_gnuplot_api.hh"

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue." << std::endl;
  } while(std::cin.get() != '\n');
}


    
int main()
{
    
    Prostopadloscian dron;
    cout << "Poczatek rysowania " << endl << endl;
    Wektor<double,3> srodek;
    Wektor<double,3> srodek2;
    Wektor<double,3> przesuniecie;
    int wymia_x;
    int wymia_y;
    int wymia_z;
    char os='z';
    int rysowanie=0;
    int przesuwanie=0;
    int obracanie=0;

    cout << "Podaj wspolrzedne srodka w kolejnosci x, y, z." << endl << endl;
    cin>>srodek[0];
    cin>>srodek[1];
    cin>>srodek[2];

    cout << "Podaj wymiary drona w kolejnosci x, y, z." << endl << endl;
    cin>>wymia_x;
    cin>>wymia_y;
    cin>>wymia_z;

    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,0)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
    wait4key();

    
    int tworzenie=dron.stworz_prostopadloscian(srodek, wymia_x, wymia_y, wymia_z );
     
    rysowanie=dron.rysuj_prostopadloscian(api);
    wait4key();

    obracanie=dron.obroc(45, 'x');

    rysowanie=dron.rysuj_prostopadloscian(api);
    wait4key();

    cout << "Podaj wektor przesuniecia x, y, z." << endl << endl;
    cin>>przesuniecie[0];
    cin>>przesuniecie[1];
    cin>>przesuniecie[2];
    
    przesuwanie=dron.przesuniecie_prostopadlscianu(przesuniecie);
     
    rysowanie=dron.rysuj_prostopadloscian(api);

    wait4key();

    
    przesuwanie=dron.przesuniecie_prostopadlscianu(przesuniecie);
    rysowanie=dron.rysuj_prostopadloscian(api);
    wait4key();


    //przesuwanie=dron.przesuniecie_prostopadlscianu(przesuniecie);
    //obracanie=dron.obroc(45, 'y');

    //rysowanie=dron.rysuj_prostopadloscian(api);

    wait4key();





    /*
    Dron_podwodny dron;
    int rysowanie=dron.rysowanie_drona(api, srodek, wymiar_x, wymiar_y, wymiar_z );
    wait4key();

    cout << "Podaj wektor przesuniecia x, y, z." << endl << endl;
    cin>>przesuniecie[0];
    cin>>przesuniecie[1];
    cin>>przesuniecie[2];

    for(int i=0;i<3;i++)
    {
      srodek2[i]=srodek[i]+przesuniecie[i];
    }
    
     
    int rysowanie2=dron.rysowanie_drona(api, srodek2, wymiar_x, wymiar_y, wymiar_z );
    wait4key();
    */
     return 0;
}
