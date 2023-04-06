#include "prostopadloscian.hh"

void Prostopadloscian::rysuj(drawNS::Draw3DAPI * rysownik){
    Wektor<3> A,B,C,D,E,F,G,H;
    A= przelicz_punkt_do_rodzica({dlugosc/2,szerokosc/2,wysokosc/2},orientacja);
    B= przelicz_punkt_do_rodzica({dlugosc/2,-szerokosc/2,wysokosc/2},orientacja);
    C= przelicz_punkt_do_rodzica({-dlugosc/2,-szerokosc/2,wysokosc/2},orientacja);
    D= przelicz_punkt_do_rodzica({-dlugosc/2,szerokosc/2,wysokosc/2},orientacja);
    E= przelicz_punkt_do_rodzica({dlugosc/2,szerokosc/2,-wysokosc/2},orientacja);
    F= przelicz_punkt_do_rodzica({dlugosc/2,-szerokosc/2,-wysokosc/2},orientacja);
    G= przelicz_punkt_do_rodzica({-dlugosc/2,-szerokosc/2,-wysokosc/2},orientacja);
    H= przelicz_punkt_do_rodzica({-dlugosc/2,szerokosc/2,-wysokosc/2},orientacja);
    
    MiddlePoint = (A+B) / 2;

    //std::cout << "Orientacja w prostopadłościanie: "<< std::endl << get_orientacja();
    
    SrodekRotora[0] = A;
    SrodekRotora[1] = B;
    SrodekRotora[2] = C;
    SrodekRotora[3] = D;


    this->id_figury = rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {{konwertuj(A) , konwertuj(B), konwertuj(C), konwertuj(D)},{konwertuj(E), konwertuj(F), konwertuj(G), konwertuj(H)}},"red");
   
   // std::cout << "Środek prostopadloscianu: " << srodek << std::endl;
}