#include "dron.hh"

void Dron::rysuj() {
    korpus.rysuj(get_rysownik());
    (wirniki[0]).rysuj(get_rysownik());
    (wirniki[1]).rysuj(get_rysownik());
    (wirniki[2]).rysuj(get_rysownik());
    (wirniki[3]).rysuj(get_rysownik());
}

void Dron::przelicz(UkladW W){
    korpus.przelicz_uklad_do(W);
    (wirniki[0]).przelicz_uklad_do(W);
    (wirniki[1]).przelicz_uklad_do(W);
    (wirniki[2]).przelicz_uklad_do(W);
    (wirniki[3]).przelicz_uklad_do(W);
}

void Dron::zmaz(){
    get_rysownik() -> erase_shape(korpus.get_idFigury());
    get_rysownik() -> erase_shape((wirniki[0]).get_id_wirnika());
    get_rysownik() -> erase_shape((wirniki[1]).get_id_wirnika());
    get_rysownik() -> erase_shape((wirniki[2]).get_id_wirnika());
    get_rysownik() -> erase_shape((wirniki[3]).get_id_wirnika());
}

void Dron::lec_do_gory(double wys){
    this->Translacja(Wektor<3> {0,0,wys});
    this->przelicz(*this);
}

void Dron::lec_do_przodu(double odl){
    korpus.Translacja(Wektor<3> {odl,0,0});
    (wirniki[0]).Translacja(Wektor<3> {odl,0,0});
    (wirniki[1]).Translacja(Wektor<3> {odl,0,0});
    (wirniki[2]).Translacja(Wektor<3> {odl,0,0});
    (wirniki[3]).Translacja(Wektor<3> {odl,0,0});
    this->przelicz(*this);
    this->zmaz();
    this->rysuj();
    this->zeruj();
}

void Dron::lec_w_bok(double odl){
    korpus.Translacja(Wektor<3> {0,odl,0});
    (wirniki[0]).Translacja(Wektor<3> {0,odl,0});
    (wirniki[1]).Translacja(Wektor<3> {0,odl,0});
    (wirniki[2]).Translacja(Wektor<3> {0,odl,0});
    (wirniki[3]).Translacja(Wektor<3> {0,odl,0});
    this->przelicz(*this);
    this->zmaz();
    this->rysuj();
    this->zeruj();
}

void Dron::obroc(double kat){
    MacierzRot2D<3> macierz(kat,"Z");
    korpus.set_orientacja(macierz);
    (wirniki[0]).set_srodek((korpus.get_SrodekRotora())[3]);
    (wirniki[1]).set_srodek((korpus.get_SrodekRotora())[2]);
    (wirniki[2]).set_srodek((korpus.get_SrodekRotora())[1]);
    (wirniki[3]).set_srodek((korpus.get_SrodekRotora())[0]);
    this->przelicz(*this);
    this->zmaz();
    this->rysuj();
}

void Dron::porusz_wirnikami(){
    (wirniki[0]).set_orientacja(MacierzRot2D<3> (10,"Z"));
    (wirniki[1]).set_orientacja(MacierzRot2D<3> (10,"Z"));
    (wirniki[2]).set_orientacja(MacierzRot2D<3> (10,"Z"));
    (wirniki[3]).set_orientacja(MacierzRot2D<3> (10,"Z"));
    this->przelicz(*this);
    this->zmaz();
    this->rysuj();
    this->zeruj();
}

void Dron::zeruj(){
    this->srodek = Wektor<3> {0,0,0};
    this->orientacja = MacierzRot2D<3> (0,"X");

}

void Dron::Przelot(Wektor<3> PunktKoncowy, double wysokosc_przelotu, Scena * scena){

    /*
    PunktKoncowy = PunktKoncowy - (korpus).get_srodek();
    for(int i = 0; i < 144; i++){
      std::this_thread::sleep_for(std::chrono::milliseconds(7));
      porusz_wirnikami();
      lec_do_gory(wysokosc_przelotu/144);
      zmaz();
      rysuj();
      zeruj();
    }
    double test = ((korpus).get_MiddlePoint()[1]-PunktKoncowy[1])/((korpus).get_MiddlePoint()[0]-PunktKoncowy[0]);
    double test1 = ((korpus).get_MiddlePoint()[1]-(korpus).get_srodek()[1])/((korpus).get_MiddlePoint()[0]-(korpus).get_srodek()[0]);
    double angle = atan(((test-test1)/(1+test*test1)));
    angle = angle / atan(1) / 4 * 180;
    for(int i = 0; i <144; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(7));
        obroc(angle/144);
        porusz_wirnikami();
    }

    
    for(int i = 0; i < 144; i++){
      std::this_thread::sleep_for(std::chrono::milliseconds(7));
      porusz_wirnikami();
      lec_do_przodu(PunktKoncowy[0]/144);
      lec_w_bok(PunktKoncowy[1]/144);
    }
    std::cout << (korpus).get_srodek() << std::endl;

    for(int i = 0; i<scena->get_przeszkody.size();i++){
        (scena->get_przeszkody[i])->czy_nad(this);
    }

     for(int i = 0; i < 144; i++){
      std::this_thread::sleep_for(std::chrono::milliseconds(7));
      porusz_wirnikami();
      lec_do_gory(-wysokosc_przelotu/144);
      zmaz();
      rysuj();
      zeruj(); 
    } */

}

bool Dron::czy_nad(std::shared_ptr<InterfejsDrona> AktualnyDron){
    Wektor<3> temp1 = srodek - AktualnyDron->srodek_drona();
    double Srodki = temp1.dlugosc_w_rzucie_OXY();
    if((Srodki) < 6){
        return 1;
    }else{
    return 0;
    }
}

bool Dron::czy_ladowac(std::shared_ptr<InterfejsDrona> AktualnyDron){
    if (czy_nad(AktualnyDron) == 0){
        return 1;
    }else{
        return 0;
    }
}

Wektor<3> Dron::srodek_drona(){
    return korpus.get_srodek();
}