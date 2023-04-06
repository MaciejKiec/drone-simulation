#include <iostream>
#include "macierzobrotu.hh"
#include "prostopadloscian.hh"
#include "powierzchnia.hh"
#include "dron.hh"
#include "plaskowyz_prosty.hh"
#include "plaskowyz.hh"
#include "graniastoslup6.hh"
#include "OpenGL_API.hh"
#include "wzgorze.hh"
#include "scena.hh"
#include <iostream>
#include <cmath>
using std::vector;
using drawNS::Point3D;
using drawNS::APIopenGL3D;
using std::cout;
using std::endl;

void stop(){
  std::cin.sync();
  std::cout << "Naciśnij enter, by kontynuować...";
  std::cin.ignore();
  std::cin.get();
}
 

int main(int argc, char **argv){
    int WymSceny = 15;
    int wybor, exit = 0;
    drawNS::Draw3DAPI *api = new APIopenGL3D(-WymSceny,WymSceny,-WymSceny,WymSceny,-WymSceny,WymSceny,1000,&argc,argv);
    api->change_ref_time_ms(0);
    const int delay_in_milliseconds = 7;
    Powierzchnia powierzchnia(-WymSceny);
  // Dron dron(Wektor<3> {0,0,0}, MacierzRot2D<3> (0,"X"));
   //dron.lec_do_gory(double(-WymSceny+1),api,dron);
   //dron.zeruj();
   //powierzchnia.rysuj(api,WymSceny);
   Scena NowaScena;
   std::shared_ptr<Wzgorze> StandardoweWzgorze(new Wzgorze(5,api));
   StandardoweWzgorze->zmaz();
   StandardoweWzgorze->Translacja(Wektor<3> {7,9,-15});
   StandardoweWzgorze->rysuj();
   NowaScena.dodaj_element_krajobrazu(StandardoweWzgorze);
   std::shared_ptr<plaskowyz> StandardowyPlaskowyz(new plaskowyz(8,api));
   StandardowyPlaskowyz->zmaz();
   StandardowyPlaskowyz->Translacja(Wektor<3> {-8,-8,-11});
   StandardowyPlaskowyz->rysuj();
   NowaScena.dodaj_element_krajobrazu(StandardowyPlaskowyz);
   std::shared_ptr<plaskowyz_prosty> StandardowyPlaskowyzProsty(new plaskowyz_prosty(6,8,10,api));
   StandardowyPlaskowyzProsty->zmaz();
   StandardowyPlaskowyzProsty->Translacja(Wektor<3> {10,-10,-11});
   StandardowyPlaskowyzProsty->rysuj();
   NowaScena.dodaj_element_krajobrazu(StandardowyPlaskowyzProsty);
   



   //dron.rysuj(api);
    while(wybor!=9){
      //NowaScena.rysuj_wszystkie(api);
      system("clear");

      std::cout << "Co chcesz zrobić?: \n1.Dodaj drona \n2.Usuń drona \n3.Dodaj element krajobrazu \n4.Usuń element krajobrazu \n5.Animacja przelotu drona \n6.Wybierz drona \n7.Pokaż id dronów\n8.Pokaż id elementów krajobrazu \n9.Wyjście\n";
      std::cin >> wybor;
        switch (wybor)
        {
        case 1:
        {
          system("clear");
          NowaScena.dodaj_drona(api);
          std::cout << "Pomyślnie dodano drona!\n";
          stop();
          exit = 1;
        }
          break;
         case 2:
         {
          system("clear");
          int id;
          std::cout << "Podaj id drona, którego chcesz usunąć: ";
          std::cin >> id;
          NowaScena.usun_drona(id);
          stop();
          exit = 1;
         }
          break;
        case 3:
          {
          system("clear");
          int wybor = 0;
          std::cout << "Który element krajobrazu chcesz dodać?\n1.Płaskowyż zdegenerowany\n2.Płaskowyż prosty\n3.Wzgórze\n";
          std::cin >> wybor;
          switch(wybor){
            case 1:
            {
            double wysokosc;
            std::cout << "Podaj wysokosć płaskowyżu: ";
            std::cin >> wysokosc;
            std::shared_ptr<InteraktywnyElementPowierzchni> NowaPrzeszkoda(new plaskowyz(wysokosc,api));
            NowaScena.dodaj_element_krajobrazu(NowaPrzeszkoda);
            }
            break;
            case 2:
            {
            double dlugosc, szerokosc, wysokosc;
            std::cout << "Podaj dlugosc: ";
            std::cin >> dlugosc;
            std::cout << "Podaj szerokosc: ";
            std::cin >> szerokosc;
            std::cout << "Podaj wysokosc: ";
            std::cin >> wysokosc;
            std::shared_ptr<InteraktywnyElementPowierzchni> NowaPrzeszkoda(new plaskowyz_prosty(dlugosc,szerokosc,wysokosc,api));
            NowaScena.dodaj_element_krajobrazu(NowaPrzeszkoda);
            }
            break;
            case 3:
            {
              double wysokosc;
              std::cout << "Podaj wysokość: ";
              std::cin >> wysokosc;
              std::shared_ptr<InteraktywnyElementPowierzchni> NowaPrzeszkoda(new Wzgorze(wysokosc,api));
              NowaScena.dodaj_element_krajobrazu(NowaPrzeszkoda);
              break;
            }
            default:
            std::cout << "Wprowadzono nierpawdiłową wartość!";
            break;
          }
          stop();
          exit = 1;
         }
          break;
        case 4:
          {
          int id;
          system("clear");
          //USUWANIE ELEMENTÓW KRAJOBRAZU
          std::cout << "Podaj id bryły, którą chcesz usunąć: ";
          std::cin >> id;
          if(id == 1){
            StandardoweWzgorze->zmaz();
          }else if(id == 2){
            StandardowyPlaskowyz->zmaz();
          }else if(id == 3){
            StandardowyPlaskowyzProsty->zmaz();
          }
          NowaScena.usun_element_krajobrazu(id);
          stop();
          exit = 1;
          break;
          }
          case 5:
          {
          double temp,x,y;
          system("clear");
          std::cout << "Przelot \n Wpisz wysokosc: ";
          std::cin >> temp;
          std::cout << "Wprowadź wartość x: ";
          std::cin >> x;
           std::cout << "Wprowadź wartość y: ";
          std::cin >> y;
          NowaScena.animuj(Wektor<3> {x,y,-13}, temp,&NowaScena);
          stop();
          exit = 1;
          }
          break;
        case 6:
          {
          system("clear");
          int id;
          std::cout << "Wprowadź id drona, którym chcesz sterować: ";
          std::cin >> id;
          NowaScena.wybierz_drona(id);
          stop();
          exit = 1;
          }
        break;
        case 7:
          system("clear");
          NowaScena.pokaz_id_dronow();
          stop();
          exit = 1;
        break;
        case 8:
          //Pokaż id elementów krajobrazu
          system("clear");
          NowaScena.pokaz_id_el_krajobrazu();
          stop();
          exit = 1;
        break;
        default:
          break;
        }
      if(exit == 1){
        wybor = 0;
        exit = 0;
      }
    } 
 

    /*powierzchnia.rysuj(api,WymSceny);
    dron.rysuj(api);
    api->redraw();
    stop();
    dron.obroc(45);
    dron.przelicz(dron);
    dron.zmaz(api);
    dron.rysuj(api);
    api->redraw();
    stop();
    dron.lec_do_gory(1);
    dron.obroc(-45);
    dron.przelicz(dron);
    dron.zmaz(api);
    dron.rysuj(api);
    api->redraw();
    stop();
    dron.porusz_wirnikami();
    dron.zmaz(api);
    dron.rysuj(api);
    api->redraw();
    stop();*/

    return 0;
}