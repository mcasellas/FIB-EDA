#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> arcP; // y i cost
typedef vector<vector<arcP>> Graf;

void entrar_graf(Graf& G, int m){
    
    int x, y, pes;
    
    for (int i = 0; i < m; i++){
        cin >> x >> y >> pes;
        G[x].push_back(make_pair(y, pes));
    }
}


int dijkstra(const Graf G, int u, int v){
    
    int n = int(G.size());
    
    vector<int> cost (n, -1);
    vector<bool> visitat (n, false);
    
    priority_queue<arcP, vector<arcP>, less<arcP>> Q;
    
    Q.push({u,0});
    cost[u] = 0;
    
    while (not Q.empty()){
        int act = Q.top().first;
        Q.pop();
        
        if (not visitat[act]){
            visitat[act] = true;
            
            for (int i = 0; i < int(G[act].size()); i++){
                int c = G[act][i].second;
                int nou_node = G[act][i].first;
                
                if (cost[nou_node] == -1 or cost[nou_node] > cost[act] + c) {
                    cost[nou_node] = cost[act] + c;
                    
                    Q.push({nou_node, cost[nou_node]});
                }
            }
        }
    }
    return cost[v];
    
}

int main(){
    
    int n, m;
    
    while (cin >> n >> m){
        Graf G (n);
        
        entrar_graf(G, m);
        
        int u,v;
        cin >> u >> v;
        int ret = dijkstra(G, u, v);
        
        if (ret < 0) cout << "no path from " << u << " to " << v << endl;
        else cout << ret << endl;
    }
    
}
