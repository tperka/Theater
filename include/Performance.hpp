/**
 * Autor: Tymoteusz Perka
 * Nr indeksu: 300243
 * Prowadzący: mgr Wiktor Kuśmirek
 * Projekt: 9. Symulacja teatru
**/

#ifndef THEATER_PERFORMANCE_H
#define THEATER_PERFORMANCE_H

#include "Date.hpp"
#include "Ticket.hpp"
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

template <class T = unsigned short int>
class Performance {
    Date date;
    std::string title;
    unsigned short int duration;
    T nOfTickets;
    std::vector<std::vector<unsigned char>> hallPlan;
    std::vector<Ticket> tickets;
    int hall;

    void delTicket();
    void addTicket();
    void showTickets();
    void showHall();
    void setNumberOfTickets(T n);
    Performance& operator--();
    Performance& operator++();
public:
    Performance(int hN = 0, std::string t = " ", unsigned short int dur = 0, T nOfT = 0)
    : date(), title(t), duration(dur), hall(hN)
    {
        setNumberOfTickets(nOfT);
        if(hN == 2)
        {
            for(int i = 0; i < 20; i++)
            {
                std::vector<unsigned char> help;
                for(int j = 0; j < 25; ++j)
                    help.push_back('O');

                hallPlan.push_back(help);
            }
        }
        else
        {
            for(int i = 0; i < 10; i++)
            {
                std::vector<unsigned char> help;
                for(int j = 0; j < 15; ++j)
                    help.push_back('O');

                hallPlan.push_back(help);
            }
        }
        
    }
    void menu();
    
    void setDate(Date d);
    void loadPerformanceFromUser();
    
    friend std::ostream& operator<<(std::ostream& os, const Performance<T>& perf)
    {
        os<<perf.title<<"\t"<<perf.duration<<"\t"<<perf.date<<"\t" <<perf.hall << "\t" << (int)perf.nOfTickets<<std::endl;
        return os;
    }

};

template <class T>
void Performance<T>::setDate(Date d)
{
    date = d;
}

template <class T>
Performance<T>& Performance<T>::operator--()
{
    this->nOfTickets--;
    return *this;
}

template <class T>
Performance<T>& Performance<T>::operator++()
{
    this->nOfTickets++;
    return *this;
}

template <class T>
void Performance<T>::setNumberOfTickets(T n)
{
    nOfTickets = n;
}

template <>
inline void Performance<unsigned short int>::loadPerformanceFromUser()
{
    std::string input;
    std::cout << "Podaj nazwę spektaklu: " << std::endl;
    std::cin.clear();
    std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
    while(!(std::getline(std::cin, input)) || !isName(input))
    {
        std::cout << "Błąd! Podaj prawidłową nazwę (tylko litery i spacje):" << std::endl;
    }
    title = input;
    std::cout << "Podaj czas trwania spektaklu: "<<std::endl;
    while(!(std::cin >> input) || !isNumber(input))
    {
        std::cout << "Błąd! Podaj prawidłową wartość:" << std::endl;
    }
    duration = stoi(input);
    Date A;
    A.loadDateFromUser();
    date = A;
    nOfTickets = 500;

}

template <>
inline void Performance<unsigned char>::loadPerformanceFromUser()
{
    std::string input;
    std::cout << "Podaj nazwę spektaklu: " << std::endl;
    std::cin.clear();
    std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
    while(!(std::getline(std::cin, input)) || !isName(input))
    {
        std::cout << "Błąd! Podaj prawidłową nazwę (tylko litery i spacje):" << std::endl;
    }
    title = input;
    std::cout << "Podaj czas trwania spektaklu: "<<std::endl;
    while(!(std::cin >> input) || !isNumber(input))
    {
        std::cout << "Błąd! Podaj prawidłową wartość:" << std::endl;
    }
    duration = stoi(input);
    Date A;
    A.loadDateFromUser();
    date = A;
    nOfTickets = 150;
}


template<class T>
void Performance<T>::showHall()
{
    std::cout << "Ekran znajduje się po lewej stronie." << std::endl
    <<"O- wolne, X- zajęte" << std::endl;
    std::cout << "   ";
    for (unsigned int i = 0; i < hallPlan.size(); i++) 
        std::cout << std::setw(3) << i+1;
		
    std::cout << std::endl;
    for (unsigned int i = 0; i < hallPlan[0].size(); i++) {
		std::cout << std::setw(3) << i+1;
		for (unsigned int j = 0; j < hallPlan.size(); j++) {
			std::cout << std::setw(3) << hallPlan[j][i];
		}
		std::cout << std::endl;
	}
}

template <class T>
void Performance<T>::delTicket()
{
    if(tickets.size() > 0)
    {
        std::cout << std::setw(20) << "Nr\tOsoba\tRząd\tKolumna" << std::endl;
        for(unsigned int i = 0; i < tickets.size(); ++i)
            std::cout << i+1 << ". "<< tickets[i];

        std::cout << "Który bilet chciałbyś anulować?" << std::endl;
        unsigned int ans = 0;
        while(!(std::cin>>ans) || ans < 1 || ans > tickets.size())
            std::cout << "Nie ma takiego biletu, spróbuj ponownie" << std::endl;

        int* seat = tickets[ans-1].getSeat();
        hallPlan[seat[0]][seat[1]] = 'O';
        tickets.erase(tickets.begin() +(ans-1));
        delete [] seat;
        ++*this;
    }
    else
    {
        std::cout << "Nie ma żadnych wydanych biletów." << std::endl;
    }
    
}

template<class T>
void Performance<T>::addTicket()
{
    Ticket tick;
    tick.setTicket((int)hallPlan.size(), (int)hallPlan[0].size());
    int* seat = tick.getSeat();
    if(hallPlan[seat[0]][seat[1]] == 'X')
        std::cout << "To miejsce jest już zajęte, nie udało się dokonać rezerwacji" << std::endl;
    else
    {
        tickets.push_back(tick);
        hallPlan[seat[0]][seat[1]] = 'X';
        --*this;
    }
   delete []seat;
}

template<class T>
void Performance<T>::showTickets()
{
    if(tickets.size() == 0)
        std::cout << "Brak wydanych biletów." << std::endl;
    else
    {
        std::cout << std::setw(20) << "Osoba\tRząd\tKolumna" << std::endl;
        std::vector<Ticket>::iterator it = tickets.begin();
        for(;it != tickets.end(); it++)
            std::cout << *it;
    }
}

template<class T>
void Performance<T>::menu()
{
    int ans = 0;
    do
    { 
        std::cout << "---------------------------------------------------" << std::endl;   
        std::cout << *this << std::endl; 
        std::cout << "Co chciałbyś zrobić?" <<std::endl
        << "1. Wydać bilet" << std::endl << "2. Zobaczyć plan sali" << std::endl
        <<"3. Anulować bilet" << std::endl << "4. Wyświetlić wszystkie wydane bilety"
        << std::endl << "5. Wrócić do menu głównego" << std::endl;
        while(!(std::cin>>ans) || ans < 1 || ans > 5)
            std::cout << "Niepoprawne polecenie, spróbuj ponownie" << std::endl;

        switch(ans)
        {
            case 1:
                addTicket();
                break;
            case 2:
                showHall();
                break;
            case 3:
                delTicket();
                break;
            case 4:
                showTickets();
                break;
            default:
                break;
        }

    }while(ans != 5);
}

#endif //THEATER_PERFORMANCE_H
