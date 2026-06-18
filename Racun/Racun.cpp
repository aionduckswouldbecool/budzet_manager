#include "Racun.hpp"
#include "../random_number_generator/random_number.cpp"

Racun::Racun(double stanjeNaRacunu) {
    this->StanjeNaRacunu = stanjeNaRacunu;
    for (int i = 0; i < 18; i++) { 
        this->ZiroBrojRacuna = ZiroBrojRacuna * 10 + generisiNasumicanBroj(0, 9); // broj racuna se sa 
        if (this->ZiroBrojRacuna < 0) this->ZiroBrojRacuna = -this->ZiroBrojRacuna; // osiguravamo da je broj racuna pozitivan
    }

    
}

void Racun::prikaziStanje ( ) { 
    cout << "Stanje na racunu " << ZiroBrojRacuna << " je: " << StanjeNaRacunu << endl;
}

void Racun::dodajSredstva(double iznos) {
    if (iznos > 0) {
        StanjeNaRacunu += iznos;
        cout << "Dodat iznos: " << iznos << ". Novo stanje: " << StanjeNaRacunu << endl;
    } else {
        cout << "Iznos mora biti pozitivan!" << endl;
    }
}

void Racun::podigniSredstva (double iznos ) { 
    if (iznos > 0 && iznos <= StanjeNaRacunu) { 
        StanjeNaRacunu -= iznos;
        cout << "Podignut iznos: " << iznos << ". Novo stanje: " << StanjeNaRacunu << endl;
    } else if (iznos > StanjeNaRacunu) {
        cout << "Nedovoljno sredstava na racunu!" << endl; 
    } else {
        cout << "Iznos mora biti pozitivan!" << endl;
    }
}
