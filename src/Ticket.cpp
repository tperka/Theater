/**
 * Autor: Tymoteusz Perka
 * Nr indeksu: 300243
 * Prowadzący: mgr Wiktor Kuśmirek
 * Projekt: 9. Symulacja teatru
**/
#include "Ticket.hpp"

using namespace std;

void Ticket::setTicket(int maxrow, int maxcol)
{
    string input;
    cin.clear();
    cin.ignore( numeric_limits < streamsize >::max(), '\n' );
    cout << "Podaj imię i nazwisko kupującego: " << endl;
    while (!(getline(cin, input)) || !isName(input)) 
        cout << "Podaj prawidłowe imię i nazwisko (tylko litery i spacje)" << endl;
    
    name = input;
    cout << "Podaj rząd miejsca (1-"<<maxrow<<"):" << endl;
    while (!(cin >> input) || !isNumber(input) || stoi(input) > maxrow) {
        cout << "Podaj prawidłowy numer rzędu (1-" << maxrow<< "):" << endl;
    }
    row = stoi(input) - 1;
    cout << "Podaj kolumnę miejsca (1-"<<maxcol<<"):" << endl;
    while (!(cin >> input) || !isNumber(input) || stoi(input) > maxcol) {
        cout << "Podaj prawidłowy numer kolumny (1-" << maxcol << "):" << endl;
    }
    column = stoi(input) - 1;
}


int* Ticket::getSeat()
{
    int* seat = new int[2];
    seat[0] = row;
    seat[1] = column;
    return seat;
}