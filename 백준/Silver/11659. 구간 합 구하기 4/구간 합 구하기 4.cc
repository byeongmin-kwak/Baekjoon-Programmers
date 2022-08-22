#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
  	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        arr[i] = arr[i-1] + num;
    }

    int a, b;
    
    while (m--) {
        cin >> a >> b;
        cout << arr[b] - arr[a-1] << '\n';
        
    }
    
}