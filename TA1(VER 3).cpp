#include <iostream>
#include <windows.h>
#include <ctime>
#include <algorithm>
#include <fstream>

using namespace std;

int get_Arguments();
bool comp(int, int);
bool end_of_Program();
void shekerSort(int *mass, int count);
int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream webcam;
	do
    {
    int n{};
    int mas[100000];
    time_t start{}, stop{};
    //start = clock();
    //time(&start);
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
                //start = clock();
            //sort(mas, mas + n, comp);
            //cout << "Íàéìåíøèé åëåìåíò = " << mas[0] << endl;
            break;
        }
    case 2 :
        {
            webcam.open("Ôàéë_âèâîäó_ðàíäîìíèõ_çíà÷åíü.txt", ios_base::out | ios_base::trunc);
            srand((time(0) + 1));
            cout << "Ââåä³òü ê³ëüê³ñòü åëåìåíò³â ìàñèâó\n";
            n = get_Arguments();
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
            //start = clock();
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
            //start = clock();
            break;
        }
    default :
        {
            cout << "Âè îáðàëè íåâ³ðíèé âàð³àíò\n";
            goto tryAgain;
        }
    }
    //time(&start);
    shekerSort(mas, n);
    int n_e{mas[0]};
    /*for(int i{1}; i < n; i++)
    {
        if(n_e > mas[i])
            n_e = mas[i];
    }*/
    //time(&stop);
    cout << "Íàéìåíøèé åëåìåíò = " << n_e << endl;
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
void shekerSort(int *mass, int count)
{
  int left = 0, right = count - 1; // ëåâàÿ è ïðàâàÿ ãðàíèöû ñîðòèðóåìîé îáëàñòè ìàññèâà
  int flag = 1;  // ôëàã íàëè÷èÿ ïåðåìåùåíèé
  // Âûïîëíåíèå öèêëà ïîêà ëåâàÿ ãðàíèöà íå ñîìêí¸òñÿ ñ ïðàâîé
  // è ïîêà â ìàññèâå èìåþòñÿ ïåðåìåùåíèÿ
  double start, stop;
  start = clock();
  while ((left < right) && flag > 0)
  {
    flag = 0;
    for (int i = left; i<right; i++)  //äâèãàåìñÿ ñëåâà íàïðàâî
    {
      if (mass[i]>mass[i + 1]) // åñëè ñëåäóþùèé ýëåìåíò ìåíüøå òåêóùåãî,
      {             // ìåíÿåì èõ ìåñòàìè
        double t = mass[i];
        mass[i] = mass[i + 1];
        mass[i + 1] = t;
        flag = 1;      // ïåðåìåùåíèÿ â ýòîì öèêëå áûëè
      }
    }
    right--; // ñäâèãàåì ïðàâóþ ãðàíèöó íà ïðåäûäóùèé ýëåìåíò
    for (int i = right; i>left; i--)  //äâèãàåìñÿ ñïðàâà íàëåâî
    {
      if (mass[i - 1]>mass[i]) // åñëè ïðåäûäóùèé ýëåìåíò áîëüøå òåêóùåãî,
      {            // ìåíÿåì èõ ìåñòàìè
        double t = mass[i];
        mass[i] = mass[i - 1];
        mass[i - 1] = t;
        flag = 1;    // ïåðåìåùåíèÿ â ýòîì öèêëå áûëè
      }
    }
    left++; // ñäâèãàåì ëåâóþ ãðàíèöó íà ñëåäóþùèé ýëåìåíò
  }
  stop = clock();
  cout << "×àñ íà âèêîíàííÿ = " << stop - start << endl;
}
