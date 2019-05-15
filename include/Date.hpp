/**
 * Autor: Tymoteusz Perka
 * Nr indeksu: 300243
 * Prowadzący: mgr Wiktor Kuśmirek
 * Projekt: 9. Symulacja teatru
**/

#ifndef THEATER_DATE_HPP
#define THEATER_DATE_HPP

#include <string>

class Date {
    std::string day;
    std::string month;
    std::string year;
    std::string hour;
    std::string mins;
public:
    Date(std::string d = "00", std::string m = "00", std::string y = "0000", std::string h = "00", std::string min = "00")
    : day(d), month(m), year(y), hour(h), mins(min)
    {}
    friend std::ostream& operator<<(std::ostream& os, const Date dt);
    void loadDateFromUser();
};

std::ostream& operator<<(std::ostream& os, const Date dt);

#endif //THEATER_DATE_HPP
