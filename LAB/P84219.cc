#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre){
    
    int mig = (dre-esq)/2 + esq;
    
    if (esq > dre) return -1;
    if (esq == dre) {
        if (v[esq] == x) return esq;
        else return -1;
    }
    
    if (v[mig+1] == x) return mig+1;
    else if (v[mig+1] < x) return posicio(x,v,mig+2,dre);
    else return posicio(x,v,esq,mig);
}

int first_occurrence(double x, const vector<double>& v) {
    
    
    
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}
