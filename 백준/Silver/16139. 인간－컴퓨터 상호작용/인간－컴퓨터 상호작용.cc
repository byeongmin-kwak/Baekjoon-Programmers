#include <bits/stdc++.h>

using namespace std;

int arr[26][200001] = {0};
string s;

int main() {
  	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        if(i!=0) {
            for (int j = 0; j < 26; j++) {
                arr[j][i] = arr[j][i-1];
            }
        }
        arr[s[i]-'a'][i]++;
        
    }
    


    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char ch;
        int start, end;

        cin >> ch >> start >> end;

        if (start == 0) {
            cout << arr[ch-'a'][end] << '\n';
        }
        else {
            cout << arr[ch-'a'][end]-arr[ch-'a'][start-1] << '\n';
        }
    }

}
