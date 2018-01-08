#include <iostream>
#include <set>
using namespace std;

int main() {
    
    set<string> s;
    
    string valor;

    while (cin >> valor and valor != "END") {
        
        s.insert(valor);
        
        auto it = s.begin();
        
        int salt = (s.size()+1)/2;
        salt--;
        
        advance(it, salt);
    
        cout << *it << endl;
        
    }
    
}


