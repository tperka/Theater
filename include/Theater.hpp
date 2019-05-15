/**
 * Autor: Tymoteusz Perka
 * Nr indeksu: 300243
 * Prowadzący: mgr Wiktor Kuśmirek
 * Projekt: 9. Symulacja teatru
**/

#ifndef THEATER_THEATHER_HPP
#define THEATER_THEATHER_HPP


#include "Performance.hpp"
#include <functional>

class Theater {
    Performance<unsigned char>* smallPerformances;
    int numberOfSmall;
    int numberOfBig;
    Performance<unsigned short int>* bigPerformances;

    void addPerformance();
    void showPerformances();
    void showPerformances(int h);
public:
    Theater();
    ~Theater();
 
    void menu();
};




#endif //THEATER_THEATHER_HPP
