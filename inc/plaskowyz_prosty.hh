#ifndef PLASKOWYZ_PROSTY_HH
#define PLASKOWYZ_PROSTY_HH

#include "inter_drona.hh"
#include "inter_rysowania.hh"
#include "inter_el_powierzchni.hh"
#include "ukladw.hh"
#include "OpenGL_API.hh"
#include "Draw3D_api_interface.hh"
#include "wektor.hh"
#include "macierzobrotu.hh"
#include "dron.hh"
#include "prostopadloscian.hh"



class plaskowyz_prosty : public Prostopadloscian, public InterfejsRysowania, public InteraktywnyElementPowierzchni {
private:
    double dlugosc,szerokosc,wysokosc;

public:
    plaskowyz_prosty(double _dlugosc, double _szerokosc, double _wysokosc, drawNS::Draw3DAPI * _rysownik) : Prostopadloscian(_dlugosc, _szerokosc, _wysokosc, Wektor<3> {0,0,0}, MacierzRot2D<3> {0,"Z"}, nullptr), InterfejsRysowania(_rysownik), dlugosc(_dlugosc), szerokosc(_szerokosc), wysokosc(_wysokosc) {rysuj();};
    ~plaskowyz_prosty(){zmaz();};
    void rysuj() override;
    void zmaz() override;
    bool czy_nad(std::shared_ptr<InterfejsDrona> AktualnyDron) override;
    bool czy_ladowac(std::shared_ptr<InterfejsDrona> AktualnyDron) override;
    Wektor<3> get_srodek() override {return srodek;};
    int ID() override {return 2;};
};

#endif