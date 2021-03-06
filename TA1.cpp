#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <fstream>

using namespace std;

int get_Arguments();
bool comp(int, int);
bool end_of_Program();
int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream webcam;
	do
    {
    int n{};
    tryAgain:
    system("cls");
    cout << "Îáåð³òü âàð³àíò çàïîâíåííÿ ìàñèâó\n1)Âðó÷íó 2)Àâòîìàòè÷íî 3)Ç ôàéëó\n";
    int sw{get_Arguments()};
    switch (sw)
    {
    case 1 :
        {
            cout << "Ââåä³òü ê³ëüê³ñòü åëåìåíò³â ìàñèâó\n";
            do
            {
                n = get_Arguments();
                if(n < 2 || n > 100)
                    cout << "Ñïðîáóéòå ùå\n";
            }while(n < 2 || n > 100);
            int mas[n];
            for(int i{}; i < n; i++)
                {
                    cout << i+1 << ")åëåìåíò = ";
                    mas[i] = get_Arguments();
                    if(mas[i] > 1e+6 || mas[i] < -1e+6)
                    {
                        cout << "Ñïðîáóéòå ùå ðàç\n";
                        i--;
                    }
                }
            sort(mas, mas + n, comp);
            cout << "Íàéìåíøèé åëåìåíò = " << mas[0] << endl;
            break;
        }
    case 2 :
        {
            webcam.open("Ôàéë_âèâîäó_ðàíäîìíèõ_çíà÷åíü.txt", ios_base::out | ios_base::trunc);
            srand((time(0) + 1));
            n = rand() % 100 + 2;
            cout << "n = " << n << endl;
            int mas[n];
            srand(time(0));
            for(int i{}; i < n; i++)
            {
                mas[i] = rand();
                webcam << i+1 << ")mas = " << mas[i] << endl;
            }
            sort(mas, mas + n, comp);
            cout << "Íàéìåíøèé åëåìåíò = " << mas[0] << endl;
            webcam.close();
            break;
        }
    case 3:
        {
            ifstream webcam;
            webcam.open("3_ââ³ä.txt", ios_base::in);
            int mas[100];
            for(int i{}; i < 100; i++)
            {
                webcam >> mas[i];
            }
            sort(mas, mas + 100, comp);
            cout << "Íàéìåíøèé åëåìåíò = " << mas[0] << endl;
            webcam.close();
            break;
        }
    default :
        {
            cout << "Âè îáðàëè íåâ³ðíèé âàð³àíò\n";
            goto tryAgain;
        }
    }
    }while(end_of_Program());
    return 0;
}
int get_Arguments()
{
    double x;
    do
    {
        cin >> x;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "You entered wrong symbol\n";
            continue;
        }
        char c[256];
        fgets(c, 256, stdin);
        if(strlen(c) > 1)
        {
            cout << "There were some wrong symbols , try again please\n";
            continue;
        }
        return x;
    }while(true);
}
bool comp (int a, int b) {return a < b;}
bool end_of_Program()
{
    cout << "Press y to continue and n to end program\n";
    char choice;
    do
    {
    cin >> choice;
    if(choice != 'y' && choice != 'n')
        cout << "Please choose y or n\n";
    }
    while(choice != 'y' && choice != 'n');
        return choice == 'y';
}

