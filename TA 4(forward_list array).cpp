#include <iostream>
#include <conio.h>
#include <ctime>
#define MAX 90000 // Macro defines maximum no. of elements in the list. It is a user defined data type

using namespace std;

struct
{
    int list[MAX];
    int element;     //new element to be inserted
    int pos;           //position of the element to be inserted or deleted
    int length;     //total no of elements
}l;

int menu(void);           //This function displays the list of operations
void create(void);       //This function creates initial set of elements
void delet();       //This function deletes the element at given position
void display(void);       //This function displays the elements in the list
bool islistfull(void);  //This function checks whether the list is full or not boolean
bool islistempty(void);        //This function checks whether the list is empty or not

double start, stop;

void main()
{
    int ch;
    int pos;
    srand(time(0));
    l.length = 0;
    while (1)
    {
        ch = menu();
        switch (ch)
        {
        case 1:   l.length = 0;
            create();
            break;
        case 2:
            if (islistempty() != true)
            {
                delet();
            }
            else
            {
                cout << "List is Empty.";
                cout << "\n Press any key to continue...";
                _getch();
                system("cls");
            }
            break;
        case 3:
            system("cls");
            display();
            break;
        case 4:
            cout << "Exit";
            exit(0);
            break;
        default:  printf("Invalid Choice");
            cout << "\n Press any key to continue...";
            _getch();
            system("cls");
        }
    }
}        //function to display the list of elements
int menu()
{
    int ch;
    cout << "1. Create\n2. Delete\n3. Display\n4.Exit\n\n Enter your choice : ";
    cin >> ch;
    cout << "\n\n";
    return ch;
}
void create(void)
{
    int element;
        start = time(0);
        cout << "Enter amount of elements to randomise : ";
        int amount;
        cin >> amount;
        for(int i{}; i < amount; i++)
        {
            element = rand();
            l.list[l.length] = element;
            l.length++;
        }
        stop = time(0);
        cout << "Time of program = " << scientific << (stop - start) / 1e20 << endl;
        system("pause");
    system("cls");
}
void display(void)
{
    int i;
    for (i = 0; i < l.length; i++)
        cout << "Element" << i + 1 << ":" << l.list[i] << "\n";
    cout << "\n Press any key to continue...";
    _getch();
    system("cls");
}
void delet()
{
    int pos;
    int k;
    int old_pos[MAX]{};
    int amount;
    cout << "Enter amount of elements to delete\n";
    cin >> amount;
    start = time(0);
    for (int i{}; i < amount; i++)
    {
        pos = rand() % l.length + 1;
        for (int j{}; j < i; j++)
        {
            if (old_pos[j] == pos)
            {
                pos = rand() % l.length + 1;
            }
        }
        old_pos[i] = pos;
        if (pos == 0)
        {
            cout << "\nCannot delete at an element 0th position";
            _getch();
            return;
        }
        if (pos > l.length)
        {
            cout << "\n\n Only" << l.length << "elements exit. Cannot delete" << pos;
            cout << "\n Press any key to continue...";
            _getch();
            system("cls");
            return;
        }
        for (k = pos - 1; k < l.length; k++)
        {
            l.list[k] = l.list[k + 1];
        }
        l.length--;
    }
    stop = time(0);
    cout << "Time of program = " << scientific << (stop - start) / 1e20 << endl;
    system("pause");
    system("cls");
}

bool islistfull(void)
{
    if (l.length == MAX)
        return true;
    else
        return false;
}
bool islistempty(void)
{
    if (l.length == 0)
        return true;
    else
        return false;
}