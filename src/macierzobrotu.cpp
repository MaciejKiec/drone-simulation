    #include "macierzobrotu.hh"
    template<int ROZMIAR> MacierzRot2D<ROZMIAR>::MacierzRot2D(double kat, std::string os){
        this->angle = kat;
        kat = kat/180*atan(1)*4;
        switch (ROZMIAR)
        {
        case 2:
        {
            Wektor<ROZMIAR> null2D;
            for(int i=0; i<2; i++) wiersze.push_back(null2D);
            wiersze[0][0] = cos(kat);
            wiersze[0][1] = -sin(kat);
            wiersze[1][0] = sin(kat);
            wiersze[1][1] = cos(kat);
            break;
        }
        case 3:
        {
            Wektor<ROZMIAR> null3D;
            for(int i=0; i<3; i++) wiersze.push_back(null3D);
                if(os=="X"){
                    wiersze[0][0] = 1;
                    wiersze[0][1] = 0;
                    wiersze[0][2] = 0;
                    wiersze[1][0] = 0;
                    wiersze[1][1] = cos(kat);
                    wiersze[1][2] = -sin(kat);
                    wiersze[2][0] = 0;
                    wiersze[2][1] = sin(kat);
                    wiersze[2][2] = cos(kat);
                }else if(os=="Y"){
                    wiersze[0][0] = cos(kat);
                    wiersze[0][1] = 0;
                    wiersze[0][2] = sin(kat);
                    wiersze[1][0] = 0;
                    wiersze[1][1] = 1;
                    wiersze[1][2] = 0;
                    wiersze[2][0] = -sin(kat);
                    wiersze[2][1] = 0;
                    wiersze[2][2] = cos(kat);
                }else if(os=="Z"){
                    wiersze[0][0] = cos(kat);
                    wiersze[0][1] = -sin(kat);
                    wiersze[0][2] = 0;
                    wiersze[1][0] = sin(kat);
                    wiersze[1][1] = cos(kat);
                    wiersze[1][2] = 0;
                    wiersze[2][0] = 0;
                    wiersze[2][1] = 0;
                    wiersze[2][2] = 1;
                }
                break;
        }
        default:
            std::cerr << "Macierz obrotu tego wymiaru nie jest zaimplementowana";
            break;
        }
    }
    template<int ROZMIAR> MacierzRot2D<ROZMIAR>::MacierzRot2D(){
        for(int i = 0; i < ROZMIAR; i++){
                Wektor<ROZMIAR> zero;
                wiersze.push_back(zero);
            }
        }
    template<int ROZMIAR> MacierzRot2D<ROZMIAR> MacierzRot2D<ROZMIAR>::operator * (const MacierzRot2D<ROZMIAR> & arg2){
        MacierzRot2D<ROZMIAR> wynik;
        for(int i = 0; i < ROZMIAR; i++){
            for(int j = 0; j < ROZMIAR; j++){
                double komorka = 0;
                for(int k = 0; k < ROZMIAR; k++){
                    komorka += wiersze[i][k] * arg2.wiersze[k][j];
                }
                (wynik[i])[j] = komorka;
            }
        }
        wynik.set_kat(angle+arg2.get_kat());
        return wynik;
    }
    template <int ROZMIAR> Wektor<ROZMIAR> MacierzRot2D<ROZMIAR>::operator * (const Wektor<ROZMIAR> & Punkt){
        Wektor<ROZMIAR> wynik;
        for(int i = 0; i < ROZMIAR; i++){
            wynik[i] = Punkt * wiersze[i];
        }
        return wynik;
    }

    template<int ROZMIAR> std::ostream& operator << (std::ostream& out, const MacierzRot2D<ROZMIAR> macierz){
        for(int i = 0; i < ROZMIAR; i++){
           std::cout << "| ";
            for(int j = 0; j < ROZMIAR; j++){
                std::cout << (macierz.get_wiersze(i))[j] << " ";
            }
            std::cout << "|" << std::endl;
        }
        return out;
    }
    template<int ROZMIAR> const Wektor<ROZMIAR> MacierzRot2D<ROZMIAR>::get_wiersze(int n) const{
        if(n<0 || n>ROZMIAR){
            std::cerr << "Odwołanie poza pamięć(Macierz)!" << std::endl;
        }
        return wiersze[n];
    }
    template<int ROZMIAR> Wektor<ROZMIAR> & MacierzRot2D<ROZMIAR>::operator [] (int n){
        if(n<0 || n>ROZMIAR){
            std::cerr << "Odwołanie poza pamięć(Macierz)!" << std::endl;
        }
        return wiersze[n];
    }

    template class MacierzRot2D<2>;
    template class MacierzRot2D<3>;
    template std::ostream& operator << (std::ostream& out, const MacierzRot2D<2> macierz);
    template std::ostream& operator << (std::ostream& out, const MacierzRot2D<3> macierz);