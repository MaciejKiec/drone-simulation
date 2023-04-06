#ifndef Prostopadloscian_HH
#define Prostopadloscian_HH



#include "wektor.hh"
#include "macierzobrotu.hh"
#include "OpenGL_API.hh"
#include "Draw3D_api_interface.hh"
#include "ukladw.hh"

class Prostopadloscian : public UkladW{
    int id_figury;
    double dlugosc;
    double szerokosc;
    double wysokosc;
    Wektor <3> MiddlePoint = {0,0,0};
    std::vector<Wektor<3>> SrodekRotora {Wektor<3>{0,0,0},Wektor<3>{0,0,0},Wektor<3>{0,0,0},Wektor<3>{0,0,0}};
public:
    Prostopadloscian(double _dlugosc, double _szerokosc, double _wysokosc, Wektor<3> _srodek, MacierzRot2D<3> _orientacja, UkladW * rodzic) : UkladW(_srodek, _orientacja, rodzic), dlugosc(_dlugosc), szerokosc(_szerokosc), wysokosc(_wysokosc) {};
    void rysuj(drawNS::Draw3DAPI * rysownik);
    int get_idFigury(){
    return id_figury;
    }
    Wektor<3> get_MiddlePoint(){
        return MiddlePoint;
    }
    std::vector<Wektor<3>> get_SrodekRotora(){
        return SrodekRotora;
    }
};

#endif