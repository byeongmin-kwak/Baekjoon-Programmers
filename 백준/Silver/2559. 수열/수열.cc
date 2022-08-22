#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
  	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        arr[i] = arr[i-1] + num;
    }

    int maxNum = -10000;
    for (int i = k; i <= n; i++) {
        maxNum = max(maxNum, arr[i]-arr[i-k]);
    }

    cout << maxNum;
    
}