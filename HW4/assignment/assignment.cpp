/*
 * Title: assignment.cpp
 * Abstract: Identifies the lowest cost assignment of n jobs to n people
 * ID: 4444
 * Name: Sara Kazemi
 * Date: 02/04/2020
 */

#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main() {
    int n; // to store number of jobs
    cout << "Enter number of jobs: ";
    cin >> n;
    vector<vector<int>> assignments(n); // vector to hold assignments
    int permutations[n]; // use array for permutations of job assignments
    int solution[n]; // Stores the  permutation for the solution
    for (int i = 0; i < n; i++) // populate array with 0...n-1
    {
        permutations[i]=i;
    }

    // populate vector with assignment costs per person
    cout << "Enter assignment costs of " << n << " persons: \n";
    for(int i=0; i < n; i++) {
        cout << "Person " << i + 1 << ": ";
        assignments[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> assignments[i][j];
        }
    }

    // determine assignment permutations
    int lowestCost = numeric_limits<int>::max();
    int bestSolution[n];
    int counter = 1;
    do {
        int cost = 0;
        for(int i = 0; i < n; i++){
            if(i==0){
                cout << "Permutation " << counter << ": ";
                counter = counter+1;
            }
            cost = cost + assignments[i][permutations[i]];
            cout << assignments[i][permutations[i]] << ' ';
            solution[i] = assignments[i][permutations[i]];
        }
        cout << "=> total cost: " << cost << "\n";
        if (cost < lowestCost)
        {
            lowestCost = cost; // copy best cost so far
            copy(solution, solution+n, bestSolution); // copy best solution so far
        }
    } while ( next_permutation(permutations,permutations+n) );

    // Display solution and cost
    cout << "Solution: ";
    for(int i = 0; i < n; i++)
    {
        cout << bestSolution[i] << " ";
    }
    cout << " => total cost: " << lowestCost;
    return 0;
}
