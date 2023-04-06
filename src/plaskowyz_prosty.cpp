#include "plaskowyz_prosty.hh"

void plaskowyz_prosty::rysuj(){
     Wektor<3> A,B,C,D,E,F,G,H;
    A= przelicz_punkt_do_rodzica({dlugosc/2,szerokosc/2,wysokosc/2},orientacja);
    B= przelicz_punkt_do_rodzica({dlugosc/2,-szerokosc/2,wysokosc/2},orientacja);
    C= przelicz_punkt_do_rodzica({-dlugosc/2,-szerokosc/2,wysokosc/2},orientacja);
    D= przelicz_punkt_do_rodzica({-dlugosc/2,szerokosc/2,wysokosc/2},orientacja);
    E= przelicz_punkt_do_rodzica({dlugosc/2,szerokosc/2,-wysokosc/2},orientacja);
    F= przelicz_punkt_do_rodzica({dlugosc/2,-szerokosc/2,-wysokosc/2},orientacja);
    G= przelicz_punkt_do_rodzica({-dlugosc/2,-szerokosc/2,-wysokosc/2},orientacja);
    H= przelicz_punkt_do_rodzica({-dlugosc/2,szerokosc/2,-wysokosc/2},orientacja);

    set_id(get_rysownik()->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {{konwertuj(A) , konwertuj(B), konwertuj(C), konwertuj(D)},{konwertuj(E), konwertuj(F), konwertuj(G), konwertuj(H)}},"red"));

}

void plaskowyz_prosty::zmaz(){
    get_rysownik()->erase_shape(get_id());
}

bool plaskowyz_prosty::czy_nad(std::shared_ptr<InterfejsDrona> AktualnyDron){
    return 1;
}

bool plaskowyz_prosty::czy_ladowac(std::shared_ptr<InterfejsDrona> AktualnyDron){
    return 1;
}
