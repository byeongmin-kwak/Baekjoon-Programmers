#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1, y1, x2, y2, _x1, _y1, _x2, _y2;
    
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> _x1 >> _y1 >> _x2 >> _y2;
    
    if(x1 > _x1){
            swap(x1, _x1);
            swap(y1, _y1);
            swap(x2, _x2);
            swap(y2, _y2);
        }
    
    if(x2 == _x1){
        if(y2 == _y1 || y1 == _y2){
            cout << "POINT" << "\n";
        }
        else {
            cout <<"LINE" << "\n";
        }
    }
    else if(x2 > _x1){
        if(y2 < _y1 || y1 > _y2) {
            cout << "NULL" << "\n";
        }
        else if(y2 == _y1 || y1 == _y2) {
            cout << "LINE" << "\n";
        }
        else {
            cout << "FACE" << "\n";
        }
    }
    else if(x2 < _x1) {
        cout << "NULL" << "\n";
    }


}
