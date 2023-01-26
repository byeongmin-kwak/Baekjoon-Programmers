#include <bits/stdc++.h>

using namespace std;

vector<char> v;
int L, C, cnt1 = 0, cnt2 = 0;
char ans[15];
vector<char> temp = {'a', 'e', 'i', 'o', 'u'};

void dfs(int depth, int index) {
    bool check;

    if (depth == L) {
        if (cnt1 >= 1 && cnt2 >= 2) {
            for (int i = 0; i < L; i++) {
                cout << ans[i];
            }
            cout << '\n';
        }
        return;
    }
    for (int i = index; i < C; i++) {
        ans[depth] = v[i];
        if (find(temp.begin(), temp.end(), v[i]) != temp.end()) {
            cnt1++;
            check = true;
        }
        else {
            cnt2++;
            check = false;
        }
        dfs(depth+1, i+1);
        if (check)
            cnt1--;
        else
            cnt2--;
    }
}


int main() {
    cin >> L >> C;
    
    char c;
    for (int i = 0; i < C; i++) {
        cin >> c;
        v.push_back(c);
    }
    
    sort(v.begin(), v.end());
    
    
    dfs(0,0);
    
    
}
