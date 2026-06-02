#ifndef TERMINAL_TERMINAL_HPP
#define TERMINAL_TERMINAL_HPP
#include <iostream>
#include <stdlib.h>
using namespace std;

class Terminal {
    // Terminal klasa gde se nalazi sve za terminal
private:
    int data;
    bool running; // Dodajemo bool da pratimo stanje terminala

    void meni(); // funkcija koja ispisuje meni
    void run(); // funkcija koja pokrece terminal i obraduje korisnicki unos

public:
    Terminal();
    ~Terminal();

    int getData() const; // getter data-e
    void setData(int value); // setter data-e

    void clearScreen();
};

#endif // TERMINAL_TERMINAL_HPP