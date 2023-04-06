#ifndef SCENA_HH
#define SCENA_HH

#include "inter_rysowania.hh"
#include "inter_el_powierzchni.hh"
#include "ukladw.hh"
#include "OpenGL_API.hh"
#include "Draw3D_api_interface.hh"
#include "wektor.hh"
#include "macierzobrotu.hh"
#include "dron.hh"
#include "plaskowyz.hh"
#include "plaskowyz_prosty.hh"
#include "wzgorze.hh"


class Scena {
private:
    std::shared_ptr<InterfejsDrona> AktualnyDron;
    std::vector<std::shared_ptr<Dron>> Drony;
    std::vector<std::shared_ptr<InteraktywnyElementPowierzchni>> Przeszkody;
    //std::vector<InterfejsRysowania> ElementyDoRysowania; /* DO ZASTANOWIENIA*/
public:
    bool animuj(Wektor<3> PunktKoncowy, double wysokosc_przelotu,Scena * scena);
    void rysuj_wszystkie(drawNS::Draw3DAPI * api);
    void dodaj_drona(drawNS::Draw3DAPI * api);
    void dodaj_element_krajobrazu(std::shared_ptr<InteraktywnyElementPowierzchni> Przeszkoda);
    bool usun_drona(int id);
    bool usun_element_krajobrazu(int id);
    void pokaz_id_dronow();
    void pokaz_id_el_krajobrazu();
    bool wybierz_drona(int id);
    std::vector<std::shared_ptr<InteraktywnyElementPowierzchni>> get_przeszkody() {return Przeszkody;};
};


#endif