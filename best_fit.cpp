#include <bits/stdc++.h>
using namespace std;

void display(int block_size[], int m, int procees_size[], int n, int allocation[])
{
    cout << " Process No. \t Process Size \t Block No. " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << procees_size[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "not allowed";
        }

        cout << endl;
    }
}

void bestFit(int block_size[], int m, int procees_size[], int n)
{
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n; i++)
    {
        int best_index = -1;
        for (int j = 0; j < m; j++)
        {
            if (block_size[j] >= procees_size[i])
            {
                if (best_index == -1)
                {
                    best_index = j;
                }
                else if (block_size[best_index] > block_size[j])
                {
                    best_index = j;
                }
            }
        }
        if (best_index != -1)
        {
            allocation[i] = best_index;
            block_size[best_index] = block_size[best_index] - procees_size[i];
        }
    }
    display(block_size, m, procees_size, n, allocation);
}

int main()
{
    int block_size[] = {100, 500, 200, 300, 600};
    int process_size[] = {212, 417, 112, 426};
    int m = sizeof(block_size) / sizeof(block_size[0]);
    int n = sizeof(process_size) / sizeof(process_size[0]);
    bestFit(block_size, m, process_size, n);

    return 0;
}