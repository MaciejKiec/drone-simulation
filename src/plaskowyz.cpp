#include "plaskowyz.hh"
#include "random"


    void plaskowyz::generuj(){
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::uniform_int_distribution<int> distribution(3,9);
        std::uniform_real_distribution<> dis(3, 6.7);
        int ilosc_wierzcholkow = distribution(generator);
        double R = dis(generator);
        NajwiekszeR = R;
        Wektor<3> A = {R,0,wysokosc/2};
        MacierzRot2D<3> Mac(360/ilosc_wierzcholkow,"Z");
        wierzcholki.push_back(Mac*A);

        for (int i = 1; i<=ilosc_wierzcholkow; i++){
            double R = dis(generator);
            if (R > NajwiekszeR) NajwiekszeR = R;
            A = {R,0,wysokosc/2};
            Mac = {double(360/ilosc_wierzcholkow*i),"Z"};
            wierzcholki.push_back(Mac*A);
        }

    }


    void plaskowyz::rysuj(){
        std::vector<drawNS::Point3D> Gora;
        std::vector<drawNS::Point3D> Dol;
        Wektor<3> Shift = {0,0,-wysokosc};
        

        for (int i = 0; i<=wierzcholki.size()-1; i++){
            wierzcholki[i] = przelicz_punkt_do_rodzica(wierzcholki[i],orientacja);
        }

        for(int i = 0; i<=wierzcholki.size()-1; i++){
            Gora.push_back(konwertuj(wierzcholki[i]));
        } 
        
        for(int i = 0; i<=wierzcholki.size()-1; i++){
            Dol.push_back(konwertuj(wierzcholki[i]+Shift));
        }


        set_id(get_rysownik()->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {Gora, Dol},"blue"));  
    }

    void plaskowyz::zmaz(){
        get_rysownik()->erase_shape(get_id());
    }

    bool plaskowyz::czy_nad(std::shared_ptr<InterfejsDrona> AktualnyDron){
        Wektor<3> temp1 = srodek - AktualnyDron->srodek_drona();
        double Srodki = temp1.dlugosc_w_rzucie_OXY();
        if((Srodki) < 3+NajwiekszeR){
            return 1;
        }else{
        return 0;
        }
    }

    bool plaskowyz::czy_ladowac(std::shared_ptr<InterfejsDrona> AktualnyDron){
        if (czy_nad(AktualnyDron) == 0){
        return 1;
        }else{
        return 0;
        }
    }
