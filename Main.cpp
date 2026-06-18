#include "Terminal/Terminal.cpp"

int main ( ) {
    Terminal terminal;
    terminal.run(); // Pokrećemo terminal nakon kreiranja objekta
    terminal.clearScreen(); // Čistimo ekran nakon pokretanja terminala
    return 0;
}