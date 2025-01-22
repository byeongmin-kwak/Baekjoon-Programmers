#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int N;
vector<pair<double, double>> point;
double ans = 0.0;

void input() {
  cin >> N;
  double x, y;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    point.push_back({x, y});
  }
}

void solve() {
  
  for (int i = 0; i < N; i++) {
    ans += (point[i].first * point[(i+1)%N].second);
    ans -= (point[(i+1)%N].first * point[i].second);
  }
  ans /= 2;
  ans = fabs(ans);
  
}

int main() {
  
  input();
  
  solve();
  
  cout << fixed;
  cout.precision(1);
  cout << ans;
}
