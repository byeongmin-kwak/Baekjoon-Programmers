#include <bits/stdc++.h>

using namespace std;

int arr[129][129];
int white = 0;
int blue = 0;

void paper(int x_start, int x_end, int y_start, int y_end)
{
    int check1 = arr[x_start][y_start];
    bool check2 = true;

    if (x_start < x_end or y_start < y_end)
    {
        for (int i = x_start; i <= x_end; i++)
        {
            for (int j = y_start; j <= y_end; j++)
            {
                if (check1 == 0 and arr[i][j] == 1)
                {
                    check2 = false;
                    break;
                }
                else if (check1 == 1 and arr[i][j] == 0)
                {
                    check2 = false;
                    break;
                }
            }
            if (check2 == false)
                break;
        }

        if (check2 == false)
        {
            paper(x_start, (x_start + x_end - 1) / 2, y_start, (y_start + y_end - 1) / 2);
            paper(x_start, (x_start + x_end - 1) / 2, (y_start + y_end - 1) / 2 + 1, y_end);
            paper((x_start + x_end - 1) / 2 + 1, x_end, y_start, (y_start + y_end - 1) / 2);
            paper((x_start + x_end - 1) / 2 + 1, x_end, (y_start + y_end - 1) / 2 + 1, y_end);
        }
        else {
            if (arr[x_start][y_start] == 1) {
                blue++;
            }
            else {
                white++;
            }
        }
    }
    else {
        if (arr[x_start][y_start] == 1) {
            blue++;
        }
        else {
            white++;
        }
    }
}

int main()
{

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

//     cout << '\n';
//     for (int i = 1; i <=N; i++) {
//         for (int j = 1; j <= N; j++) {
//             cout << arr[i][j] << ' ';
//         }
//         cout << '\n';
//     }

    paper(1, N, 1, N);
    cout << white << '\n' << blue;
}
