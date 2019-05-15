/**
 * Autor: Tymoteusz Perka
 * Nr indeksu: 300243
 * Prowadzący: mgr Wiktor Kuśmirek
 * Projekt: 9. Symulacja teatru
**/

#ifndef THEATER_TICKET_HPP
#define THEATER_TICKET_HPP


#include <string>
#include <iostream>

class Ticket {
    std::string name;
    int row;
    int column;
public:
    Ticket(std::string n = " ", int r = 0, int c = 0)
    : name(n), row(r), column(c)
    {}

    friend std::ostream& operator<<(std::ostream& os, const Ticket& tick)
    {
        os<<tick.name << "\t" << tick.row + 1 <<"\t"<< tick.column + 1 <<std::endl;
        return os;
    }

    void setTicket(int maxrow, int maxcol);
    int* getSeat();

};




#endif //THEATER_TICKET_HPP
