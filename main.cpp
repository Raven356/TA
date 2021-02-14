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
    cout << "������ ������ ���������� ������\n1)������ 2)����������� 3)� �����\n";
    int sw{get_Arguments()};
    //start = clock();
    switch (sw)
    {
    case 1 :
        {
            cout << "������ ������� �������� ������\n";
            do
            {
                n = get_Arguments();
                if(n < 2 || n > 100)
                    cout << "��������� ��\n";
            }while(n < 2 || n > 100);
            for(int i{}; i < n; i++)
                {
                    cout << i+1 << ")������� = ";
                    mas[i] = get_Arguments();
                    if(mas[i] > 1e+6 || mas[i] < -1e+6)
                    {
                        cout << "��������� �� ���\n";
                        i--;
                    }
                }
                //start = clock();
            //sort(mas, mas + n, comp);
            //cout << "��������� ������� = " << mas[0] << endl;
            break;
        }
    case 2 :
        {
            webcam.open("����_������_���������_�������.txt", ios_base::out | ios_base::trunc);
            srand((time(0) + 1));
            cout << "������ ������� �������� ������\n";
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
            //cout << "��������� ������� = " << mas[0] << endl;
            webcam.close();
            //start = clock();
            break;
        }
    case 3:
        {
            ifstream webcam;
            webcam.open("3_���.txt", ios_base::in);
            for(int i{}; i < 100; i++)
            {
                webcam >> mas[i];
                cout << i+1 << ")mas = " << mas[i] << endl;
            }
            n = 100;
            //sort(mas, mas + 100, comp);
            //cout << "��������� ������� = " << mas[0] << endl;
            webcam.close();
            //start = clock();
            break;
        }
    default :
        {
            cout << "�� ������ ������� ������\n";
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
    cout << "��������� ������� = " << n_e << endl;
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
  int left = 0, right = count - 1; // ����� � ������ ������� ����������� ������� �������
  int flag = 1;  // ���� ������� �����������
  // ���������� ����� ���� ����� ������� �� �������� � ������
  // � ���� � ������� ������� �����������
  double start, stop;
  start = clock();
  while ((left < right) && flag > 0)
  {
    flag = 0;
    for (int i = left; i<right; i++)  //��������� ����� �������
    {
      if (mass[i]>mass[i + 1]) // ���� ��������� ������� ������ ��������,
      {             // ������ �� �������
        double t = mass[i];
        mass[i] = mass[i + 1];
        mass[i + 1] = t;
        flag = 1;      // ����������� � ���� ����� ����
      }
    }
    right--; // �������� ������ ������� �� ���������� �������
    for (int i = right; i>left; i--)  //��������� ������ ������
    {
      if (mass[i - 1]>mass[i]) // ���� ���������� ������� ������ ��������,
      {            // ������ �� �������
        double t = mass[i];
        mass[i] = mass[i - 1];
        mass[i - 1] = t;
        flag = 1;    // ����������� � ���� ����� ����
      }
    }
    left++; // �������� ����� ������� �� ��������� �������
  }
  stop = clock();
  cout << "��� �� ��������� = " << stop - start << endl;
}
