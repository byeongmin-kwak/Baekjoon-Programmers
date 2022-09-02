#include <bits/stdc++.h>

using namespace std;

long long cnt[1001];
long long sum, ans;

int main() {
  	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    int num;
    sum = 0;
    for (int i = 0; i < n; i++) {    
        cin >> num;
        sum += num;
        cnt[sum % m]++;
    }

    for (int i = 0; i <= m; i++) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << cnt[0] + ans;
}