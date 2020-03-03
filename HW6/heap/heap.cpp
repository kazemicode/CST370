/*
 * Title: heap.cpp
 * Abstract: Implements heap operations using the bottom-up heap construction algorithm
 * Creates a heap based on a set of numbers supplied from a user
 * Name: Sara Kazemi
 * Date: 02/25/2020
 */

#include <iostream>
using namespace std;

bool heapBottomUp(int arr[], int n)
{
    bool wasHeap = true; // will determine if input was heap originally
    for(int i = n/2; i > 0; i--)
    {
        int k = i;
        int temp = arr[k];
        bool isHeap = false;
        while(!isHeap && 2*k <= n)
        {
            int j = 2*k;
            if(j < n) // 2 children
            {
                if (arr[j] < arr[j + 1]) {
                    j = j + 1; // check biggest child
                }
            }
            if(temp >= arr[j])
            {
                isHeap = true; //this part is heap
            }
            else{
                wasHeap = false; // original input was not a heap!
                // promote child
                arr[k] = arr[j];
                k = j;

            }


        }
        arr[k] = temp; // old parent becomes child
    }
    return wasHeap;

}

void copyArray( int arr[], int target[], int n)
{
    for(int i = 1; i <= n; i++)
    {
        target[i] = arr[i];
    }
}

void printHeap(int arr[], int n)
{
    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void printMenu()
{
    cout << "Select an operation" << endl;
    cout << "1: Insert a number" << endl;
    cout << "2: Delete the max" << endl;
    cout << "3: Heapsort & Quit" << endl;
}

int main() {
    int n; // number of nodes in heap
    int selection; // menu selection
    cout << "Input size: ";
    cin >> n;

    int *arr;
    arr = new int[n+1](); // initialize array of size n+1 to hold input values from user

    cout << "Enter " << n << " numbers: ";
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }


    // Determine if Heap
    if(heapBottomUp(arr, n))
        cout << "This is a heap." << endl;
    else {
        cout << "This is NOT a heap!" << endl;
        cout << "Heap constructed: ";
        printHeap(arr, n);
    }

    // Program loop with menu prompt
    while(selection != 3){
        printMenu();
        cin >> selection;
        if(selection == 1)
        {
            // Insert new value and heapify
            n = n + 1;
            int *temp;
            temp = new int[n+1]();

            // copy existing heap
            copyArray(arr, temp, n);

            // Request new value and insert as next empty leaf
            int newValue;
            cout << "Enter a number: ";
            cin >> newValue;
            temp[n] = newValue;

            // copy
            arr = new int[n+1]();
            copyArray(temp, arr, n);

            heapBottomUp(arr, n);
            cout << "Updated heap: ";
            printHeap(arr, n);

        }
        else if(selection == 2)
        {
            // Delete max key
            int tempValue = arr[n];
            // swap max key with last key
            arr[n] = arr[0];
            arr[1] = tempValue;

            // Decrease heap size by 1
            n = n - 1;

            int *temp;
            temp = new int[n+1]();
            // copy existing heap
            copyArray(arr, temp, n);

            // copy
            arr = new int[n+1]();
            copyArray(temp, arr, n);

            // Heapify smaller tree
            heapBottomUp(arr, n);
            cout << "Updated heap: ";
            printHeap(arr, n);


        }
    }
    // Heapsort and Bye!
    cout << "Heapsort: ";
    printHeap(arr, n);
    cout << "Bye!";


    return 0;
}
