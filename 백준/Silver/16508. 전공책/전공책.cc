#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, string>> v;
string T;
int N;
int answer = 1000000;
bool check[16];
vector<string> s;

void Solve(int currentDepth, int depth, int price, int next) {
    if (currentDepth == depth) {
        
        int cnt = 0;
        string tmp = "";
        for (int i = 0; i < s.size(); i++) {
            tmp += s[i];
        }
        for (int i = 0 ; i < T.size(); i++) {
            for (int j = 0; j < tmp.size(); j++) {
                if (T[i] == tmp[j]) {
                    tmp[j] = '-';
                    cnt++;
                    break;
                }
            }
            if (cnt-1 != i) {
                break;
            }
        }
        tmp.clear();
        
        if (cnt == T.size()) {
            answer = min(answer, price);
        }
        return;
    }
    for (int i = next; i < N; i++) {
        s.push_back(v[i].second);
        Solve(currentDepth+1, depth, price+v[i].first, i+1);
        s.pop_back();
    }
}

int main() {

    cin >> T >> N;

    int C;
    string W;
    for (int i = 0; i < N; i++) {
        cin >> C >> W;
        v.push_back({C,W});
    }

    for (int i = 1; i <= N; i++) {
        Solve(0, i, 0, 0);
    }

    if (answer == 1000000) {
        cout << -1;
    }
    else {
        cout << answer;
    }

}
