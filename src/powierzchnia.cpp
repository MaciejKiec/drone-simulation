#include "Draw3D_api_interface.hh"
#include "powierzchnia.hh"

void Powierzchnia::rysuj(drawNS::Draw3DAPI * rysownik, int WymSceny){
    for(int i = -WymSceny; i<=WymSceny; i++){
        rysownik->draw_line(drawNS::Point3D(i,-WymSceny,wysokosc),drawNS::Point3D(i,WymSceny,wysokosc),"green");
    }
    for(int j = -WymSceny; j<=WymSceny; j++){
    rysownik->draw_line(drawNS::Point3D(-WymSceny,j,wysokosc),drawNS::Point3D(WymSceny,j,wysokosc),"green");
    }
    
}