#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

template <class T>
class List
{
public:
    List();
    ~List();

    int GetSize()
    {
        return Size;
    }

    void pop_front();
    void push_back(T data);
    void clear();
    void push_front(T data);
    void insert(T value, int index);
    void removeAt(int index);

    T& operator[](const int index); // перегрузка оператора


private:

    template <class T>
    class Node
    {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr) //T data = T() - инициализация по умолчанию на любой тип данных
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T>* head;

};

template <class T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template <class T>
List<T>::~List()
{
    clear();

}

template<class T>
void List<T>::pop_front()
{
    Node<T>* temp = head;

    head = head->pNext;

    delete temp;

    Size--;
}

template <class T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext; // присваивание новго адресса
        }
        current->pNext = new Node<T>(data);
    }

    Size++;
}

template<class T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<class T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<class T>
void List<T>::insert(T value, int index)
{
    if (index == 0)
    {
        push_front(value);
    }
    else
    {

        Node<T>* previous = this->head;

        for (int i{}; i < index; i++)
        {
            previous = previous->pNext;
        }
        Node<T>* newNode = new Node<T>(value, previous->pNext);
        previous->pNext = newNode;
        Size++;

    }
}

template<class T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {

        Node<T>* previous = this->head;

        for (int i{}; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;

        Size--;
    }
}

template<class T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext; // если не найдено значение передаем адрес следующего элемента
        counter++;
    }
}

void add_Elements();
void delete_Elements();
void output_Elements();
void menu();

List<int> lst;

double start, stop;

int main()
{
    srand(time(0));
    menu();

    return 0;
}

void add_Elements()
{
    int amount, element;
    cout << "Enter amount of elements to add : ";
    cin >> amount;
    start = time(0);
    for (int i{}; i < amount; i++)
    {
        element = rand();
        lst.push_back(element);
    }
    stop = time(0);
    cout << "Time of program = " << (stop - start) / 1e9 << endl;
    system("pause");
    system("cls");
}

void delete_Elements()
{
    int amount, pos;
    int old_pos[90000]{};
    cout << "Enter amount of elements to delete : ";
    cin >> amount;
    start = time(0);
    for (int i{}; i < amount; i++)
    {
        pos = rand() % lst.GetSize() + 0;
        lst.removeAt(pos);
        for (int j{}; j < i; j++)
        if(old_pos[j] == pos)
            pos = rand() % lst.GetSize() + 0;
        old_pos[i] = pos;
    }
    stop = time(0);
    cout << "Time of program = " << (stop - start) / 1e9 << endl;
    system("pause");
    system("cls");
}

void output_Elements()
{
    for (int i{}; i < lst.GetSize(); i++)
    {
        cout << i + 1 << ")" << lst[i] << endl;
    }
    system("pause");
}

void menu()
{
    do
    {
        system("cls");
        cout << "1) Add\n2) Delete\n3) Output\nChoice:";
        int choice = _getch();
        switch (choice)
        {
        case '1':
        {
            system("cls");
            add_Elements();
            break;
        }
        case '2':
        {
            system("cls");
            delete_Elements();
            break;
        }
        case '3':
        {
            system("cls");
            output_Elements();
            break;
        }
        default:
        {
            system("cls");
            cout << "Wrong\n";
        }
        }
        cout << "Press Enter to continue\n";
    } while (_getch() == 13);
}
