#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char valor;
    bool visitat = false;
};

typedef vector< vector<Node > > Graph;


bool buscar_dfs(int x, int y,Graph& g){
    
    if (!g[x][y].visitat){
        g[x][y].visitat = true;
        if (g[x][y].valor == 't') return true;
        
        else if (g[x][y].valor != 'X'){
            bool res = false;
            if (y != g[0].size() - 1) res = buscar_dfs(x, y+1, g);
            if (!res and x != g.size() - 1) res = buscar_dfs(x+1, y, g);
            if (!res and y != 0) res = buscar_dfs(x, y-1, g);
            if (!res and x != 0) res = buscar_dfs(x-1, y, g);
            return res;
        }
    }
    
    return false;
}

void entrar_elements(int x, int y,Graph& mapa){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++) {
            cin >> mapa[i][j].valor;
        }
    }
}

int main(){
    
    int midax, miday;
    cin >> midax >> miday;
    
    Graph mapa (midax, vector<Node> (miday));
    entrar_elements(midax, miday, mapa);
    
    int x,y;
    cin >> x >> y;
    
    bool result = buscar_dfs(x-1,y-1,mapa);
    
    if (result) cout << "yes" << endl;
    else cout << "no" << endl;
    
}
