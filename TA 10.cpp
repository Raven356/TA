#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

void swap(double* a, double* b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

int partition(double arr[], int low, int high)
{
	double pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(double arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(double arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void quick(double a[], int lower, int upper)
{
    while (lower < upper)
    {
        int loc = partition(a, lower, upper);
        if (loc - lower < upper - loc)
        { /* Lower part is shorter... */
            quick(a, lower, loc - 1); /* ...process it recursively... */
            lower = loc + 1; /* ...and process the upper part on the next iteration */
        }
        else
        { /* Upper part is shorter... */
            quick(a, loc + 1, upper); /* ...process it recursively... */
            upper = loc - 1; /* ...and process the lower part on the next iteration */
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do
    {
        system("cls");
        int amount_of_chests;
        cout << "Введіть кількість потрібних сундучків з золотом (1 випадок): ";
        cin >> amount_of_chests;
        double* mas = new double[amount_of_chests];
        srand(time(0));
        for (int i{}; i < amount_of_chests; i++)
        {
            mas[i] = fmod(rand(), 10000) + 1;
            if (amount_of_chests < 100)
                cout << mas[i] << endl;
        }
        ofstream file1;
        ifstream file;
        cout << "Для 1 випадку:\n";
        double start = clock();
        quickSort(mas, 0, amount_of_chests - 1);
        double stop = clock();
        cout << (stop - start) / 1000 << endl;
        file1.open("File1.txt", ios_base::out);
        for (int i{}; i < amount_of_chests; i++)
        {
            file1 << mas[i] << "\n";
        }
        file1.close();
        delete[] mas;

        int new_chests;
        cout << "Введіть кількість додаткових сундучків з золотом (2 випадок): ";
        cin >> new_chests;
        mas = new double[amount_of_chests + new_chests];
        file.open("File1.txt", ios_base::in);
        for (int i{}; i < amount_of_chests; i++)
        {
            file >> mas[i];
        }
        file.close();
        for (int i{ amount_of_chests }; i < amount_of_chests + new_chests; i++)
        {
            mas[i] = fmod(rand(), 10000) + 1;
            if (new_chests < 100)
                cout << mas[i] << endl;
        }
        amount_of_chests += new_chests;

        cout << "Для 2 випадку:\n";
        start = clock();
        quickSort(mas, 0, amount_of_chests - 1);
        stop = clock();
        cout << (stop - start) / 1000 << endl;
        file1.open("File1.txt", ios_base::out);
        for (int i{}; i < amount_of_chests; i++)
        {
            file1 << mas[i] << "\n";
        }
        file1.close();
        delete[] mas;
        cout << "Введіть кількість додаткових сундучків з золотом (3 випадок): ";
        cin >> new_chests;
        mas = new double[amount_of_chests + new_chests];

        file.open("File1.txt", ios_base::in);
        for (int i{}; i < amount_of_chests; i++)
        {
            file >> mas[i];
        }
        file.close();
        for (int i{ amount_of_chests }; i < amount_of_chests + new_chests; i++)
        {
            mas[i] = fmod(rand(), 10000) + 1;
            if (new_chests < 100)
                cout << mas[i] << endl;
        }
        amount_of_chests += new_chests;

        file1.close();
        cout << "Для 3 випадку:\n";
        start = clock();
        quick(mas, 0, amount_of_chests - 1);
        stop = clock();
        cout << (stop - start) / 1000 << endl;
        file1.open("File1.txt", ios_base::out);
        for (int i{}; i < amount_of_chests; i++)
        {
            file1 << mas[i] << "\n";
        }
        delete[] mas;
    } while (_getch() != 27);
}
