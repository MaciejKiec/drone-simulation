#ifndef powierzchnia_HH
#define powierzchnia_HH


#include "OpenGL_API.hh"
#include "Draw3D_api_interface.hh"
class Powierzchnia {
private:
    double wysokosc;
public:
    Powierzchnia(double _wysokosc) : wysokosc(_wysokosc){};
    void rysuj(drawNS::Draw3DAPI * rysownik, int WymSceny);
};



#endif