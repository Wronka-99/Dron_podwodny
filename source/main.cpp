#include <iostream>
#include <unistd.h>
#include "Dron.hh"
#include "Prostopadloscian.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Dno.hh"
#include "Tafla.hh"
#include "Graniastoslup.hh"
#include "Sruba.hh"

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
    Dron_podwodny tablica_dronow[10];
    int tablica_id[10];
    int licznik_dronow=0;
    int indeks_dronow=0;
    bool tablica_stworzenia[10]={0,0,0,0,0,0,0,0,0,0};
    Sruba sruba_prawa;
    Sruba sruba_lewa;
    cout << "Poczatek rysowania " << endl << endl;
    Wektor<double,3> srodek;
    Wektor<double,3> przesuniecie;
    Wektor<double,3> przesuniecie_pom;
    double wymia_x;
    double wymia_y;
    double wymia_z;
    int rysowanie1=0;
    int rysowanie2=0;
    double glebokosc;
    double kolizja_dno;
    double kolizja_tafla;
    int id2=0;
    char znak;
    double kat=0;
    char os;
    bool dzialanie=1;
    double zmienna=0;

    double promienie;
    double srodki;
    Wektor<double,3> srodki_wek;

    std::vector<Dron_podwodny*> kolekcja_dronow; 
    
    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,0)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
    
    
    glebokosc=20.0;
    tafla.tworzenie_tafli(glebokosc/2,api);
    dno.tworzenie_dna(-glebokosc/2,api);

    cout << "Maksymalna liczba dronow, ktore mozesz stworzyc to 10. " << endl << endl;
     cout << "Wszystkie maja takie same wymiary oraz poczatkowe wspolrzedne. " << endl << endl;
    srodek[0]=0.0;
    srodek[1]=0.0;
    srodek[2]=0.0;

    
  
    wymia_x=2.0;
    wymia_y=2.0;
    wymia_z=2.0;


    // wait4key();

    
         
    //tablica_dronow[indeks_dronow].stworz_prostopadloscian(srodek, wymia_x, wymia_y, wymia_z );
    //tablica_dronow[indeks_dronow].obroc(0, 'x');
    //kolekcja_dronow.push_back(new Dron_podwodny(tablica_dronow[indeks_dronow]));
    //id1=kolekcja_dronow[indeks_dronow]->rysuj_prostopadloscian(api);

    
   // wait4key();

    //sruba_prawa.stworz_graniastoslup(tablica_dronow[indeks_dronow].zwroc_wierzcholek_prawy(),0.5,1.0);
    //sruba_prawa.obroc_graniastoslup(0, 'x');
   // sruba_prawa.polacz_z_dronem(tablica_dronow[indeks_dronow].zwroc_wierzcholek_prawy());
    //id2=sruba_prawa.rysuj_graniastoslup(api);
    //wait4key();

    while(dzialanie)
    {
        cout<<"Wybierz co chcesz zrobic:"<<endl;
        cout<<"-nacisnij 'O' aby obrocic "<<endl;
        cout<<"-nacisnij 'P' aby przesnac "<<endl;
        cout<<"-nacisnij 'S' aby stworzyc drona "<<endl;
        cout<<"-nacisnij 'K' aby zakonczyc  "<<endl;
        cin>>znak;

        switch(znak)
        
          {

            case 'O':
                    cout<<"Podaj os i wartosc kata alfa w stopniach."<<endl<<endl;
                    cin>>os;
                    cin>>kat;
                    zmienna=kat/100.0;
                    kat=0.0;

                    cout<<"Wybierz numer drona, ktorym chcesz sie poruszac, liczone od 0."<<endl<<endl;
                    cin>>indeks_dronow;

                    
                    

                  for(int a=0; a<100; a++)
                  { 
                    
                    
                   // sruba_prawa.zmaz_graniastoslup(api, id2);
                    kolekcja_dronow[indeks_dronow]->zmaz_prostopadloscian(api, tablica_id[indeks_dronow]);
                    kolekcja_dronow[indeks_dronow]->obroc_bryle(kat, os);
                    //sruba_prawa.polacz_z_dronem(dron.zwroc_wierzcholek_prawy());
                    //sruba_prawa.obroc_bryle(kat,os);
                    tablica_id[indeks_dronow]=kolekcja_dronow[indeks_dronow]->rysuj_prostopadloscian(api);
                   // id2=sruba_prawa.rysuj_graniastoslup(api);
                    
                    
                    usleep(20000);
                    kat=zmienna+kat;
                  }

            break;

            case 'P':

                  

                  cout<<"Wybierz numer drona, ktorym chcesz sie poruszac, liczone od 0."<<endl<<endl;
                  cin>>indeks_dronow;

                   //id1=kolekcja_dronow[indeks_dronow]->rysuj_prostopadloscian(api);
                   //kolekcja_dronow[indeks_dronow]->zmaz_prostopadloscian(api, id1);

                  cout << "Podaj wektor przesuniecia x, y, z." << endl << endl;

                  cin>>przesuniecie[0];
                  cin>>przesuniecie[1];
                  cin>>przesuniecie[2];

                  przesuniecie=przesuniecie/100.0;
                  przesuniecie_pom[0]=-przesuniecie[0];
                  przesuniecie_pom[1]=-przesuniecie[1];
                  przesuniecie_pom[2]=-przesuniecie[2];
                  

                  

                  for(int a=0; a<100; a++)
                  {
                    kolekcja_dronow[indeks_dronow]->zmaz_prostopadloscian(api, tablica_id[indeks_dronow]);
                   // sruba_prawa.zmaz_graniastoslup(api, id2);
                    kolekcja_dronow[indeks_dronow]->przesun_o_wektor(przesuniecie);
                   // sruba_prawa.przesun_o_wektor(przesuniecie);
                    tablica_id[indeks_dronow]=kolekcja_dronow[indeks_dronow]->rysuj_prostopadloscian(api);

                    for(int i=0; i<licznik_dronow; i++)
                    {
                        
                        promienie=kolekcja_dronow[indeks_dronow]->promien()*2;

                            if(indeks_dronow!=i)
                            {
                              srodki_wek=kolekcja_dronow[indeks_dronow]->zwroc_srodek()-kolekcja_dronow[i]->zwroc_srodek();
                              srodki=srodki_wek.dlugoscWektora();
                            }
                          
                            if(0.1>abs(promienie-srodki))
                            {
                              cout<<"Kolizja dronow."<<endl<<endl;
                              kolekcja_dronow[indeks_dronow]->zmaz_prostopadloscian(api, tablica_id[indeks_dronow]);
                              kolekcja_dronow[indeks_dronow]->przesun_o_wektor(przesuniecie_pom);
                              tablica_id[indeks_dronow]=kolekcja_dronow[indeks_dronow]->rysuj_prostopadloscian(api);
                              a=100;
                            }

                    }

                    kolizja_tafla=abs(kolekcja_dronow[indeks_dronow]->zwroc_wspolrzedna_srodka(2)-tafla.zwroc_glebokosc());
                    
                    if(0.1>kolizja_tafla)
                    {
                           cout<<"Wyplynales na powierzchnie."<<endl<<endl;
                           kolekcja_dronow[indeks_dronow]->zmaz_prostopadloscian(api, tablica_id[indeks_dronow]);
                           kolekcja_dronow[indeks_dronow]->przesun_o_wektor(przesuniecie_pom);
                           tablica_id[indeks_dronow]=kolekcja_dronow[indeks_dronow]->rysuj_prostopadloscian(api);
                           
                           a=100; 

                    }

                    kolizja_dno=abs(kolekcja_dronow[indeks_dronow]->zwroc_wspolrzedna_srodka(2)-dno.zwroc_glebokosc()-kolekcja_dronow[indeks_dronow]->zwroc_wymiar_z());
                    
                    if(0.1>kolizja_dno)
                    {
                           cout<<"Kolizja z dnem."<<endl<<endl;
                           kolekcja_dronow[indeks_dronow]->zmaz_prostopadloscian(api, tablica_id[indeks_dronow]);
                           kolekcja_dronow[indeks_dronow]->przesun_o_wektor(przesuniecie_pom);
                           tablica_id[indeks_dronow]=kolekcja_dronow[indeks_dronow]->rysuj_prostopadloscian(api);
                           a=100; 

                    }


                    //id2=sruba_prawa.rysuj_graniastoslup(api);

                   
                    usleep(20000);
                  }

            break;

            case 'S':

                 
                  
                  tablica_dronow[licznik_dronow].stworz_prostopadloscian(srodek, wymia_x, wymia_y, wymia_z );
                  tablica_dronow[licznik_dronow].obroc(0, 'x');
                  kolekcja_dronow.push_back(new Dron_podwodny(tablica_dronow[licznik_dronow]));
                  tablica_id[licznik_dronow]=kolekcja_dronow[licznik_dronow]->rysuj_prostopadloscian(api);
                  cout<<"Zostal utworzony dron numer"<< licznik_dronow<<"zobaczysz go podczas operacji przesuwania."<<endl<<endl;
                  licznik_dronow++;
                  

                  

            break;

            case 'K':

                    dzialanie=0;
                    cout<<endl<<endl<<"Koniec dzialania programu."<<endl;
            break;

          }


    }
   
   /* 
   graniastoslup.zmaz_graniastoslup(api, id2);
                    obracanie2=graniastoslup.obroc_graniastoslup(kat, os);
                    id2=graniastoslup.rysuj_graniastoslup(api);
   
    graniastoslup.zmaz_graniastoslup(api, id2);
                    graniastoslup.przesuniecie_graniastoslupa(przesuniecie);
                    id2=graniastoslup.rysuj_graniastoslup(api);
   
   dron.zmaz_prostopadloscian(api, rysowanie);

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
