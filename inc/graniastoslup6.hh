#ifndef Graniastoslup6_HH
#define Graniastoslup6_HH




#include "wektor.hh"
#include "macierzobrotu.hh"
#include "OpenGL_API.hh"
#include "Draw3D_api_interface.hh"
#include "ukladw.hh"

class Graniastoslup6 : public UkladW {
    int id_figury;
    double DuzeR;
    double wysokosc;
public:
    Graniastoslup6(double _DuzeR, double _wysokosc, Wektor<3> _srodek, MacierzRot2D<3> _orientacja, UkladW * rodzic) : UkladW(_srodek, _orientacja, rodzic), DuzeR(_DuzeR), wysokosc(_wysokosc) {};
    void rysuj(drawNS::Draw3DAPI * rysownik);
    int get_id_wirnika(){
    return id_figury;
    }
};

#endif