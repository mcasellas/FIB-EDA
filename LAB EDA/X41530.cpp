#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int > > Graph;

void entrar_elements(Graph& g){
    int x, y;
    cin >> x >> y;
    g[x][y] = 1;
}

bool es_bosc(int n, int m){
    if (m > n-1) return false;
    else return true;
}

int main(){
    
    int n, m;
    
    while(cin >> n >> m){
        
        Graph g (n, vector<int> (n,0));
        
        for (int i = 0; i < m; i++) { // entrem les arestes
            entrar_elements(g);
        }
        
        int ret = es_bosc(n,m);
        
        if (ret == -1) cout << "no" << endl;
        else cout << "si" << endl;
    }
    
}
