#ifndef WZGORZE_HH
#define WZGORZE_HH

#include "inter_drona.hh"
#include "inter_rysowania.hh"
#include "inter_el_powierzchni.hh"
#include "ukladw.hh"
#include "OpenGL_API.hh"
#include "Draw3D_api_interface.hh"
#include "wektor.hh"
#include "macierzobrotu.hh"
#include <random>



class Wzgorze : public UkladW, public InterfejsRysowania, public InteraktywnyElementPowierzchni {
private:
    std::vector<Wektor<3>> Wierzcholki;
    double wysokosc;
public:
    Wzgorze(double _wysokosc, drawNS::Draw3DAPI * _rysownik) : UkladW(Wektor<3> {0,0,0}, MacierzRot2D<3> (0,"Z"), nullptr), InterfejsRysowania(_rysownik), wysokosc(_wysokosc) {generuj();rysuj();};
    ~Wzgorze(){zmaz();};
    void generuj();
    void rysuj() override;
    void zmaz() override;
    bool czy_nad(std::shared_ptr<InterfejsDrona> AktualnyDron) override;
    bool czy_ladowac(std::shared_ptr<InterfejsDrona> AktualnyDron);
    Wektor<3> get_srodek() override {return srodek;};
    int ID() override {return 3;};
};


#endif