#include <iostream>
#include <vector>
using namespace std;

void escriure(vector<int>& v){
    if (v.size() != 0){
        cout << v[0];
        for (int i = 1; i < v.size(); i++){
            cout << ' ' << v[i];
        }
    }
    cout << endl;
}

void zerosiuns(int i, vector<int> v, int maxuns, int z, int u){
    if (i == v.size()){
        escriure(v);
    }
    
    else {
        v[i] = 0;
        if (z < v.size()-maxuns) zerosiuns(i+1, v, maxuns, z+1, u);
        v[i] = 1;
        if (u < maxuns) zerosiuns(i+1, v, maxuns, z, u+1);
    }
}

int main(){
    
    int n, num;
    
    cin >> n >> num;
    
    vector<int> v (n);
    
    zerosiuns(0, v, num, 0, 0);
    
}
