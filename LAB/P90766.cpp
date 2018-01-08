#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char valor;
    bool visitat = false;
};

typedef vector< vector<Node > > Graph;

int buscar_dfs(int x, int y,Graph& g){
    
    int res = 0;
    
    if (!g[x][y].visitat){
        g[x][y].visitat = true;
        if (g[x][y].valor == 't') {
            ++res;
        }
        
        if (g[x][y].valor != 'X'){
            if (y != g[0].size() - 1) res += buscar_dfs(x, y+1, g);
            if (x != g.size() - 1) res += buscar_dfs(x+1, y, g);
            if (y != 0) res += buscar_dfs(x, y-1, g);
            if (x != 0) res += buscar_dfs(x-1, y, g);
        }
    }
    
    return res;

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
    
    cout << buscar_dfs(x-1,y-1,mapa) << endl;
    
}
