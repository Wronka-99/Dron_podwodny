#include <iostream>
#include <unistd.h>
#include "Dron.hh"
#include "Prostopadloscian.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Dno.hh"
#include "Tafla.hh"

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
    Dno dno;
    Tafla tafla;
    Prostopadloscian dron;
    cout << "Poczatek rysowania " << endl << endl;
    Wektor<double,3> srodek;
    Wektor<double,3> przesuniecie;
    double wymia_x;
    double wymia_y;
    double wymia_z;
    int rysowanie=0;
    int przesuwanie=0;
    int obracanie=0;
    double glebokosc;
    int id=0;
    char znak;
    int kat=0;
    char os;
    bool dzialanie=1;

    
    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,0)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
    
    cout << "Podaj wysokosc zbiornika." << endl << endl;
    cin>>glebokosc;
    tafla.tworzenie_tafli(glebokosc/2,api);
    dno.tworzenie_dna(-glebokosc/2,api);

    cout << "Podaj wspolrzedne srodka w kolejnosci x, y, z." << endl << endl;
    cin>>srodek[0];
    cin>>srodek[1];
    cin>>srodek[2];

    cout << "Podaj wymiary drona w kolejnosci x, y, z." << endl << endl;
    cin>>wymia_x;
    cin>>wymia_y;
    cin>>wymia_z;

     wait4key();

    
    int tworzenie=dron.stworz_prostopadloscian(srodek, wymia_x, wymia_y, wymia_z );
    obracanie=dron.obroc(0, 'x');
    id=dron.rysuj_prostopadloscian(api);
    wait4key();


    while(dzialanie)
    {
        cout<<"Wybierz co chcesz zrobic:"<<endl;
        cout<<"-nacisnij 'O' aby obrocic "<<endl;
        cout<<"-nacisnij 'P' aby przesnac  "<<endl;
        cout<<"-nacisnij 'K' aby zakonczyc  "<<endl;
        cin>>znak;

        switch(znak)
        
          {

            case 'O':
                    cout<<"Podaj os i wartosc kata alfa w stopniach."<<endl<<endl;
                    cin>>os;
                    cin>>kat;
                    dron.zmaz_prostopadloscian(api, id);
                    obracanie=dron.obroc(kat, os);
                    id=dron.rysuj_prostopadloscian(api);

            break;

            case 'P':

                  cout << "Podaj wektor przesuniecia x, y, z." << endl << endl;

                  cin>>przesuniecie[0];
                  cin>>przesuniecie[1];
                  cin>>przesuniecie[2];

                  przesuniecie=przesuniecie/100.0;

                  for(int a=0; a<100; a++)
                  {
                    dron.zmaz_prostopadloscian(api, id);
                    dron.przesuniecie_prostopadlscianu(przesuniecie);
                    id=dron.rysuj_prostopadloscian(api);
                    usleep(20000);
                  }

            break;

            case 'K':

                    dzialanie=0;
                    cout<<endl<<endl<<"Koniec dzialania programu."<<endl;
            break;

          }


    }
   
   /* dron.zmaz_prostopadloscian(api, rysowanie);

    obracanie=dron.obroc(0, 'x');
    a=przesuniecie_animacja_drona(przesuniecie, dron, api, a);
    wait4key();

   
    
    obracanie=dron.obroc(45, 'y');
    a=przesuniecie_animacja_drona(przesuniecie, dron, api, a);
    wait4key();
     
    

    
    
    a=przesuniecie_animacja_drona(przesuniecie, dron, api, a);

    wait4key();
    //dron.zmaz_prostopadloscian(api, rysowanie);
    //rysowanie=dron.rysuj_prostopadloscian(api);
    a=przesuniecie_animacja_drona(przesuniecie, dron, api, a);
    wait4key();

    //dron.zmaz_prostopadloscian(api, rysowanie);
    //przesuwanie=dron.przesuniecie_prostopadlscianu(przesuniecie);
    //rysowanie=dron.rysuj_prostopadloscian(api);
    wait4key();


    //przesuwanie=dron.przesuniecie_prostopadlscianu(przesuniecie);
    //obracanie=dron.obroc(45, 'y');

    //rysowanie=dron.rysuj_prostopadloscian(api);

    wait4key();


*/


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
