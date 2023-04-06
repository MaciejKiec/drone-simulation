#include "scena.hh"


void Scena::dodaj_drona(drawNS::Draw3DAPI * api){
   std::shared_ptr<Dron> NowyDron(new Dron(Wektor<3> {0,0,0}, MacierzRot2D<3>(0,"Z"),api));
   NowyDron->lec_do_gory(-14);
   NowyDron->zeruj();
   Drony.push_back(NowyDron);
   NowyDron->rysuj();
} 

void Scena::dodaj_element_krajobrazu(std::shared_ptr<InteraktywnyElementPowierzchni> Przeszkoda){
    Przeszkody.push_back(Przeszkoda);
} 


void Scena::rysuj_wszystkie(drawNS::Draw3DAPI * api){
    for(int i = 0; i < Drony.size(); i++){
        Drony[i]->rysuj();
    }

    /*for(int i = 0; i < Przeszkody.size(); i++){
        switch(Przeszkody[i]->ID()){
            case 1:
            {
                std::shared_ptr<plaskowyz> temp = std::dynamic_pointer_cast<plaskowyz>(Przeszkody[i]);
                temp->rysuj();
            }
            break;
            case 2:
            {
               //plaskowyz_prosty *temp = dynamic_cast<plaskowyz_prosty *>(Przeszkody[i]);
               // temp->rysuj(); 
            }
            break;
            case 3:
            {
                //Wzgorze *temp = dynamic_cast<Wzgorze *>(Przeszkody[i]);
                //ctemp->rysuj();
            }
            break;
            default:
            std::cerr << "Błąd! Nie rozpoznano bryły!";
            exit(0);
            break;
        }
    } */
} 

void Scena::pokaz_id_el_krajobrazu(){
    if (Przeszkody.size() == 0) std::cout << "Brak elementów krajobrazu!\n";
    for(int i = 0; i < Przeszkody.size(); i++){
       std::cout << "Id bryły: " << Przeszkody[i]->get_id_bryly();
        switch(Przeszkody[i]->ID()){
            case 1:
            {
                std::cout << " Rodzaj bryły: płaskowyż, o środku w punkcie: " << Przeszkody[i]->get_srodek() << std::endl;
            }
            break;
            case 2:
            {
               std::cout << " Rodzaj bryły: płaskowyż prosty, o środku w punkcie: " << Przeszkody[i]->get_srodek() << std::endl;
            }
            break;
            case 3:
            {
                std::cout << " Rodzaj bryły: wzgórze, o środku w punkcie: " << Przeszkody[i]->get_srodek() << std::endl;
            }
            break;
            default:
            std::cerr << "Błąd! Nie rozpoznano bryły!" << std::endl;
            exit(0);
            break;
        }
    }
}

bool Scena::usun_element_krajobrazu(int id){
    int i = 0;
    if (Przeszkody.size() == 0){
    std::cout << "Brak elementów krajobrazu na scenie!\n";
    return 0;
    }
    while( (i < Przeszkody.size()) && (id != Przeszkody[i]->get_id_bryly())) i++;
    if(i == Przeszkody.size()){
        std::cout << "Nie znaleziono bryły o podanym id!\n";
        return 0;
    }else{
        std::cout << "Udało się znaleźć bryłę o podanym id! Zostanie ona usunięta!\n";
        Przeszkody.erase(Przeszkody.begin()+i);
        return 1;
    }
}

void Scena::pokaz_id_dronow(){
    if (Drony.size() == 0) std::cout << "Brak dronów!\n";
    for(int i = 0; i < Drony.size(); i++){
      std::cout << "ID drona: " << Drony[i]->get_id_bryly() << std::endl;
    }

}

bool Scena::usun_drona(int id){
    int i = 0;
    if(Drony.size()==0){
        std::cout << "Brak dronów na scenie!\n";
        return 0;
    }

    while(i<Drony.size() && id != Drony[i]->get_id_bryly()) i++;
        if (i == Drony.size()){
            std::cout << "Nie znaleziono drona o podanym id!\n";
            return 0;
        }else{
            std::cout << "Udało się znaleźć drona o podanym id! Zostanie on usunięty!\n";
            Drony[i]->zmaz();
            Drony.erase(Drony.begin()+i);
            return 1;
        }
    
}

bool Scena::wybierz_drona(int id){
    int i = 0;
    if(Drony.size()==0){
        std::cout << "Brak dronów na scenie!\n";
        return 0;
    }

    while(i<Drony.size() && id != Drony[i]->get_id_bryly()) i++;
        if (i == Drony.size()){
            std::cout << "Nie znaleziono drona o podanym id!\n";
            return 0;
        }else{
            std::cout << "Udało się znaleźć drona o podanym id! Od teraz operacje przeprowadzane będą na tym dronie!\n";
            AktualnyDron = Drony[i];
            return 1;
        }

}

bool Scena::animuj(Wektor<3> PunktKoncowy, double wysokosc_przelotu,Scena * scena){
    if(AktualnyDron == nullptr){
        std::cout << "Najpierw należy wybrac drona!\n";
        return 0;
    }else{
    PunktKoncowy = PunktKoncowy - AktualnyDron->srodek_drona();
    for(int i = 0; i < 144; i++){
      std::this_thread::sleep_for(std::chrono::milliseconds(7));
      AktualnyDron->porusz_wirnikami();
      AktualnyDron->lec_do_gory(wysokosc_przelotu/144);
      AktualnyDron->zmaz();
      AktualnyDron->rysuj();
      AktualnyDron->zeruj();
    }
   
   /* double test = ((korpus).get_MiddlePoint()[1]-PunktKoncowy[1])/((korpus).get_MiddlePoint()[0]-PunktKoncowy[0]);
    double test1 = ((korpus).get_MiddlePoint()[1]-(korpus).get_srodek()[1])/((korpus).get_MiddlePoint()[0]-(korpus).get_srodek()[0]);
    double angle = atan(((test-test1)/(1+test*test1)));
    angle = angle / atan(1) / 4 * 180;
    for(int i = 0; i <144; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(7));
        obroc(angle/144);
        porusz_wirnikami();
    } */

    
    for(int i = 0; i < 144; i++){
      std::this_thread::sleep_for(std::chrono::milliseconds(7));
      AktualnyDron->porusz_wirnikami();
      AktualnyDron->lec_do_przodu(PunktKoncowy[0]/144);
      AktualnyDron->lec_w_bok(PunktKoncowy[1]/144);
    }
    //std::cout << (korpus).get_srodek() << std::endl;

     for(int i = 0; i<Przeszkody.size();i++){
         if(Przeszkody[i]->czy_nad(AktualnyDron)){
             std::cout << "Wykryto przeszkodę\n";
             if(Przeszkody[i]->czy_ladowac(AktualnyDron)){
                 std::cout << "Można lądować\n";
                 break;
             }else{
                 while(Przeszkody[i]->czy_nad(AktualnyDron)){
                    std::this_thread::sleep_for(std::chrono::milliseconds(7));
                    AktualnyDron->porusz_wirnikami();
                    AktualnyDron->lec_do_przodu(PunktKoncowy[0]/144);
                    AktualnyDron->lec_w_bok(PunktKoncowy[1]/144);
             }
             std::cout << "Ominięto przeszkodę, można lądować\n";
            }
         }
     }

      for(int i = 0; i<Drony.size();i++){
         if(Drony[i]->czy_nad(AktualnyDron)){
             std::cout << "Wykryto przeszkodę\n";
             if(Drony[i]->czy_ladowac(AktualnyDron)){
                 std::cout << "Można lądować\n";
                 break;
             }else{
                 while(Drony[i]->czy_nad(AktualnyDron)){
                  for(int i = 0; i < 144; i++){
                    std::this_thread::sleep_for(std::chrono::milliseconds(7));
                    AktualnyDron->porusz_wirnikami();
                    AktualnyDron->lec_do_przodu(PunktKoncowy[0]/144);
                    AktualnyDron->lec_w_bok(PunktKoncowy[0]/144);
                    }
                 }
             }
         }
     }

     for(int i = 0; i < 144; i++){
      std::this_thread::sleep_for(std::chrono::milliseconds(7));
      AktualnyDron->porusz_wirnikami();
      AktualnyDron->lec_do_gory(-wysokosc_przelotu/144);
      AktualnyDron->zmaz();
      AktualnyDron->rysuj();
      AktualnyDron->zeruj(); 
    } 
        return 1; 
    }
}