//
// Created by tperka on 07.05.19.
//

#ifndef THEATER_THEATHER_HPP
#define THEATER_THEATHER_HPP


#include "Performance.hpp"
#include "Ticket.hpp"
#include <functional>

class Theather {
    Performance<unsigned char>* smallPerformances;
    int numberOfSmall;
    int numberOfBig;
    Performance<unsigned short int>* bigPerformances;

    void addPerformance();
    void showPerformances();
    void showPerformances(int h);
public:
    Theather();
    ~Theather();
 
    void menu();
};




#endif //THEATER_THEATHER_HPP
