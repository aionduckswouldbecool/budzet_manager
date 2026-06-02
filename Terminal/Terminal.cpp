#include "Terminal.hpp"

Terminal::Terminal () : data(0), running(false) {
    cout << "Napravljen terminal sa podatkom: " << data << endl;
    Terminal::run(); // Pokrećemo terminal odmah nakon kreiranja objekta
    Terminal::clearScreen(); // Čistimo ekran nakon pokretanja terminala
    
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
    cout << "1. Opcija 1" << endl;
    cout << "2. Opcija 2" << endl;
    cout << "3. Opcija 3" << endl;
    cout << "0. Izlaz" << endl;
}

void Terminal::run() {
    int choice;
    running = true;
    while (running){
        meni();
        cout << "/n$ ";
        cin >> choice;
        if (choice == 0) {
            running = false;
        }
    }

}
