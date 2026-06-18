#ifndef TRANSAKCIJA_TRANSAKCIJA_HPP
#define TRANSAKCIJA_TRANSAKCIJA_HPP
#include "../Racun/Racun.cpp"

class Transakcija { 

    private: 
        int suma; 
        Racun * racun; 
        Transakcija * prevTransakcija = nullptr; // pokazivac na prethodnu transakciju u dvostruko ulancanoj listi
        Transakcija * nextTransakcija = nullptr; // pokazivac na sledecu transakciju u dvostruko ulancanoj listi
    
        public:
            Transakcija (Racun * racun, int suma); // konstruktor u sebi ima pokazivac an racun i sumu koja se oduzima sa racuna 
            int getSuma() const { return suma; } // getter za sumu transakcije
            Transakcija * getPrevTransakcija() const { return prevTransakcija; } // getter za prethodnu transakciju
            Transakcija * getNextTransakcija() const { return nextTransakcija; }
    // Transkacije se cuvaju kao dvosturko ulancana lista gde mozemo imati uvid u 
    // sve transakcije koje su se desle i da bi se mglo hronoloski ici kroz njih
    // da bi imali uvid u nase troskove kroz vreme 

    
    
    
};

#endif