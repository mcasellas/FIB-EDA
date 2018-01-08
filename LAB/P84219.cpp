#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre){
    
    if (esq > dre) return -1;
    
    int mig = (dre+esq)/2;
    
    if (x < v[mig]) return posicio(x, v, esq, mig-1);
    if (x > v[mig]) return posicio(x, v, mig+1, dre);
    
    if (mig > 1) {
        int iguals = posicio(x, v, esq, mig - 1);
        if (iguals != -1) return iguals;
    }
    
    return mig;
}

int first_occurrence(double x, const vector<double>& v) {
    
    
    
    return posicio(x, v, 0, v.size()-1);
    
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

