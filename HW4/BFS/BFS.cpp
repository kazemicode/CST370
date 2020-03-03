/*
 * Title: BFS.cpp
 * Abstract: Implements Breadth-First Search using an adjacency matrix and a starting
 * vertex input by the user. Outputs the list of vertices visited.
 * ID: 4444
 * Name: Sara Kazemi
 * Date: 02/04/2020
 */

#include <iostream>
#include <fstream>  // std::ifstream
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> adjacency, int vertices, int start){
    // keep track of visited vertices, initially filled with 0s
    vector<int> visited(vertices);
    vector<int> vertexOrder;

    int count = 0;
    for(int i = start; i < vertices; i++)
    {
        if(visited[i] == 0)
        {
            // increase count -- this will indicate the order in which
            // a vertex is visited
            count = count + 1;
            visited[i] = count;
            vertexOrder.push_back(i);
            // initiate a queue, initialized with vertex
            queue<int> myqueue;
            myqueue.push(i);


            while (!myqueue.empty())
            {
                // for each vertex adjacent to front vertex do:
                for(int j = 0; j < vertices; j++)
                {
                    // if adjacent and unvisited
                    // mark vertex with count in visited
                    // and push vertex onto queue
                    if(adjacency[i][j] == 1 && visited[j] == 0)
                    {
                        count = count + 1;
                        visited[j] = count;
                        vertexOrder.push_back(j);
                        myqueue.push(j);
                    }
                }
                myqueue.pop(); // remove front vertex from queue
            }
        }
    }


    // Print out results
    cout << "BFS Order: ";
    for(int i = 0; i < vertices-1; i++)
    {
        cout << vertexOrder[i] << " -> ";
    }
    cout << vertexOrder[vertices-1] << endl;



}
int main() {

    int vertices; // number of vertices indicated by first value in file
    int start;    // starting vertex input by user

    // get the input file as a string
    string inputFile;
    cout << "Enter input file name: ";
    cin >> inputFile;
    cout << "Enter a start vertex: ";
    cin >> start;

    // open file if it exists, otherwise print
    // that we are unable to open it
    ifstream myfile(inputFile);
    if (myfile.is_open()) {
        // get the first value in the file to determine length of array
        string s;
        getline(myfile, s);
        stringstream word(s);
        word >> vertices;
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

        myfile.close(); // done with file -- close
        bfs(adjacency, vertices, start);

        return 0;
    }
}
