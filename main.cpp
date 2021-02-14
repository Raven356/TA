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
    cout << "Оберіть варіант заповнення масиву\n1)Вручну 2)Автоматично 3)З файлу\n";
    int sw{get_Arguments()};
    //start = clock();
    switch (sw)
    {
    case 1 :
        {
            cout << "Введіть кількість елементів масиву\n";
            do
            {
                n = get_Arguments();
                if(n < 2 || n > 100)
                    cout << "Спробуйте ще\n";
            }while(n < 2 || n > 100);
            for(int i{}; i < n; i++)
                {
                    cout << i+1 << ")елемент = ";
                    mas[i] = get_Arguments();
                    if(mas[i] > 1e+6 || mas[i] < -1e+6)
                    {
                        cout << "Спробуйте ще раз\n";
                        i--;
                    }
                }
                //start = clock();
            //sort(mas, mas + n, comp);
            //cout << "Найменший елемент = " << mas[0] << endl;
            break;
        }
    case 2 :
        {
            webcam.open("Файл_виводу_рандомних_значень.txt", ios_base::out | ios_base::trunc);
            srand((time(0) + 1));
            cout << "Введіть кількість елементів масиву\n";
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
            //cout << "Найменший елемент = " << mas[0] << endl;
            webcam.close();
            //start = clock();
            break;
        }
    case 3:
        {
            ifstream webcam;
            webcam.open("3_ввід.txt", ios_base::in);
            for(int i{}; i < 100; i++)
            {
                webcam >> mas[i];
                cout << i+1 << ")mas = " << mas[i] << endl;
            }
            n = 100;
            //sort(mas, mas + 100, comp);
            //cout << "Найменший елемент = " << mas[0] << endl;
            webcam.close();
            //start = clock();
            break;
        }
    default :
        {
            cout << "Ви обрали невірний варіант\n";
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
    cout << "Найменший елемент = " << n_e << endl;
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
  int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
  int flag = 1;  // флаг наличия перемещений
  // Выполнение цикла пока левая граница не сомкнётся с правой
  // и пока в массиве имеются перемещения
  double start, stop;
  start = clock();
  while ((left < right) && flag > 0)
  {
    flag = 0;
    for (int i = left; i<right; i++)  //двигаемся слева направо
    {
      if (mass[i]>mass[i + 1]) // если следующий элемент меньше текущего,
      {             // меняем их местами
        double t = mass[i];
        mass[i] = mass[i + 1];
        mass[i + 1] = t;
        flag = 1;      // перемещения в этом цикле были
      }
    }
    right--; // сдвигаем правую границу на предыдущий элемент
    for (int i = right; i>left; i--)  //двигаемся справа налево
    {
      if (mass[i - 1]>mass[i]) // если предыдущий элемент больше текущего,
      {            // меняем их местами
        double t = mass[i];
        mass[i] = mass[i - 1];
        mass[i - 1] = t;
        flag = 1;    // перемещения в этом цикле были
      }
    }
    left++; // сдвигаем левую границу на следующий элемент
  }
  stop = clock();
  cout << "Час на виконання = " << stop - start << endl;
}
