/**
 * Autor: Tymoteusz Perka
 * Nr indeksu: 300243
 * Prowadzący: mgr Wiktor Kuśmirek
 * Projekt: 9. Symulacja teatru
**/

#ifndef THEATER_TICKET_HPP
#define THEATER_TICKET_HPP


#include <string>


class Ticket {
    std::string name;
    int row;
    int column;
public:
    Ticket(std::string n = " ", int r = 0, int c = 0)
    : name(n), row(r), column(c)
    {}

    friend std::ostream& operator<<(std::ostream& os, const Ticket& tick);

    void setTicket(int maxrow, int maxcol);
    int* getSeat();

};

std::ostream& operator<<(std::ostream& os, const Ticket& tick);


#endif //THEATER_TICKET_HPP
