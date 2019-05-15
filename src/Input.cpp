/**
 * Autor: Tymoteusz Perka
 * Nr indeksu: 300243
 * Prowadzący: mgr Wiktor Kuśmirek
 * Projekt: 9. Symulacja teatru
**/

#include "Input.hpp"


bool isNumber(std::string input)
{
    for(unsigned int i = 0; i < input.length(); ++i)
    {
        if(input[i] < '0' || input[i] > '9')
            return false;
    }
    return true;
}

bool isName(std::string input)
{
    for(unsigned int i = 0; i < input.length(); ++i)
    {
        if(input[i] == ' ' || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
            continue;
        else
            return false;
    }
    return true;
}

