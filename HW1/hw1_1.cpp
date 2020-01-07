/*
 * Title: hw1_1.cpp
 * Abstract: Identifies the minimum distance among pairs of integers read from file
 * ID: 4444
 * Name: Sara Kazemi
 * Date: 01/06/2020
 */

#include <iostream> // std::cin, std::cout
#include <fstream>  // std::ifstream
#include <sstream>
#include <new>      // for dynamic arrays
#include <set>
#include <utility>  // pair

using namespace std;

void minDistance(int arr[], int length)
{
    set<pair<int, int>> results;
    sort(arr, arr+length); // sort in increasing order, so we need only compare adjacent pairs
    int minimum = INT_MAX;

    // compare adjacent pairs
    for(int i = 0; i < length-1; i++)
    {
        int distance = abs(arr[i] - arr[i+1]);
        pair <int, int> temp = make_pair(arr[i], arr[i+1]);
        // -for debugging- cout << "Distance between " <<  arr[i] << " and " << arr[i+1] << ": " <<  distance << '\n';
        // If new min is found, clear out our set of pairs and add new one
        if(distance != 0 && distance < minimum){
            minimum = distance;
            results.clear();
            results.insert(temp);
        }
        // if distance matches current minimum, insert the new pair to existing set
        else if(distance == minimum)
        {
            results.insert(temp);
        }
    }
    // Print out the minimum distance
    cout << "Minimum distance: " << minimum << '\n';

    // Iterate through set of pairs with minimum distance and print
    for (auto const &p : results)
    {
        cout << "Two numbers for minimum distance: " << p.first << " and " << p.second << '\n';
    }

}

int main ()
{
    int * values;   // array pointer
    int length = 0; // length of array tbd by first value in file

    // get the input file as a string
    string inputFile;
    cout << "Enter input file name: ";
    cin >> inputFile;

    // open file if it exists, otherwise print
    // that we are unable to open it
    ifstream myfile(inputFile);
    if (myfile.is_open())
    {
        // get the first value in the file to determine length of array
        string s;
        getline(myfile, s);
        stringstream word(s);
        word >> length;
        values = new int[length];

        // read remaining values from file and store in array
        int index = 0; // array index position
        int value;     // temp storage for each value in file
        while( index < length && myfile >> value)
        {
            values[index++] = value;
        }

        myfile.close(); // done with file -- close
        minDistance(values, length);    // find minimum distance and pairs of ints with this distance
        delete[] values;
    }

    else cout << "Unable to open file";
    return 0;
}



