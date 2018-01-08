#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef pair<int,int> arcP;
typedef vector<vector<arcP>> Graf;

void entrar_graf(Graf& G, int m){
    for (int i = 0; i < m; i++){
        int x, y, p;
        cin >> x >> y >> p;
        G[x].push_back({p, y});
    }
}


void dijkstra (const Graf& G, int x, int y){
    
    int n = int(G.size());
    
    vector<int> distancia (n, numeric_limits<int>::max());
    vector<bool> visitat (n,false);
    vector<int> recorregut (n,-1);
    priority_queue<arcP, vector<arcP>, greater<arcP>> Q;
    
    Q.push({0,x});
    distancia[x] = 0;
    
    while (not Q.empty() and Q.top().second != y){
        int act = Q.top().second;
        Q.pop();
        
        if (not visitat[act]){
            visitat[act] = true;
            
            for (int i = 0; i < G[act].size(); i++){
                int nou_node = G[act][i].second;
                int c = G[act][i].first;
                
                if (distancia[nou_node] > distancia[act] + c){
                    distancia[nou_node] = distancia[act] + c;
                    
                    recorregut[nou_node] = act;
                    
                    Q.push({distancia[nou_node], nou_node});
                }
            }
        }
    }
    
    if (Q.empty()){
        cout << "no path from " << x << " to " << y << endl;
        return;
    }
    
    stack<int> resultat;
    
    while (recorregut[y] != -1){
        resultat.push(y);
        y = recorregut[y];
    }
    
    cout << resultat.top();
    resultat.pop();
    
    while (not resultat.empty()){
        cout << ' ' << resultat.top();
        resultat.pop();
    }
    
    cout << endl;
}


int main(){
    
    int n, m;
    
    while (cin >> n >> m){
        
        Graf G (n);
        entrar_graf(G,m);
        
        int x, y;
        
        cin >> x >> y;
        dijkstra(G, x, y);
    }
    
    
}
