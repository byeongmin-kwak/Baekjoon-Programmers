#include <bits/stdc++.h>

using namespace std;

struct line {
  int s, e;
};

int inter(line a, line b) {
  if (a.s > b.s) {
    line tmp = a;
    a = b;
    b = tmp;
  }
  if (a.e < b.s) return 0;
  else if (a.e == b.s) return 1;
  else return 2;
}

int main() {
  line x1, y1;
  line x2, y2;

  scanf("%d%d%d%d", &x1.s, &y1.s, &x1.e, &y1.e);
  scanf("%d%d%d%d", &x2.s, &y2.s, &x2.e, &y2.e);
  int ix = inter(x1, x2), iy = inter(y1, y2);
  if (ix == 2 && iy == 2) printf("FACE");
  else if (ix == 1 && iy == 2 || ix == 2 && iy == 1) printf("LINE");
  else if (ix == 1 && iy == 1) printf("POINT");
  else printf("NULL");
}
