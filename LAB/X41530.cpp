#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int > > Graph;

void entrar_elements(Graph& g, int n, int m){
    
    g = Graph (n);
    
    int x, y;
    for (int j = 0; j < m; j++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void buscar_cicles (const Graph& g, vector<bool>& visitats, int i, int antecessor, bool& cicle) {
    if (!visitats[i]) {
        visitats[i] = true;
        
        for (int j = 0; j < g[i].size(); j++){ // Adjacents de cada node
            if (g[i][j] != antecessor){ // Diferent del node de partida
                buscar_cicles(g, visitats, g[i][j], i, cicle);
                if (cicle) return;
            }
        }
    }
    
    else cicle = true;
}

void dfs(const Graph& g){
    
    vector<bool> visitats(g.size(), false); // Graf de nodes visitats
    
    int narbres = 0; // nº arbres trobats
    
    for (int i = 0; i < g.size(); i++){ // Anem visitant node a node
        if (!visitats[i]) {
            bool cicle = false;
            buscar_cicles(g, visitats, i, i, cicle);
            
            if (cicle) {
                cout << "no" << endl;
                return;
            }
            
            else ++narbres;
        }
    }
    cout << narbres << endl;
}

int main(){
    
    int n, m;
    
    while(cin >> n >> m){
        Graph g (n, vector<int> (n,0));
        
        entrar_elements(g,n,m);
        
        dfs(g);
    }
    
}
