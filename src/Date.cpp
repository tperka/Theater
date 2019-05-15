//
// Created by tperka on 29.04.19.
//

#include "Date.hpp"
#include "Input.hpp"

using namespace std;

ostream& operator<<(ostream& os, const Date dt)
{
    os<<dt.day<<"/"<<dt.month<<"/"<<dt.year<<"\t"<<dt.hour<<":"<<dt.mins;
    return os;
}

void Date::loadDateFromUser()
{
    string input;
    cout<<"Podaj rok: "<<endl;
    while(!(cin >> input) || !isNumber(input) || stoi(input) < 2019 || stoi(input) > 2030)
    {
        cout << "Błąd! Podaj prawidłową liczbę całkowitą z przedziału 2019-2030:" << endl;
    }
    year = input;

    cout << "Podaj miesiąc: "<<endl;
    while(!(cin >> input) || !isNumber(input) || stoi(input) < 1 || stoi(input) > 12)
    {
        cout << "Błąd! Podaj prawidłowy miesiąc (1-12):" << endl;
    }
    if(input.length() == 1)
    {
        input.insert(0, 1, '0');
    }
    month = input;

    cout << "Podaj dzień: "<<endl;
    while(!(cin >> input) || !isNumber(input) || stoi(input) < 1 || stoi(input) > 31 || (stoi(input) > 30 && (month == "04" || month == "06" || month == "09" ||
    month == "11")) || (stoi(input) > 28 && month == "02" && (stoi(year)%4 != 0)) || (stoi(input) > 29 && month == "02" && (stoi(year)%4 == 0)))
    {
        cout << "Błąd! Podaj prawidłowy dzień: " << endl;
    }
    if(input.length() == 1)
    {
        input.insert(0, 1, '0');
    }
    day = input;

    cout << "Podaj godzinę: "<<endl;
    while(!(cin >> input) || !isNumber(input) || stoi(input) > 23)
    {
        cout << "Błąd! Podaj prawidłową godzinę(0-23):" << endl;
    }
    if(input.length() == 1)
    {
        input.insert(0, 1, '0');
    }
    hour = input;

    cout << "Podaj minuty: " << endl;
    while(!(cin >> input) || !isNumber(input) || stoi(input) > 59)
    {
        cout << "Błąd! Podaj prawidłową wartość (0-59):" << endl;
    }
    if(input.length() == 1)
    {
        input.insert(0, 1, '0');
    }
    mins = input;
}