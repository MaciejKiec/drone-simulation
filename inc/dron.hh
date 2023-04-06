#ifndef dron_HH
#define dron_HH



#include "wektor.hh"
#include "macierzobrotu.hh"
#include "OpenGL_API.hh"
#include "Draw3D_api_interface.hh"
#include "prostopadloscian.hh"
#include "graniastoslup6.hh"
#include "inter_drona.hh"

//class InterfejsDrona;

class Dron : public UkladW, public InterfejsDrona{
Prostopadloscian korpus;
std::array<Graniastoslup6, 4> wirniki;
public:
    Dron(Wektor<3> _srodek, MacierzRot2D<3> _orientacja, drawNS::Draw3DAPI * rysownik) :
     UkladW(_srodek, _orientacja, nullptr),
     korpus(4.0, 2.0, 2.0,Wektor<3> {0,0,0},MacierzRot2D<3> (0,"X"), this),
     wirniki{Graniastoslup6(1, 0.1, Wektor<3>{-2,1,1}, MacierzRot2D<3> (0,"X"), this), Graniastoslup6(1, 0.1, Wektor<3>{-2,-1,1}, MacierzRot2D<3> (0,"X"), this),
     Graniastoslup6(1, 0.1, Wektor<3>{2,-1,1}, MacierzRot2D<3> (0,"X"), this), Graniastoslup6(1, 0.1, Wektor<3> {2,1,1}, MacierzRot2D<3> (0,"X"), this)}, InterfejsDrona(rysownik) {};
    void przelicz(UkladW W);
    void lec_do_gory(double wys) override;
    void lec_do_przodu(double odl) override; //za oś, po której dron będzie się poruszał wybrałem oś OX
    void lec_w_bok(double odl) override;
    void obroc(double kat) override;
    void porusz_wirnikami() override;
    void rysuj() override;
    void zmaz() override;
    bool czy_nad(std::shared_ptr<InterfejsDrona> AktualnyDron) override;
    bool czy_ladowac(std::shared_ptr<InterfejsDrona> AktualnyDron) override;
    void zeruj() override;
    void Przelot(Wektor<3> PunktKoncowy, double wysokosc_przelotu, Scena * scena) override;
    int ID() override {return 4;};
    Wektor<3> srodek_drona() override;
    Wektor<3> get_srodek() override {return srodek;};

};


#endif