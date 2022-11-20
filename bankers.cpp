#include <bits/stdc++.h>
using namespace std;

const int N = 5;
const int M = 3;

void bankersAlgo(int n, int m, int alloc[N][M], int max[N][M], int avail[M])
{
    int finish[n] = {0}, ans[n], index = 0;
    int need[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[index++] = i;
                    for (int y = 0; y < m; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    finish[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            flag = 0;
            cout << "the given sequence is not safe";
            break;
        }
    }
    if (flag == 1)
    {
        cout << "following is the safe sequence" << endl;
        for (int i = 0; i < n - 1; i++)
        {
            cout << " P" << ans[i] << " ->";
        }
        cout << " P" << ans[n - 1] << endl;
    }
}

int main()
{
    int alloc[N][M] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int max[N][M] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int avail[M] = {3, 3, 2};
    bankersAlgo(N, M, alloc, max, avail);

    return 0;
}