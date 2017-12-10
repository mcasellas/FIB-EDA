#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

typedef vector<char> fila;
typedef vector< fila > Matriu;

void entrar_matriu(Matriu& mat, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
}

void imprimir(Matriu mat) {
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << ' ';
            
        }
        cout << endl;
    }
}


int bfs (const Matriu& mat, int px, int py) {
    
    int max = -1;
    
    vector<vector<bool> > visitat (mat.size(), vector<bool>(mat[0].size(),false));
    
    queue<pair<int,int>> Q;
    
    queue<int> dist;
    
    Q.push(make_pair(px, py));
    dist.push(0);
    visitat[px][py] = true;
    
    while (!Q.empty()){
        pair<int, int> act = Q.front();
        
        int x = act.first;
        int y = act.second;
        
        // Esquerra
        if (y > 0 and visitat[x][y-1] == false and mat[x][y-1] != 'X') {
            if (mat[x][y-1] == 't') max = dist.front() + 1;
            Q.push(make_pair(x, y-1));
            dist.push(dist.front() + 1);
            visitat[x][y-1] = true;
        }
        // Dreta
        if (y < mat[0].size() - 1 and visitat[x][y+1] == false and mat[x][y+1] != 'X') {
            if (mat[x][y+1] == 't') max = dist.front() + 1;
            Q.push(make_pair(x, y+1));
            dist.push(dist.front() + 1);
            visitat[x][y+1] = true;
        }
        // Dalt
        if (x > 0 and visitat[x-1][y] == false and mat[x-1][y] != 'X') {
            if (mat[x-1][y] == 't') max = dist.front() + 1;
            Q.push(make_pair(x-1, y));
            dist.push(dist.front() + 1);
            visitat[x-1][y] = true;
        }
        // Sota
        if (x < mat.size() -1 and visitat[x+1][y] == false and mat[x+1][y] != 'X') {
            if (mat[x+1][y] == 't') max = dist.front() + 1;
            Q.push(make_pair(x+1, y));
            dist.push(dist.front() + 1);
            visitat[x+1][y] = true;
        }
        
        Q.pop();
        dist.pop();
        
    }
    
    return max;
}


int main(){
    
    int x, y;
    
    cin >> x >> y;
    
    Matriu mat (x,fila(y));
    entrar_matriu(mat,x,y);
    //imprimir(mat);
    
    cin >> x >> y;
    
    int res = bfs(mat, x-1, y-1);
    
    if (res < 0) cout << "no es pot arribar a cap tresor" << endl;
    else cout << "distancia maxima: " << res << endl;
    
    
}
