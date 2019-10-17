#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;
bool circle = false;
bool chk = false;
class Graph{
public:
    int V;
    list<int> path;
    vector< list< int > > adj;
    Graph(int V);
    void Edge(int u, int v);
    void topologicalSort();
    void visited(int node, queue<int> &topoSort, int marked[]);
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
    }
}

void Graph::topologicalSort(){
    queue<int> topoSort;
    int marked[V+1] = {};
    for (int i=0; i<V+1; i++){ // initial marked
        marked[i] = -1;
    }
    for (int i=1; i<V+1; i++){
        if (marked[i] == -1 ) {
            visited(i, topoSort, marked);
        }
    }
    if (circle == true) {
        cout << "-1" << endl;
    }else{
        while(topoSort.size() >1){
            cout << topoSort.front() << " ";
            topoSort.pop();
        }
        cout << topoSort.front() << endl;
    }
}

void Graph::visited(int node, queue<int> &topoSort, int marked[]){
    if (marked[node] == -1){
        marked[node] = 0;
    } else if (marked[node] == 0){
        circle = true;
        return;
    }else{
        return;
    }
    if (adj[node].empty()){ // empty
        topoSort.push(node);
        chk = true;
        marked[node] = 1;

        for (int l=1; l<adj.size(); l++){
            for (list<int>::iterator m =adj[l].begin(); m != adj[l].end(); ++m){
                if (*m == node){
                    adj[l].erase(m);
                    break;
                }
            }
        }
    }else{ // not empty
        visited(adj[node].front(), topoSort, marked);
        if (chk == true)
            marked[node] = -1;
        chk = false;
        visited(node, topoSort, marked);
    }
}

int main()
{
    while(true){
        int N, M;
        circle = false;
        cin >> N >> M;
        if (N == 0 && M == 0){
            break;
        }
        if (N<1 || N>1000 || M>100000){
            cout << "-1" << endl;
            continue;
        }

        int u, v;
        Graph g(N);
        while(M--){
            cin >> u >> v;
            g.Edge(u, v);
        }
        g.topologicalSort();

    }
    return 0;
}