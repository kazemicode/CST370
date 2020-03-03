/*
 * Title: prim.cpp
 * Abstract: Implements Prim's algorithm to calculate the MST from
 * an input graph
 * Name: Sara Kazemi
 * Date: 02/25/2020
 */
#include <iostream>
#include <fstream>  // std::ifstream
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

class Edges{
public:
int source;
int destination;
int cost;

Edges(int c, int s, int d){
    cost = c;
    source = s;
    destination = d;

}


void printEdge()
{
    cout << "New edge: " << source << ',' << destination << " - " << "cost: " << cost << endl;
}
};

// this is an structure which implements the
// operator overloading
struct CompareCost {
    bool operator()(Edges const& e1, Edges const& e2)
    {
        // return "true" if "e1" is ordered
        // before "e3", for example:
        return e1.cost > e2.cost;
    }
};

void Prim(vector<Edges> graph, int start, int vertices){
    int mstCost = 0;
    vector<int> V;



    priority_queue<Edges, vector<Edges>, CompareCost> Q;
    Q.push(Edges(0, 0, start));

    while(!Q.empty())
    {

        // Keep track of vertices already added to the MST
        V.push_back(start);


        // get rid of stuff in the queue that has destinations we've already visited
        while(!Q.empty() && count(V.begin(), V.end(), Q.top().destination) && (count(V.begin(), V.end(), Q.top().source) || Q.top().source ==  0))
        {
            Edges x = Q.top();
            //cout << "removing: ";
            //x.printEdge();
            Q.pop();

        }



        // Determine next cheapest edge
        for(int i = 0; i < graph.size(); i++){

            bool partOfTree = graph[i].source == start || graph[i].destination == start;
            bool unVisited = !count(V.begin(), V.end(), graph[i].destination) || !count(V.begin(), V.end(), graph[i].source);
            if(partOfTree && unVisited) {

                Q.push(graph[i]); // push edge to priority queue
            }
        }
        Edges temp = Q.top();

        if(!count(V.begin(), V.end(), temp.destination) || !count(V.begin(), V.end(), temp.source)){
            mstCost = mstCost + temp.cost;
            temp.printEdge();
        }

        if(start == temp.source){
            start = temp.destination;
        }
        else{
            start = temp.source;
        }

    }
    cout << "Total cost of MST: " << mstCost << endl;


}

int main() {
    int vertices; // number of vertices indicated by first value in file
    int edges; // number of edges indicated by 2nd value in file

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
        getline(myfile, s);
        stringstream word2(s);
        word2 >> edges;


        // Create graph
        vector<Edges> graph;
        for(int i = 0; i < edges; i++)
        {
            // read remaining values from file and store in vector
            int index = 0; // array index position
            int value;     // temp storage for each value in file
            int source, destination, cost;
            while (index < 3 && myfile >> value) {
                if(index == 0)
                {
                    source = value;
                }
                else if(index == 1)
                {
                    destination = value;
                }
                else{
                    cost = value;
                }
                index = index + 1;

            }
            graph.push_back(Edges(cost, source, destination));
        }


        // Prompt user for starting vertex
        int start; // to store number of jobs
        cout << "Enter the starting vertex: ";
        cin >> start;

       Prim(graph, start, vertices);

    }
    return 0;

}