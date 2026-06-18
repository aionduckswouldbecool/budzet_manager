#ifndef TERMINAL_TERMINAL_HPP
#define TERMINAL_TERMINAL_HPP
#include <iostream>
#include <stdlib.h>
#include <string>
#include "../Racun/Racun.cpp" // Pretpostavljamo da postoji klasa Racun
using namespace std;

class Terminal {
    // Terminal klasa gde se nalazi sve za terminal
private:
    int data;
    bool running; // Dodajemo bool da pratimo stanje terminala

    void meni(); // funkcija koja ispisuje meni
    
    Racun * trenutniRacun; // pokazivac na trenutni racun, pretpostavljamo da postoji klasa Racun

public:
    Terminal();
    ~Terminal();

    int getData() const; // getter data-e
    void setData(int value); // setter data-e
    void run(); // funkcija koja pokrece terminal i obraduje korisnicki unos
    void clearScreen();
};

#endif // TERMINAL_TERMINAL_HPP