#include "wzgorze.hh"



void Wzgorze::generuj(){
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<> dis(3, 5.5);
    double R = dis(generator);
    MacierzRot2D<3> Mac (90,"Z");
    Wektor<3> A = {R,0,0};
    Wierzcholki.push_back(A);

        for(int i = 1; i<4; i++){
            A = Mac * A;
            Wierzcholki.push_back(A);
        }

}


void Wzgorze::rysuj(){

        std::vector<drawNS::Point3D> Podstawa, WierzcholekGorny;
        Wektor<3> H = {0,0,wysokosc};
        //H = H + srodek;

        for(int i = 0; i<4; i++){
            Podstawa.push_back(konwertuj(przelicz_punkt_do_rodzica(Wierzcholki[i],orientacja)));  
            std::cout << i << ". " << przelicz_punkt_do_rodzica(Wierzcholki[i],orientacja) << std::endl;
        }

        for(int i = 0; i<4; i++){
            WierzcholekGorny.push_back(konwertuj(przelicz_punkt_do_rodzica(H,orientacja)));
            //std::cout << przelicz_punkt_do_rodzica((srodek + Wektor<3> {0,0,wysokosc}),orientacja) << std::endl;
        }

        set_id(get_rysownik()->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>>{Podstawa,WierzcholekGorny},"black"));





}

void Wzgorze::zmaz(){
    get_rysownik()->erase_shape(get_id());
}

bool Wzgorze::czy_nad(std::shared_ptr<InterfejsDrona> AktualnyDron){
    Wektor<3> temp = Wierzcholki[0] - srodek;
    Wektor<3> temp1 = srodek - AktualnyDron->srodek_drona();
    double R = temp.dlugosc_w_rzucie_OXY();
    double Srodki = temp1.dlugosc_w_rzucie_OXY();
    if((Srodki) < R +3){
        return 1;
    }else{
    return 0;
    }
}

bool Wzgorze::czy_ladowac(std::shared_ptr<InterfejsDrona> AktualnyDron){
    if (czy_nad(AktualnyDron) == 0){
        return 1;
    }else{
        return 0;
    }

}