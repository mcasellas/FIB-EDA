#include <iostream>
#include <queue>
using namespace std;

int main() {
    char ordre;

    priority_queue<int> pq;

    while (cin >> ordre) {
        int temp, numero;
        switch (ordre) {
            case 'S' :
                cin >> numero;
                pq.push(numero);

            break;
            case 'A' :
                if (pq.empty()) cout << "error!" << endl;
                else cout << pq.top() << endl;

            break;
            case 'R' :
                if (pq.empty()) cout << "error!" << endl;
                else pq.pop();

            break;
            case 'I' :
                cin >> numero;

                if (pq.empty()) cout << "error!" << endl;

                else {
                    temp = pq.top();
                    pq.pop();
                    pq.push(temp+numero);
                }

            break;
            case 'D' :
                cin >> numero;

                if (pq.empty()) cout << "error!" << endl;

                else {
                    temp = pq.top();
                    pq.pop();
                    pq.push(temp-numero);
                }
            break;
        }

    }


}
