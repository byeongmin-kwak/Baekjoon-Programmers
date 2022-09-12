#include <bits/stdc++.h>

using namespace std;


void recursion(string& s, int start, int end, int cnt) {
	if (start >= end) {
		cnt += 1;
		cout << 1 << ' ' << cnt << '\n';
	}
	else if (s[start] != s[end]) {
		cnt += 1;
		cout << 0 << ' ' << cnt << '\n';
	}
	else {
		cnt += 1;
		return recursion(s, start+1, end-1, cnt);
	} 
}

void isPalindrome(string& s) {
	return recursion(s, 0, s.size()-1, 0);
}

int main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	string s;

	while(T--) {
		cin >> s;
		isPalindrome(s);
	}
}