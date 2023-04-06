#include "wektor.hh"

 template<int ROZMIAR>

    Wektor<ROZMIAR>::Wektor(){
        for(int i = 0; i<ROZMIAR;i++){
            xy.push_back(0.0);
        }
       ile_jest++;
       ile_stworzono++;
    
    } 

template<int ROZMIAR>
   
   const double & Wektor<ROZMIAR>::operator [] (int ind) const{
        if(ind < 0 || ind > ROZMIAR){
            std::cerr << "Odwolanie poza pamiec!" << std::endl;
        }
        return xy[ind];
   } 

template<int ROZMIAR>
   double & Wektor<ROZMIAR>::operator [] (int ind){
        if(ind < 0 || ind > ROZMIAR){
            std::cerr << "Odwolanie poza pamiec!" << std::endl;
        }
        return xy[ind];
}
template<int ROZMIAR>
    Wektor<ROZMIAR> Wektor<ROZMIAR>::operator + (const Wektor & arg2) const{
        Wektor<ROZMIAR> wynik;
        for(int i=0;i<ROZMIAR;i++){
            wynik[i] = xy[i] + arg2[i];
        }
        return wynik;
 }
 template<int ROZMIAR>
    const Wektor<ROZMIAR> Wektor<ROZMIAR>::operator - (const Wektor & arg2) const{
        Wektor wynik;
       for(int i=0;i<ROZMIAR;i++){
            wynik[i] = xy[i] - arg2[i];
        }
        return wynik;
 }
 template<int ROZMIAR>
    const Wektor<ROZMIAR> Wektor<ROZMIAR>::operator * (double arg2) const{
        Wektor wynik;
       for(int i=0;i<ROZMIAR;i++){
            wynik[i] = xy[i] * arg2;
        }
        return wynik;
 }
 template<int ROZMIAR>
    const Wektor<ROZMIAR> Wektor<ROZMIAR>::operator / (double arg2) const{
        Wektor wynik;
       for(int i=0;i<ROZMIAR;i++){
            wynik[i] = xy[i] / arg2;
        }
        return wynik;
 }
 template<int ROZMIAR>
    const double Wektor<ROZMIAR>::operator * (const Wektor & arg2) const{
        double wynik;
       for(int i=0;i<ROZMIAR;i++){
            wynik += xy[i]*arg2[i];
        }
        return wynik;
 }

template<int ROZMIAR>
std::ostream& operator << (std::ostream& out, const Wektor<ROZMIAR> wektor){
    std::cout << "(" << std::fixed << std::setprecision(5) << wektor[0];
    for(int i = 1; i<ROZMIAR; i++){
        std::cout << ":" << wektor[i];
    }
    std::cout << ")";
    return out;
} 

template<int ROZMIAR>
drawNS::Point3D konwertuj(Wektor<ROZMIAR> arg){
    return drawNS::Point3D(arg[0],arg[1],arg[2]);
}

Wektor<3> konwertuj(drawNS::Point3D arg){
    return Wektor<3>{arg[0],arg[1],arg[2]};
}
template<int ROZMIAR>
double Wektor<ROZMIAR>::dlugosc_w_rzucie_OXY(){
    return sqrt(xy[0]*xy[0]+xy[1]*xy[1]);
    
}


template class Wektor<2>;
template class Wektor<3>;
template class Wektor<6>;
template drawNS::Point3D konwertuj(Wektor<3> arg);
template std::ostream& operator << (std::ostream& out, const Wektor<2> wektor);
template std::ostream& operator << (std::ostream& out, const Wektor<3> wektor);
template std::ostream& operator << (std::ostream& out, const Wektor<6> wektor);
