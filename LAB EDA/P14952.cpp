#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

typedef vector< vector<int > > Graph;

void entrar_elements(Graph& g, int n, int m){
    
    g = Graph (n);
    
    int x, y;
    for (int j = 0; j < m; j++) {
        cin >> x >> y;
        g[x].push_back(y);
        
    }
}

list<int> ordenacio_topologica (Graph& G) {
    int n = int(G.size());
    priority_queue<int, vector<int>, greater<int>> cua;
    
    vector<int> ge(n, 0);
    
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < G[u].size(); ++i) {
            ++ge[G[u][i]];
        }
        
    }

    for (int u = 0; u < n; ++u) {
        if (ge[u] == 0) {
            cua.push(u);
        }
        
    }
    list<int> L;
    while (not cua.empty()) {
        int u = cua.top(); cua.pop();
        L.push_back(u);
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            if (--ge[v] == 0) {
                 cua.push(v);
            }
        }
        
    }
    return L;
    
}

void imprimir (list<int>& l){
    if (!l.empty()) {
        cout << l.front();
        l.pop_front();
    }
    while (!l.empty()) {
        cout << ' ' << l.front();
        l.pop_front();
    }
    
   
}
    

int main(){
    
    int n, m;
    
    while(cin >> n >> m){
        Graph g (n, vector<int> (n,0));
        
        entrar_elements(g,n,m);
        
        list<int> l = ordenacio_topologica(g);
        
        imprimir(l);
        
        cout << endl;
        
    }
    
}
