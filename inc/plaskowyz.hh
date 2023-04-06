#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH

#include "inter_drona.hh"
#include "inter_rysowania.hh"
#include "inter_el_powierzchni.hh"
#include "ukladw.hh"
#include "OpenGL_API.hh"
#include "Draw3D_api_interface.hh"
#include "wektor.hh"
#include "macierzobrotu.hh"
#include "dron.hh"


class plaskowyz : public InterfejsRysowania, public InteraktywnyElementPowierzchni, public UkladW {
private:
    std::vector<Wektor<3>> wierzcholki;
    double wysokosc;
    double NajwiekszeR;
    int id;
public:
    plaskowyz(double _wysokosc, drawNS::Draw3DAPI * _rysownik) : InterfejsRysowania (_rysownik), UkladW(Wektor<3> {0,0,0}, MacierzRot2D<3> (0,"X"), nullptr), wysokosc(_wysokosc) {generuj();rysuj();};
    ~plaskowyz(){zmaz();};
    void generuj();
    void rysuj() override;
    void zmaz() override;
    bool czy_nad(std::shared_ptr<InterfejsDrona> AktualnyDron) override;
    bool czy_ladowac(std::shared_ptr<InterfejsDrona> AktualnyDron) override;
    int ID() override {return 1;};
    Wektor<3> get_srodek() override {return srodek;};
};

#endif