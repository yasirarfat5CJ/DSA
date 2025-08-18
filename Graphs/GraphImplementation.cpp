#include <iostream>
#include <list>
using namespace std;

class Graph {
    int v;              // number of vertices
    list<int> *l;       // adjacency list (array of lists)

public:
    // Constructor
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];  // create adjacency list of size v
    }

  
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);  
    }


    void printGraph() {
        for (int i = 0; i < v; i++) {    // loop through each vertex
            cout << i << " -> ";         // print current vertex number
            
            // for each neighbor (nbr) in adjacency list of vertex i
            for (int nbr : l[i]) {
                cout << nbr << " ";      // print the neighbor
            }
            cout << endl;                // move to the next line
        }
    }

    // Destructor (to free memory)
    ~Graph() {
        delete[] l;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency List Representation of Graph:" << endl;
    g.printGraph();

    return 0;
}


/*In this  i  implememted graph 
Graph:It is a network of nodes
here i used adjacency list which is used to store the neighbour vertices 
for every vertex we store it neighbours vertices in the list
as it is an undirected graph so in a single opertion we can able 
to build tow list. */