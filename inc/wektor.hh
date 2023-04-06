#ifndef Wektor_HH
#define Wektor_HH


#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "OpenGL_API.hh"
#include "Draw3D_api_interface.hh"
template <int ROZMIAR>
class Wektor{
private:
    std::vector<double> xy;
    inline static int ile_stworzono = 0;
    inline static int ile_jest = 0;
public:
    Wektor operator + (const Wektor & arg2) const; //suma wektorów
    const Wektor  operator - (const Wektor & arg2) const; //różnica wektorów
    const Wektor  operator * (double arg2) const; //mnożenie przez stałą
    const Wektor  operator / (double arg2) const; //dzielenie przez stałą
    const double  operator * (const Wektor & arg2) const; //iloczyn skalarny
    Wektor(std::initializer_list<double> arg) : xy(arg) {ile_stworzono++;ile_jest++;};
    Wektor();
    //Wektor(const Wektor<ROZMIAR> & nowy) {};
    const double & operator [] (int ind) const; // 
    double & operator [] (int ind);
    double dlugosc_w_rzucie_OXY();
    static int get_stworzono() {return ile_stworzono;};
    static int get_jest() {return ile_jest;};
   ~Wektor(){ile_jest--;};


};
template <int ROZMIAR>
std::ostream& operator << (std::ostream& out, const Wektor<ROZMIAR> wektor);
template <int ROZMIAR>
drawNS::Point3D konwertuj(Wektor<ROZMIAR> arg);
Wektor<3> konwertuj(drawNS::Point3D arg);





#endif