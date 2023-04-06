#ifndef UkladW_HH
#define UkladW_HH




#include "wektor.hh"
#include "macierzobrotu.hh"

class UkladW {
protected:
    UkladW * wskaznik_na_poprzedni;
    Wektor<3> srodek;
    MacierzRot2D<3> orientacja;
public:
    UkladW(Wektor<3> _srodek, MacierzRot2D<3> _orientacja, UkladW *rodzic) : wskaznik_na_poprzedni(rodzic), srodek(_srodek), orientacja(_orientacja) {}
    void Translacja(Wektor<3> nowy){
    srodek = srodek + nowy;
    }
    void Rotacja(MacierzRot2D<3> nowa){
        orientacja = nowa;
    }
    UkladW przelicz_uklad_do_dziadka();
    void przelicz_uklad_do(UkladW UW);
    Wektor<3> przelicz_punkt_do_rodzica(Wektor<3> W, MacierzRot2D<3> M);
    void set_orientacja(MacierzRot2D<3> M){
        orientacja = orientacja * M;
    }
    MacierzRot2D<3> get_orientacja(){
        return orientacja;
    }
    Wektor<3> get_srodek(){
        return srodek;
    }
    void set_srodek(Wektor<3> W){
        srodek = W;
    }
};


#endif