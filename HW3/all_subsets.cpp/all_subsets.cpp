/*
 * Title: all_subsets.cpp
 * Abstract: Identifies and prints out every subset in the powerset of a given set
 * ID: 4444
 * Name: Sara Kazemi
 * Date: 01/21/2020
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<char>> getPowerset(char arr[], int n)
{

    int numSets = pow(2,n);
    vector<vector<char>> powerset(numSets);
    // A set size n will have 2^n subsets, so the outer loop runs 2^n times
    // i acts as a binary counter
    for (int i = 0; i < numSets; i++)
    {
        powerset[i] = vector<char>();
        // The max size of a subset of set size n is n, so the inner loop runs n times
        // This loop generates a subset
        for (int j = 0; j < n; j++)
        {
            // Is the jth bit in binary representation of i set to 1?
            // Yes? include arr[j] in the current subset
            // No? exclude arr[j]
            if ((i & (1 << j)) > 0) {
                powerset[i].push_back(arr[j]);
            }
        }
    }
    return powerset;
}

int main()
{
    int n; // number of characters in set
    cout << "Number of input characters: ";
    cin >> n;

    char arr[n]; // initialize array of size n to hold input characters from user
    cout << "Enter " << n << " characters: ";
    for(int i=0; i < n; i++)
        cin >> arr[i];

    // get the powerset
    vector<vector<char>> powerset = getPowerset(arr, n);

    // sort subsets in powerset by size
    sort(powerset.begin(), powerset.end(), [](const vector<char> & a, const vector<char> & b){ return a.size() < b.size(); });

    // output subsets in powerset to terminal
    for(int i = 0; i < powerset.size(); i++)
    {
        cout << "{";
        for(int j = 0; j < powerset[i].size(); j++)
        {
            cout << powerset[i][j];
            if(j != powerset[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "}\n";
    }

    return 0;
}

