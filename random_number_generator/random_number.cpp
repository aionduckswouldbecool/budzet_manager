#include <iostream>
#include <random> // Neophodno za generisanje nasumičnih brojeva

// Funkcija koja vraća nasumičan ceo broj u opsegu od 'min' do 'max' (uključujući oba)
int generisiNasumicanBroj(int min, int max) {
    // 'static' obezbeđuje da se generator inicijalizuje samo jednom, a ne pri svakom pozivu funkcije
    static std::random_device rd;  
    static std::mt19937 gen(rd()); 
    
    // Definišemo ravnomernu raspodelu za cele brojeve u zadatom opsegu
    std::uniform_int_distribution<int> dist(min, max);
    
    return dist(gen);
}

