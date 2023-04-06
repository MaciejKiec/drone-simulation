#ifndef INTER_EL_POWIERZCHNI_HH
#define INTER_EL_POWIERZCHNI_HH
#include <memory>
#include "wektor.hh"



class InterfejsDrona;

class InteraktywnyElementPowierzchni {
private:
    int id_bryly = 0;
    inline static int ilosc_bryl = 0;
    inline static int ilosc_dronow = 0;

public:
    InteraktywnyElementPowierzchni() {ilosc_bryl++; id_bryly = ilosc_bryl;};
    virtual int ID() = 0;
    virtual bool czy_nad(std::shared_ptr<InterfejsDrona> AktualnyDron) = 0;
    virtual bool czy_ladowac(std::shared_ptr<InterfejsDrona> AktualnyDron) = 0;
    int get_id_bryly() {return id_bryly;};
    virtual Wektor<3> get_srodek() = 0;
};

#endif