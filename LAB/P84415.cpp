#include <iostream>
#include <map>
using namespace std;

int main() {
    
    map<string, int> m;
    
    string ordre;
    
    while (cin >> ordre) {
        if (ordre == "maximum?") {            
            if (m.empty()) cout << "indefinite maximum" << endl;
            else {
                
                auto it = m.end();
                --it;
                
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        
        else if (ordre == "minimum?") {
            
            if (m.empty()) cout << "indefinite minimum" << endl;
            else {
                
                auto it = m.begin();
              
                
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
            
        }
        
        else if (ordre == "store") {
            string valor;
            cin >> valor;
            
            if (m.find(valor) == m.end()) m[valor] = 1; // si no hi es
            else ++m[valor];
        }
        
        else if (ordre == "delete") {
            string valor;
            cin >> valor;
            
            auto it = m.find(valor);
            
            if (it != m.end()) {
            
                if (m.find(valor)->second > 1) --m[valor];
                else m.erase(valor);
            }
        }
    }
}


