#include <iostream>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <fstream>

using namespace std;

int get_Arguments();
bool comp(int, int);
bool end_of_Program();
void sort_m(int*, int*, int);
int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream webcam;
	do
    {
    int n{};
    int mas[100];
    double start{}, stop{};
    //start = clock();
    tryAgain:
    system("cls");
    cout << "Îáåð³òü âàð³àíò çàïîâíåííÿ ìàñèâó\n1)Âðó÷íó 2)Àâòîìàòè÷íî 3)Ç ôàéëó\n";
    int sw{get_Arguments()};
    //start = clock();
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
                start = clock();
            //sort(mas, mas + n, comp);
            //cout << "Íàéìåíøèé åëåìåíò = " << mas[0] << endl;
            break;
        }
    case 2 :
        {
            webcam.open("Ôàéë_âèâîäó_ðàíäîìíèõ_çíà÷åíü.txt", ios_base::out | ios_base::trunc);
            srand((time(0) + 1));
            n = rand() % 100 + 2;
            cout << "n = " << n << endl;
            srand(time(0));
            for(int i{}; i < n; i++)
            {
                mas[i] = rand();
                webcam << i+1 << ")mas = " << mas[i] << endl;
                cout << i+1 << ")mas = " << mas[i] << endl;
            }
            //sort(mas, mas + n, comp);
            //cout << "Íàéìåíøèé åëåìåíò = " << mas[0] << endl;
            webcam.close();
            start = clock();
            break;
        }
    case 3:
        {
            ifstream webcam;
            webcam.open("3_ââ³ä.txt", ios_base::in);
            for(int i{}; i < 100; i++)
            {
                webcam >> mas[i];
                cout << i+1 << ")mas = " << mas[i] << endl;
            }
            n = 100;
            //sort(mas, mas + 100, comp);
            //cout << "Íàéìåíøèé åëåìåíò = " << mas[0] << endl;
            webcam.close();
            start = clock();
            break;
        }
    default :
        {
            cout << "Âè îáðàëè íåâ³ðíèé âàð³àíò\n";
            goto tryAgain;
        }
    }
/*    for (int iteration = 0; iteration < n; ++iteration)
    {
        int endOfArrayIndex(n - iteration);

        bool swapped(false); // îòñëåæèâàåì, áûëè ëè âûïîëíåíû çàìåíû â ýòîé èòåðàöèè

        for (int currentIndex = 0; currentIndex < endOfArrayIndex; ++currentIndex)
        {
            // Åñëè òåêóùèé ýëåìåíò áîëüøå ýëåìåíòà, ñëåäóþùåãî çà íèì,
            if (mas[currentIndex] > mas[currentIndex + 1])
            {
                swap(mas[currentIndex], mas[currentIndex + 1]);
                swapped = true;
            }
        }

        // Åñëè â ýòîé èòåðàöèè íå âûïîëíèëîñü íè îäíîé çàìåíû, òî öèêë ìîæíî çàâåðøàòü
        if (!swapped)
        {
            break;
        }
    }*/
    //start = clock();
    int n_e{mas[0]};
    for(int i{1}; i < n; i++)
        if(n_e > mas[i])
            n_e = mas[i];
    stop = clock();
    cout << "Íàéìåíøèé åëåìåíò = " << n_e << endl;
    //for(int i{}; i < n; i++)
    //cout << i+1 << ")mas = " << mas[i] << endl;
    double time_of_prog{(stop - start) / CLK_TCK};
    cout << scientific << "×àñ íà îá÷èñëåííÿ = " << time_of_prog << endl;
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
