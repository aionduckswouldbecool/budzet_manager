#ifndef RACUN_RACUN_HPP
#define RACUN_RACUN_HPP
#include <iostream>
using namespace std;

class Racun {

    private: 
        int ZiroBrojRacuna = 0; 
        double DinariNaRacunu; // stavljanje Dinara na Racun 
        double EvriNaRacunu; // prikazuje Evre na racunu 
        double DolariNaRacunu; // prikazuje Dolari na racunu
        double StanjeNaRacunu; // Ovo je ukupno stanje na računu, koje se računa kao suma svih valuta, 
                               // konvertovanih u dinare posto smo SRBI
        Racun* trenutniRacun; // pokazivač na trenutni račun, može biti koristan za funkciju prenosa sredstava

    protected: 
        // Za sada nemamo zaštićene članove, ali ih možemo dodati kasnije ako bude potrebno

    public:
        Racun(double stanjeNaRacunu);
        void prikaziStanje();
        void dodajSredstva(double iznos);
        void podigniSredstva(double iznos);
        void prenosSredstava(Racun& drugiRacun, double iznos);
        // Getteri i setteri
        int getZiroBrojRacuna() const { return ZiroBrojRacuna; }  // const oznavav da je ova funkcija
                                                                  // radi samo ovo i da ne moze da se predefinise 
        double getStanjeNaRacunu() const { return StanjeNaRacunu; }
    
};



#endif // RACUN_RACUN_HPP