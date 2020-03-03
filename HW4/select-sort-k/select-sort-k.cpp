/*
 * Title: select-sort-k
 * Abstract: Modified Selection Sort that sorts the first k smallest elements of the array with n elements
 * (k <= n, the value of k is entered by the user)
 * ID: 4444
 * Name: Sara Kazemi
 * Date: 02/04/2020
 */

#include <iostream>
#include <fstream>  // std::ifstream
#include <sstream>
#include <new>      // for dynamic arrays
using namespace std;

void selectSortK(int arr[], int length, int k){
    int min;
    int temp;
    for(int i = 0; i < length - 1; i++)
    {
        min = i;
        for(int j = i+1; j < length ; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
            // Swap arr[i] and arr[min]
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    for(int i = 0 ; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";


}

int main() {
    int *values;   // array pointer
    int length = 0; // length of array tbd by first value in file

    // get the input file as a string
    string inputFile;
    int k;
    cout << "Enter input file name: ";
    cin >> inputFile;
    cout << "Enter the value k: ";
    cin >> k;

    // open file if it exists, otherwise print
    // that we are unable to open it
    ifstream myfile(inputFile);
    if (myfile.is_open()) {
        // get the first value in the file to determine length of array
        string s;
        getline(myfile, s);
        stringstream word(s);
        word >> length;
        values = new int[length];

        // read remaining values from file and store in array
        int index = 0; // array index position
        int value;     // temp storage for each value in file
        while (index < length && myfile >> value) {
            values[index++] = value;
        }

        myfile.close(); // done with file -- close

        selectSortK(values, length, k);
        return 0;
    }
}
