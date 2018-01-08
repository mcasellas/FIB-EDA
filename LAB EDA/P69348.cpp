#include <iostream>
#include <vector>
using namespace std;

void escriure(vector<int>& v){
    if (v.size() != 0){
        cout << '(' << v[0];
        for (int i = 1; i < v.size(); i++){
            cout << ',' << v[i];
        }
    }
    cout << ')' << endl;
}

void permutacions (int i, vector<int>& v, vector<bool>& utilitzats){
    int n = int(v.size());
    
    if (i == n) escriure(v);
    
    else {
        for (int j = 0; j < n; j++){
            if (not utilitzats[j]){
                utilitzats[j] = true;
                v[i] = j+1;
                permutacions(i+1, v, utilitzats);
                utilitzats[j] = false;
            }
        }
    }
}

int main(){
    
    int n;
    
    cin >> n;
    
    vector<int> v (n);
    vector<bool> utilitzats (n, false);
    
    permutacions(0,v,utilitzats);
    
}
