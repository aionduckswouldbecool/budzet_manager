# ifndef TRANSACIJA_VIEWER_HPP
# define TRANSACIJA_VIEWER_HPP
# include "Transakcija.hpp"
using namespace std;

// Transakcija_Viewer je klasa koja omogucava pregled transakcija, tj. da se vidi koje transakcije 
// su se desile kroz vreme kao i njihovo hronolosko listanje kroz vreme

class Transakcija_Viewer {
    private: 

        Transakcija * head; // pokazivac na transakciju koju gledamo tj na head 
        Transakcija * tail; // pokazivac na transakciju koja je poslednja u listi tj. tail
        Transakcija * curr; // pokazivac na trenutnu transakciju koju gledamo
        Transakcija_Viewer ( const Transakcija_Viewer& ) = delete; // brisemo copy konstruktor da bi imali samo jednu instancu?!
        Transakcija_Viewer ( Transakcija *t ) { 
            head = t; 
            tail = t;
            curr = t; 

        } // konstruktor koji inicijalizuje pokazivac na transakciju na nullptr

    public: 

        // pravimo singleton instancu Transakcija_Viewer klase da bi postaja samo jedan objekat koj
        // i ce biti odgovoran za pregled transakcija

        static Transakcija_Viewer& getInstance ( Transakcija *t ) { 
            static Transakcija_Viewer instance (t);
            return instance;
        }

        // funkcije za iteriranje kroz transakcije 

        Transakcija * prvaTransakcija() const { return head; } // getter za prvuTransakciju
        Transakcija * poslednjaTransakcija() const { return tail;} // getter za poslednjuTransakciju
        Transakcija * sledecaTransakcija(Transakcija *t) const { return curr->getNextTransakcija(); } // getter za sledecuTransakciju
        Transakcija * prethodnaTransakcija(Transakcija *t) const { return curr->getPrevTransakcija(); } // getter za prethodnuTransakciju
        Transakcija * dodajTransakciju(Racun *racun, int suma); // metoda za dodavanje transakcije  
        Transakcija * obrisiTransakciju(Transakcija *t);  // metoda za brisanje transakcije 
        void * prikaziTransakicju() const { cout << curr->getSuma() << endl; }; // metoda za prikaz curr transakcije
};


#endif // TRANSACIJA_VIEWER_HPP