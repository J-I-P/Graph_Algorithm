#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
public:
    int V;
    list<int> path;
    vector< list< int > > adj;
    Graph(int V);
    void Edge(int u, int v);
};

Graph::Graph(int V){
    this->V = V;
    adj.assign( V+1, path);
}

void Graph::Edge(int u, int v){
    bool chkexist = false;
    for (list<int>::iterator m =adj[v].begin(); m != adj[v].end(); ++m){
        if (*m == u){
            chkexist = true;
            break;
        }
    }
    if (chkexist ==false){
        adj.at(v).push_back(u);
        adj.at(u).push_back(v);
    }
}

int main() {
    int N=0, M=0;
    cin >> N >> M;

    if (N<1 || N>1000 || M>100000){
       cout << "0" << endl;
       return 0;
    }

    for (int i=1; i<=N; i++){
        
    }
    return 0;
}