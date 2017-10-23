#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;

Matriu multiplicar(const Matriu &m1, const Matriu &m2, int m){
    
    Matriu aux (2, vector<int> (2));
   
    aux[0][0] = ((m1[0][0]*m2[0][0])%m + (m1[0][1]*m2[1][0])%m)%m;
    aux[0][1] = ((m1[0][0]*m2[0][1])%m + (m1[0][1]*m2[1][1])%m)%m;
    aux[1][0] = ((m1[1][0]*m2[0][0])%m + (m1[1][1]*m2[1][0])%m)%m;
    aux[1][1] = ((m1[1][0]*m2[0][1])%m + (m1[1][1]*m2[1][1])%m)%m;

    return aux;
}

Matriu exponencial(const Matriu &M, int n, int m){
    
    Matriu aux (2, vector<int> (2));
    
    
    if (n == 0) {
        aux[0][0] = aux[1][1] = 1;
        aux[1][0] = aux[0][1] = 0;
        
        return aux;
    }
    
    else {
        aux  = exponencial(M, n/2, m);
        if (n%2 == 0) {
            aux = multiplicar(aux, aux, m);
            return aux;
        }
        
        else {
            aux = multiplicar(aux, aux, m);
            aux = multiplicar(aux, M, m);
            return aux;
        }
    }
}


int main() {
    

    
    Matriu matriu = {{0,1},{1,1}};
    
    int n,m;
    
    while (cin >> n >> m) {
    
        cout << exponencial(matriu, n, m)[0][1] << endl;
        
    }
 
}

