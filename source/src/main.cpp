#include <iostream>
#include "Dron.hh"
#include "Dr3D_gnuplot_api.hh"

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}


    
int main()
{
     
     cout << "Poczatek rysowania " << endl << endl;
    Wektor3D srodek;
    Wektor3D srodek2;
    Wektor3D przesuniecie;
    int wymiar_x;
    int wymiar_y;
    int wymiar_z;


    cout << "Podaj wspolrzedne srodka w kolejnosci x, y, z." << endl << endl;
    cin>>srodek[0];
    cin>>srodek[1];
    cin>>srodek[2];

    cout << "Podaj wymiary drona w kolejnosci x, y, z." << endl << endl;
    cin>>wymiar_x;
    cin>>wymiar_y;
    cin>>wymiar_z;

    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,0)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
    wait4key();
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
    
     return 0;
}
