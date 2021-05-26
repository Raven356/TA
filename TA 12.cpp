#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include <fstream>

using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int* output = new int[n]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
    delete[] output;
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)                        //LSD
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

//MSD
struct node {
    vector<int> arr;
    struct node* nxt[10];
};

// Function to create a new node of
// the Linked List
struct node* new_node(void)
{
    struct node* tempNode = new node;

    for (int i = 0; i < 10; i++) {
        tempNode->nxt[i] = NULL;
    }

    // Return the created node
    return tempNode;
}

// Function to sort the given array
// using MSD Radix Sort recursively
void msd_sort(struct node* root, int exp,
    vector<int>& sorted_arr)
{
    if (exp <= 0) {
        return;
    }

    int j;

    // Stores the numbers in different
    // buckets according their MSD
    for (int i = 0;
        i < root->arr.size();
        i++) {

        // Get the MSD in j
        j = (root->arr[i] / exp) % 10;

        // If j-th index in the node
        // array is empty create and
        // link a new node in index
        if (root->nxt[j] == NULL) {
            root->nxt[j] = new_node();
        }

        // Store the number in j-th node
        root->nxt[j]->arr.push_back(root->arr[i]);
    }

    // Sort again every child node that
    // has more than one number
    for (int i = 0; i < 10; i++) {

        // If root->next is NULL
        if (root->nxt[i] != NULL) {

            if (root->nxt[i]->arr.size()
    > 1) {

                // Sort recursively
                msd_sort(root->nxt[i], exp / 10, sorted_arr);
            }

            // If any node have only
            // one number then it means
            // the number is sorted
            else {
                sorted_arr.push_back(root->nxt[i]->arr[0]);
            }
        }
    }
}

// Function to calculate the MSD of the
// maximum  value in the array
int get_max_exp(vector<int> arr)
{
    // Stores the maximum element
    int mx = arr[0];

    // Traverse the given array
    for (int i = 1; i < arr.size(); i++) {

        // Update the value of maximum
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }

    int exp = 1;

    while (mx > 10) {
        mx /= 10;
        exp *= 10;
    }

    // Return the resultant value
    return exp;
}

// Function to print an array
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << endl;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do
    {
        struct node* root = new_node();
        system("cls");
        int amount_of_chests;
        cout << "Введіть кількість (1 випадок): ";
        cin >> amount_of_chests;
        int* mas = new int[amount_of_chests];
        int* mas1 = new int[amount_of_chests];
        srand(time(0));
        for (int i{}; i < amount_of_chests; i++)
        {
            mas[i] = fmod(rand(), 10000) + 1;
            if (amount_of_chests < 100)
                cout << mas[i] << endl;
            mas1[i] = mas[i];
            root->arr.insert(root->arr.end(), mas[i]);
        }
        ofstream file1;
        ifstream file;
        cout << "Для 1 випадку:\n";
        int n = amount_of_chests / sizeof(mas[0]);
        double start = clock();
        radixsort(mas1, n);
        double stop = clock();
        cout << "LSD = " << (stop - start) / 1000 << endl;
        start = clock();
        int exp = get_max_exp(root->arr);

        // Stores the sorted numbers
        vector<int> sorted_arr;

        // Function Call
        sorted_arr.clear();
        msd_sort(root, exp, sorted_arr);
        stop = clock();
        cout << "MSD = " << (stop - start) / 1000 << endl;
        print(mas1,n);
        file1.open("File1.txt", ios_base::out);
        for (int i{}; i < amount_of_chests; i++)
        {
            file1 << mas1[i] << "\n";
        }
        file1.close();
        delete[] mas;
        delete[] mas1;

        int new_chests;
        cout << "\nВведіть кількість (2 випадок): ";
        cin >> new_chests;
        mas = new int[amount_of_chests + new_chests];
        mas1 = new int[amount_of_chests + new_chests];
        file.open("File1.txt", ios_base::in);
        for (int i{}; i < amount_of_chests; i++)
        {
            file >> mas[i];
            mas1[i] = mas[i];
            root->arr.insert(root->arr.end(), mas[i]);
        }
        file.close();
        for (int i{ amount_of_chests }; i < amount_of_chests + new_chests; i++)
        {
            mas[i] = fmod(rand(), 10000) + 1;
            if (new_chests < 100)
                cout << mas[i] << endl;
            mas1[i] = mas[i];
            root->arr.insert(root->arr.end(), mas[i]);
        }
        amount_of_chests += new_chests;

        cout << "Для 2 випадку:\n";
        n = amount_of_chests / sizeof(mas[0]);
        start = clock();
        radixsort(mas1, n);
        stop = clock();
        cout << "LSD = " << (stop - start) / 1000 << endl;
        start = clock();
        exp = get_max_exp(root->arr);

        // Stores the sorted numbers

        // Function Call
        sorted_arr.clear();
        msd_sort(root, exp, sorted_arr);
        stop = clock();
        cout << "MSD = " << (stop - start) / 1000 << endl;
        print(mas1, n);
        file1.open("File1.txt", ios_base::out);
        for (int i{}; i < amount_of_chests; i++)
        {
            file1 << mas1[i] << "\n";
        }
        file1.close();
        delete[] mas;
        delete[] mas1;
        cout << "\nВведіть кількість (3 випадок): ";
        cin >> new_chests;
        mas = new int[amount_of_chests + new_chests];
        mas1 = new int[amount_of_chests + new_chests];
        file.open("File1.txt", ios_base::in);
        for (int i{}; i < amount_of_chests; i++)
        {
            file >> mas[i];
            mas1[i] = mas[i];
            root->arr.insert(root->arr.end(), mas[i]);
        }
        file.close();
        for (int i{ amount_of_chests }; i < amount_of_chests + new_chests; i++)
        {
            mas[i] = fmod(rand(), 10000) + 1;
            if (new_chests < 100)
                cout << mas[i] << endl;
            mas1[i] = mas[i];
            root->arr.insert(root->arr.end(), mas[i]);
        }
        amount_of_chests += new_chests;

        file1.close();
        cout << "Для 3 випадку:\n";
        n = amount_of_chests / sizeof(mas[0]);
        start = clock();
        radixsort(mas1, n);
        stop = clock();
        cout << "LSD = " << (stop - start) / 1000 << endl;
        start = clock();
        exp = get_max_exp(root->arr);
        // Function Call
        sorted_arr.clear();
        msd_sort(root, exp, sorted_arr);
        stop = clock();
        cout << "MSD = " << (stop - start) / 1000 << endl;
        print(mas1, n);
        file1.open("File1.txt", ios_base::out);
        for (int i{}; i < amount_of_chests; i++)
        {
            file1 << mas1[i] << "\n";
        }
        delete[] mas;
        delete[] mas1;
    } while (_getch() != 27);
}
