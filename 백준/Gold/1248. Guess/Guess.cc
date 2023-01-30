#include <bits/stdc++.h>

using namespace std;
 
int N;
char arr[10][10];
int ans[10];
 
bool Check(int Idx)
{
    int Sum = 0;
    for (int i = Idx; i >= 0; i--)
    {
        Sum = Sum + ans[i];
        if (arr[i][Idx] == '+' && Sum <= 0) return false;
        if (arr[i][Idx] == '-' && Sum >= 0) return false;
        if (arr[i][Idx] == '0' && Sum != 0) return false;
    }
    return true;
}
 
void dfs(int Cnt)
{
    if (Cnt == N)
    {
        for (int i = 0; i < Cnt; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        exit(0);
    }
 
    for (int i = -10; i <= 10; i++)
    {
        ans[Cnt] = i;
        if (Check(Cnt) == true)
            dfs(Cnt + 1);
    }
}

int main(void) {
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    dfs(0);
 
 }
