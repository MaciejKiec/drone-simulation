#ifndef MACIERZOBROTU_HH
#define MACIERZOBROTU_HH
#include "wektor.hh"
template<int ROZMIAR>
class MacierzRot2D{
private:
    std::vector<Wektor<ROZMIAR>> wiersze;
    double angle;
public:
MacierzRot2D(double kat, std::string os);
MacierzRot2D();
MacierzRot2D operator * (const MacierzRot2D & arg2);
Wektor<ROZMIAR> operator * (const Wektor<ROZMIAR> & Punkt);
const Wektor<ROZMIAR> get_wiersze(int n) const;
Wektor<ROZMIAR> & operator [] (int n);
double get_kat() const {return angle;}
void set_kat(double kat) {angle=kat;}
};

template<int ROZMIAR> std::ostream& operator << (std::ostream& out, const MacierzRot2D<ROZMIAR> macierz);
#endif