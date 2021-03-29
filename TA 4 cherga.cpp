#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

struct queue_item {
	int number;
	queue_item* next;
};
class Queue {
private:
	queue_item* LAST;
	queue_item* FIRST;
	int count;
public:
	Queue() {
		LAST = NULL;
		FIRST = NULL;
		count = 0;
	}
	void push(int item) {
		using namespace std;
		queue_item* new_item = new queue_item;
		new_item->number = item;
		new_item->next = NULL;
		if (LAST != NULL) {
			LAST->next = new_item;
		}
		LAST = new_item;
		if (FIRST == NULL)
			FIRST = new_item;
		count++;
	}
	void pop() {
		using namespace std;
		if (count == 1) {
			delete FIRST;
			FIRST = NULL;
			LAST = NULL;
			return;
		}
		else if (!count) {
			return;
		}
		queue_item* old = FIRST;
		FIRST = FIRST->next;
		delete old;
		count--;
	}
	void print() {
		using namespace std;
		queue_item* item = FIRST;
		while (item != NULL) {
			cout << item->number << " ";
			item = item->next;
		}
		cout << endl;
	}
};
class Array {
private:int count;
	   int* array;
public:
	Array() {
		count = 0;
	}
	void push(int number) {
		if (!count) {
			array = new int;
			array[0] = number;
			count++;
		}
		else {
			int* old = array;
			array = new int[++count];
			for (int i = 0; i < count - 1; i++) {
				array[i] = old[i];
			}
			delete[] old;
			array[count - 1] = number;
		}
	}
	void pop() {
		int* old = array;
		array = new int[--count];
		for (int i = 0; i < count; i++) {
			array[i] = old[i + 1];
		}
		delete[] old;
	}
	void print() {
		using namespace std;
		for (int i = 0; i < count; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

void menu();
void quere();
void arrays();

double start, stop;

int main() {
	do
	{
		srand(time(0));
		menu();
		cout << "Press ESC to quite\n";
	} while (_getch() != 27);
	return 0;
}

void menu()
{
	cout << "1) Quere\n2) Arrays\nYour choice\n";
	int ch = _getch();
	switch (ch)
	{
	case '1' :
	{
		quere();
		break;
	}
	case '2' :
	{
		arrays();
		break;
	}
	default:
		cout << "Wrong\n";
		break;
	}
}

void quere()
{
	Queue queue;
	int count{};
	do {
		system("cls");
		cout << "Your queue: ";
		queue.print();
		cout << endl << "Choose action:" << endl;
		cout << "\t1. Add item." << endl;
		cout << "\t2. Remove item." << endl;
		char key;
		do {
			key = _getch();
		} while (key != '1' && key != '2');
		if (key == '1') {
			system("cls");
			cout << "Your queue: ";
			queue.print();
			cout << "Enter amount to add:";
			int amount;
			cin >> amount;
			int item;
			start = time(0);
			for (int i{}; i < amount; i++)
			{
				item = rand();
				queue.push(item);
				count++;
			}
			stop = time(0);
			cout << "Time = " << (stop - start) / 1e20 << endl;
			system("pause");
			cout << "New queue: ";
			queue.print();
		}
		else {
			cout << "Size = " << count << endl;
			cout << "Enter amount to delete:";
			int amount;
			cin >> amount;
			start = time(0);
			for (int i{}; i < amount; i++)
			{
				queue.pop();
				count--;
			}
			stop = time(0);
			cout << "Time = " << (stop - start) / 1e20 << endl;
			system("pause");
			cout << "New queue: ";
			queue.print();
		}
		cout << "Press ESC to quite\n";
	} while (_getch() != 27);
}

void arrays()
{
	Array array1;
	int count{};
	do {
		system("cls");
		cout << "Your queue: ";
		array1.print();
		cout << endl << "Choose action:" << endl;
		cout << "\t1. Add item." << endl;
		cout << "\t2. Remove item." << endl;
		char key;
		do {
			key = _getch();
		} while (key != '1' && key != '2');
		if (key == '1') {
			system("cls");
			cout << "Your queue: ";
			array1.print();
			cout << "Enter amount to add:";
			int amount;
			cin >> amount;
			start = time(0);
			int item;
			for (int i{}; i < amount; i++)
			{
				item = rand();
				array1.push(item);
				count++;
			}
			stop = time(0);
			cout << "Time = " << (stop - start) / 1e20 << endl;
			system("pause");
				cout << "New queue: ";
				array1.print();
			
		}
		else {
			cout << "Size = " << count << endl;
			cout << "Enter amount to delete:";
			int amount;
			cin >> amount;
			start = time(0);
			for (int i{}; i < amount; i++)
			{
				array1.pop();
				count--;
			}
			stop = time(0);
			cout << "Time = " << (stop - start) / 1e20 << endl;
			system("pause");
			cout << "New queue: ";
			array1.print();
		}
		cout << "Press ESC to quite\n";
	} while (_getch() != 27);
}
