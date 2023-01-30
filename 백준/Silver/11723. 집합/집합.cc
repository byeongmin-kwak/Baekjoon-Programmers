#include <bits/stdc++.h>

using namespace std;
 
int arr[21];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M;
    cin >> M;
    
    string command;
    int n;
    while (M--) {
        cin >> command;
        
        if (command == "add") {
            cin >> n;
            arr[n] = 1;
        }
        else if (command == "remove") {
            cin >> n;
            arr[n] = 0;
        }
        else if (command == "check") {
            cin >> n;
            cout << arr[n] << '\n';
        }
        else if (command == "toggle") {
            cin >> n;
            if (arr[n] == 0) {
                arr[n] = 1;
            }
            else {
                arr[n] = 0;
            }
        }
        else if (command == "all") {
            for (int i = 1; i <= 20; i++) {
                arr[i] = 1;
            }
        }
        else if (command == "empty") {
            for (int i = 1; i <= 20; i++) {
                arr[i] = 0;
            }
        }
    }
}
