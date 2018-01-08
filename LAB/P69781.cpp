// Pseudo-seqüències de Collatz (2)

#include <iostream>
#include <map>
using namespace std;

int main() {
    
    int x, y, n;
    
    while (cin >> x >> y >> n) {
        
        map<int, int> m;
        
        bool trobat = false;
        int cont = 0;
        
        m[n] = cont;
        
        map<int,int>::iterator it;
        
        while (n <= 100000000 and not trobat){
            ++cont;
            
            if (n%2 == 0) n = n/2 + x; //n parell
            else n = 3*n + y; // senar
            
            it = m.find(n);
            
            if (it != m.end()) trobat = true;
            else m[n] = cont;
        }
        
        if (trobat) cout << m.size() - it->second << endl;
        else cout << n << endl;
        
    }
}


