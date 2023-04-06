#include "graniastoslup6.hh"

void Graniastoslup6::rysuj(drawNS::Draw3DAPI * rysownik){
    std::vector<drawNS::Point3D> G;
    std::vector<drawNS::Point3D> Dol;
    Wektor<3> A;
    Wektor<3> Shift{0,0,-wysokosc};
    MacierzRot2D<3> M(60,"Z");
    A = {DuzeR,0,wysokosc/2};

    G.push_back(konwertuj(A));
    for (int i = 1; i<= 6; i++){
        A = M * A;
        G.push_back(konwertuj(A));

    }

    for(int i = 0; i<=6; i++){
        drawNS::Point3D temp = G[i];
        Wektor<3>temp1 = konwertuj(temp);
        G[i] = konwertuj(przelicz_punkt_do_rodzica(temp1,orientacja));
    }

    for (int i = 0; i<= 6; i++){
        drawNS::Point3D temp = G[i];
        Wektor<3>temp1 = konwertuj(temp);
        Dol.push_back(konwertuj(temp1+Shift));

    }
    
    //std::cout << "Współrzędne środka: " << srodek << std::endl;
    
    this->id_figury = rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {G, Dol},"blue");

}