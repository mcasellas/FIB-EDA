#include <iostream>
using namespace std;


int exponenciacio (int n, int k, int m) {
    
    if (k == 0) return 1;
    
    else {
        int aux = exponenciacio(n, k/2, m)%m;
        
        if (k%2 == 0) return (aux*aux)%m;
        else return (((aux*aux)%m)*n)%m;
    }
    
    
}


int main() {
    
    int n;
    
    while(cin>>n) {
        int k, m;
        
        cin >> k >> m;
        
        cout << exponenciacio(n, k, m) << endl;
        
    }

    
    
    

}

