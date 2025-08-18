#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int v;                    
    vector<list<int>> adj;    

public:
    Graph(int v) {
        this->v = v;
        adj.resize(v);
    }

    void addEdge(int u, int w) {
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    void printGraph() {
        for (int i = 0; i < v; i++) {
            cout << i << " -> ";
            for (int nbr : adj[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }

    vector<list<int>>& getAdjList() {
        return adj;
    }

    int getVertices() {
        return v;
    }
};

//
vector<int> bfs(vector<list<int>>& adj, int v) {
    vector<int> visited(v, 0);   
    vector<int> bfsOrder;     
    
    for (int start = 0; start < v; start++) {
        if (!visited[start]) {
            queue<int> q;
            q.push(start);
            visited[start] = 1;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                bfsOrder.push_back(curr);

                for (auto &nbr : adj[curr]) {
                    if (!visited[nbr]) {
                        visited[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
        }
    }
    return bfsOrder;
}

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 5);  // disconnected component

    cout << "Adjacency List:" << endl;
    g.printGraph();

    cout << "\nBFS traversal of entire graph: ";
    vector<int> order = bfs(g.getAdjList(), g.getVertices());

    for (int node : order) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
/*BFS taversal of the graph
in  bfs traversal we visit a node and explore all its adjacent vertices
to implement bfs we use data structures queue and visited arr  the node 
which we visited will be marked as 1  on every iteration we push a vertex  into the
queue and we will travese q until it becomes empty in the  while loop 
we pop element from queue and add the neighbours of curr vertex in the queue using adjacency list*/