#include <iostream>
#include <vector>
using namespace std;

int buscar (vector<int>& S, int esq, int dre, int a) {
    
    if (esq > dre) return -1; // Error o són iguals
    
    else {
        int mig = (dre+esq)/2;
        
        if (S[mig]+a == mig+1 and (mig == 0 or mig != S[mig-1]+a)) return mig+1;
        else if (S[mig]+a < mig+1) return buscar(S, mig+1, dre, a);
        else return buscar(S, esq, mig-1, a);
    }
}


int main() {
 
    int contador = 0, midav;
    
    while(cin >> midav){
        
        cout << "Sequence #" << ++contador << endl;
    
        vector<int> v(midav);
        for (int i  = 0; i < midav; i++) cin >> v[i]; //Entrem elements al vector
        
        int nbuscar;
        
        cin >> nbuscar;
        
        for (int i = 0; i < nbuscar; i++){
            int a;
            cin >> a;
            
            int resultat = buscar(v, 0, v.size()-1, a);
            
            if (resultat != -1) cout << "fixed point for " << a << ": " << resultat << endl;
            else cout << "no fixed point for " << a << endl;
            
            
        }
        
        cout << endl;
    }
    
    
}

