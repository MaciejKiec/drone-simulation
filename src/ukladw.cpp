#include "ukladw.hh"

Wektor<3> UkladW::przelicz_punkt_do_rodzica(Wektor<3> W, MacierzRot2D<3> M){
    Wektor<3> wynik;
   return wynik = M* W + srodek;
}

void UkladW::przelicz_uklad_do(UkladW UW){
    srodek = UW.orientacja * srodek + UW.srodek;
    orientacja = UW.orientacja * orientacja;
}

