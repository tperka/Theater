/**
 * Autor: Tymoteusz Perka
 * Nr indeksu: 300243
 * Prowadzący: mgr Wiktor Kuśmirek
 * Projekt: 9. Symulacja teatru
**/

#include <algorithm>
#include "Theater.hpp"
using namespace std;

Theater::Theater()
{
    smallPerformances = new Performance<unsigned char>[3];
    bigPerformances = new Performance<unsigned short int>[3];
    numberOfSmall = numberOfBig = 2;
    Performance<unsigned char> pib(1,"Piękna i Bestia", 150, 150);
    Date PiB("22","08","2019","14","20");
    pib.setDate(PiB);
    smallPerformances[0] = pib;
    Performance<unsigned char> bal(1,"Balladyna", 175, 150);
    Date Bal("18","07","2019","17","45");
    bal.setDate(Bal);
    smallPerformances[1] = bal;

    Performance<> dzb(2, "Dzieci z Bullerbyn", 220, 500);
    Date Dzb("01","09","2019","12","15");
    dzb.setDate(Dzb);
    bigPerformances[0] = dzb;
    Performance<> metro(2, "Metro", 200, 500);
    Date Met("21","05","2019","14","00");
    metro.setDate(Met);
    bigPerformances[1] = metro;


}




void Theater::showPerformances()
{
    cout << setw(20)<< "\tTytuł\tCzas trwania\tData\t\tGodzina\tSala\tPozostało biletów" << endl;
    for(int i = 0; i < numberOfSmall; ++i)
        cout <<setw(20)<< smallPerformances[i];
    for(int i = 0; i < numberOfBig; ++i)
        cout <<setw(20)<< bigPerformances[i];
}
void Theater::showPerformances(int h) {
   cout << setw(20) <<  "\t  Tytuł\t  Czas trwania\tData\t\tGodzina\tSala\tPozostało biletów" << endl;
    if (h == 1) {
        for (int i = 0; i < numberOfSmall; ++i)
            cout << i+1 <<". "<<setw(20)<< smallPerformances[i];
    }
    else
    {
        for (int i = 0; i < numberOfBig; ++i)
            cout << i+1 <<". "<< setw(20) << bigPerformances[i];
    }
}

Theater::~Theater()
{
    delete [] smallPerformances;
    delete [] bigPerformances;
}

void Theater::addPerformance()
{
    cout << "W której sali będzię odbywać się spektakl?" << endl;
    string input;
    while(!(cin >> input) || !isNumber(input) || (stoi(input) != 1 && stoi(input) != 2))
        cout << "Podaj prawidłowy numer sali (1 lub 2)" << endl;

    if(stoi(input) == 1)
    {
        Performance<unsigned char> newer(1);
        newer.loadPerformanceFromUser();
        Performance<unsigned char>* bigger = new Performance<unsigned char>[numberOfSmall +1];
        for(int i = 0; i < numberOfSmall; ++i)
            bigger[i] = smallPerformances[i];

        delete [] smallPerformances;
        smallPerformances = bigger;
        smallPerformances[numberOfSmall] = newer;
        ++numberOfSmall;
    }
    else
    {
        Performance<unsigned short int> newer(2);
        newer.loadPerformanceFromUser();
        Performance<>* bigger = new Performance<>[numberOfBig + 1];
        for(int i = 0; i < numberOfBig; ++i)
            bigger[i] = bigPerformances[i];

        delete [] bigPerformances;
        bigPerformances = bigger;
        bigPerformances[numberOfBig] = newer;
        ++numberOfBig;
    }
}

void Theater::menu()
{
    int ans = 0;
    do
    {
        cout << "Aktualny repertuar:" << endl;
        showPerformances();
        cout << "Co chciałbyś zrobić?" << endl << "1. Dodać spektakl" << endl
        << "2. System obsługi sali numer 1" << endl << "3. System obsługi sali numer 2"
        << endl << "4. Wyjść" << endl;
        
        while(!(cin>>ans) || ans < 1 || ans > 4)
                cout << "Niepoprawne polecenie, użyj cyfry z zakresu 1-4:" << endl;

        switch(ans)
        {
            case 1:
                addPerformance();
                break;
            case 2:
            {
                int ans1 = 0;
                showPerformances(1);
                cout << "Wybierz spektakl do obsługi:" << endl;
                while(!(cin>>ans1) || ans1 < 1 || ans1 > numberOfSmall)
                    cout << "Niepoprawne polecenie, użyj cyfry z zakresu 1-" <<
                    numberOfSmall << ":" << endl;

                smallPerformances[ans1-1].menu();
                break;
            }
            case 3:
            {
                int ans2 = 0;
                showPerformances(2);
                cout << "Wybierz spektakl do obsługi:" << endl;
                while(!(cin>>ans2) || ans2 < 1 || ans2 > numberOfBig)
                    cout << "Niepoprawne polecenie, użyj cyfry z zakresu 1-" <<
                    numberOfBig << ":" << endl;

                bigPerformances[ans2-1].menu();
                break;
            }
            default:
                cout << "Do zobaczenia!" << endl;
                break;
        }
    }while(ans != 4);
}
