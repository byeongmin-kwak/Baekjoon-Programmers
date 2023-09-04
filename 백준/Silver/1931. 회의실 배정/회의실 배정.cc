//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <utility>
//
//using namespace std;
//
//bool comp(pair<int, int> a, pair<int, int> b)
//{
//   return a.second < b.second;
//}
//
//int main()
//{
//   vector<pair<int, int>>confer;
//   int c;
//   cin >> c;
//   for (int i = 0; i < c; i++)
//   {
//      int a, b;
//      cin >> a >> b;
//      confer.push_back(make_pair(a, b));
//   }
//   sort(confer.begin(), confer.end(), comp);
//
//   int result = 1;
//   int set = 0;
//   for (int i = 1; i < c; i++)
//   {
//      if (confer[i].first >= confer[set].second)
//      {
//         result++;
//         set = i;
//      }
//   }
//   cout << result;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   int n;
   cin >> n;
   vector<pair<int, int>> list;

   for (int i = 0; i < n; i++)
   {
      int start, end;
      cin >> end >> start;
      list.push_back(make_pair(start, end));
   }
   sort(list.begin(), list.end());

   int time = list[0].first;
   int ans = 1;
   int j = 0;
   for (int i = 1; i <= n; i++)
   {
      if (list[i].second >= time)
      {
         ans++;
         time = list[i].first;
      }
   }
   cout << ans;
}
