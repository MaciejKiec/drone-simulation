#ifndef INTER_RYSOWANIA_HH
#define INTER_RYSOWANIA_HH

#include "OpenGL_API.hh"
#include "Draw3D_api_interface.hh"


class InterfejsRysowania {
private:
    drawNS::Draw3DAPI * rysownik;
    int id;
public:
    InterfejsRysowania(drawNS::Draw3DAPI * _rysownik) : rysownik(_rysownik) {};
    virtual void rysuj() = 0;
    virtual void zmaz() = 0;
    int get_id() {return id;};
    void set_id(int _id) {id=_id;};
    drawNS::Draw3DAPI * get_rysownik() {return rysownik;};
};

#endif