#include <iostream>

using namespace std;

int main() {

    int x, n, a, b;

    cin >> x >> n;
    int result = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        result += a*b;
    }
    if (x == result ) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

}
