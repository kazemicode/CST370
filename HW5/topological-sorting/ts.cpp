/*
 * Title: ts.cpp
 * Abstract: Implements the topological sorting algorithm
 * based on the source-removal algorithm
 * Name: Sara Kazemi
 * Date: 02/10/2020
 */

#include <iostream>
#include <fstream>  // std::ifstream
#include <sstream>
#include <vector>
using namespace std;

void ts(vector<vector<int>> adjacency, vector<int> indegrees) {
    // keep track of deleted vertices, which will be the solution
    vector<int> solution;
    // check if vertex is a source -- i.e. in-degree of 0
    for (int row = 0; row < indegrees.size(); row++) {
        if (indegrees[row] == 0) {
            // add vertex to solution
            solution.push_back(row);
            // Mark vertex as deleted
            indegrees[row] = -1;
            // Traverse column in adjacency matrix to identify edges for deletion
            for (int col = 0; col < adjacency.size(); col++) {
                if (adjacency[row][col] == 1) {

                    // decrease in-degree by 1
                    indegrees[col] = indegrees[col] - 1;
                }
            }
            // start from beginning vertex again
            row = -1; // for loop will increment to row 0
        }
    }

    // Print out results
   cout << "Topological Order: " ;
    for (int i = 0; i < solution.size() - 1; i++) {
        cout << solution[i] << " -> ";
   }
    cout << solution[solution.size() - 1] << endl;


}
int main() {

    int vertices; // number of vertices indicated by first value in file

    // get the input file as a string
    string inputFile;
    cout << "Enter input file name: ";
    cin >> inputFile;

    // open file if it exists, otherwise print
    // that we are unable to open it
    ifstream myfile(inputFile);
    if (myfile.is_open()) {
        // get the first value in the file to determine length of array
        string s;
        getline(myfile, s);
        stringstream word(s);
        word >> vertices;

        // Create Adjacency Matrix from input
        vector<vector<int>> adjacency(vertices);
        for(int i = 0; i < vertices; i++)
        {
            adjacency[i].resize(vertices);
            // read remaining values from file and store in vector
            int index = 0; // array index position
            int value;     // temp storage for each value in file
            while (index < vertices && myfile >> value) {
                adjacency[i][index++] = value;
            }

        }

        // Create list of in-degrees for vertices
        vector<int> indegrees(vertices);
        for(int col = 0; col < vertices; col++){
            for (int row = 0; row < vertices; row++)
            {
                if(adjacency[row][col] == 1)
                {
                    indegrees[col] = indegrees[col] + 1;
                }
            }
        }

        myfile.close(); // done with file -- close
        ts(adjacency, indegrees);


    }
    return 0;
}
