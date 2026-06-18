#include "Terminal.hpp"
#include <string.h>
Terminal::Terminal () : data(0), running(false), trenutniRacun(nullptr) {
    cout << "Napravljen terminal sa podatkom: " << data << endl;
    
    
}
// konstruktor terminala

Terminal::~Terminal() {
    cout << "Terminal se gasi.. " << endl; 
}
// destruktor terminala

int Terminal::getData() const { 
    return data; 
 }

void Terminal::setData(int value) {
    data = value; 
}

void Terminal::clearScreen() {
    // Primer: isprazni terminal izlazom niza kontrolnih karaktera
    // Ovo radi na većini ANSI terminala.
    std::cout << "\x1B[2J\x1B[H" << std::endl;
}

void Terminal::meni() {
    cout << "Dobrodosli u meni terminala!" << endl;
    cout << "1. Opcija: Napravi racun" << endl;
    cout << "2. Opcija: Pogledaj stanje racuna" << endl;
    cout << "3. Opcija: Dodaj sredstva na racun" << endl;
    cout << "0. Izlaz" << endl;

}

void Terminal::run() {
    int choice;
    running = true;
    while (running){
        meni();
        cout << "\n$ ";
        cin >> choice;
        if (choice == 0) {
            running = false;
        }
        else if (choice == 1){
            // izabrao je da napravi racun, ovde bi trebalo da pozovem funkciju koja pravi racun, ali za sada samo ispisujem poruku
            cout << "Izabrali ste opciju 1: Napravi racun" << endl;
            double pocetnoStanje;
            string odgovor; 
            cout << "Hocete da prenesete pocetna sredstva na racun? (da/ne): ";
            cin >> odgovor; 
            while (odgovor != "da" && odgovor != "ne") {
                cout << "Neispravan unos. Molimo unesite 'da' ili 'ne': ";
                cin >> odgovor;
            }
            if (odgovor == "da") {
                cout << "Unesite koliko novca bi ste prebacili na racun: ";
                cin >> pocetnoStanje;
                cout << "Preneseno " << pocetnoStanje << " na racun." << endl;
            } 
            else {
                cout << "Niste preneli pocetna sredstva na racun." << endl;
                pocetnoStanje = 0.0; // Postavljamo pocetno stanje na 0 ako korisnik ne želi da prenese sredstva
            }
            trenutniRacun = new Racun(pocetnoStanje); // Kreiramo novi racun sa unetim pocetnim stanjem
        }
        else if ( choice == 2 ) { 
            if (trenutniRacun == nullptr) {
                cout << "Nema aktivnog racuna. Molimo prvo napravite racun." << endl;
                continue; // Preskačemo ostatak petlje i vraćamo se na meni
            }   
            cout << "Izabrali ste opciju 2: Pogledaj stanje racuna" << endl;
            // ovde bi trebalo da pozovemo funkciju koja prikazuje stanje racuna, ali za sada smo ispisujemo poruku
            cout << "Stanje na trenutnom racunu (" << trenutniRacun->getZiroBrojRacuna() << "): " << endl;
            trenutniRacun->prikaziStanje();
        }
        else if (choice == 3) { 
            if (trenutniRacun == nullptr) {
                cout << "Nema aktivnog racuna. Molimo prvo napravite racun." << endl;
                continue; // Preskačemo ostatak petlje i vraćamo se na meni
            }
            cout << "Izabrali ste opciju 3: dodaj sredstva na racun" << endl;
            double iznos;
            cout << "Unesite iznos koji zelite da dodate na racun: ";
            cin >> iznos;
            trenutniRacun->dodajSredstva(iznos);
        }
        string dalje;
        cout << "Zelite li da nastavite? (da/ne): ";
        cin >> dalje;
        if (!dalje.empty() || dalje == "\n" || dalje == " ") {
            this->clearScreen(); // Čistimo ekran nakon obrade korisničkog unosa
        } else{
            running = false; // Ako korisnik ne želi da nastavi, izlazimo iz petlje
        }
    }

}
