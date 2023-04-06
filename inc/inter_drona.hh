#ifndef INTER_DRONA_HH
#define INTER_DRONA_HH


#include "inter_el_powierzchni.hh"
#include "inter_rysowania.hh"
#include "OpenGL_API.hh"
#include "Draw3D_api_interface.hh"
#include "wektor.hh"

class Scena;

class InterfejsDrona: public InteraktywnyElementPowierzchni, public InterfejsRysowania{
    public:
    InterfejsDrona(drawNS::Draw3DAPI * rysownik)  : InteraktywnyElementPowierzchni(), InterfejsRysowania(rysownik) {};
    //virtual ~InterfejsDrona() {};
    virtual void lec_do_przodu(double odl) = 0;
    virtual void lec_do_gory(double wys) = 0;
    virtual void lec_w_bok(double odl) = 0;
    virtual void obroc(double kat) = 0;
    virtual void porusz_wirnikami() = 0;
    virtual void Przelot(Wektor<3> PunktKoncowy, double wysokosc_przelotu, Scena * scena) = 0;
    virtual Wektor<3> srodek_drona() = 0;
    virtual void zeruj() = 0;
};

#endif