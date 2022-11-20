#include <bits/stdc++.h>
using namespace std;

void findingWaitingTime(int process[], int n, int burst_time[], int waiting_time[], int quantum)
{
    int remaning_burst_time[n];
    for (int i = 0; i < n; i++)
    {
        remaning_burst_time[i] = burst_time[i];
    }
    int t = 0;
    while (true)
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (remaning_burst_time[i] > 0)
            {
                done = false;
                if (remaning_burst_time[i] > quantum)
                {
                    t = t + quantum;
                    remaning_burst_time[i] = remaning_burst_time[i] - quantum;
                }
                else
                {
                    t = t + remaning_burst_time[i];
                    waiting_time[i] = t - burst_time[i];
                    remaning_burst_time[i] = 0;
                }
            }
        }
        if (done == true)
        {
            break;
        }
    }
}

    void findingTurnAroundTime(int process[], int n, int burst_time[], int waiting_time[], int turn_around_time[])
    {
        for (int i = 0; i < n; i++)
        {
            turn_around_time[i] = waiting_time[i] + burst_time[i];
        }
    }

    void display(int process[], int n, int burst_time[], int waiting_time[], int turn_around_time[])
    {
        int total_wt = 0, total_tat = 0;
        cout << "Process  "
             << " Burst Time  "
             << " waiting Time  "
             << " Turn Around Time " << endl;
        for (int i = 0; i < n; i++)
        {
            total_tat = total_tat + turn_around_time[i];
            total_wt = total_wt + waiting_time[i];
            cout << " " << i + 1 << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turn_around_time[i] << endl;
        }
        cout << "total turn around time = " << (float)total_tat / (float)n << endl;
        cout << "total waiting time = " << (float)total_wt / (float)n;
    }

    void findingAvgTime(int process[], int n, int burst_time[], int quantum)
    {
        int waiting_time[n], turn_around_time[n], total_wt = 0, total_tat = 0;
        findingWaitingTime(process, n, burst_time, waiting_time, quantum);
        findingTurnAroundTime(process, n, burst_time, waiting_time, turn_around_time);
        display(process, n, burst_time, waiting_time, turn_around_time);
    }

    int main()
    {
        int process[] = {1, 2, 3};
        int n = sizeof(process) / sizeof(process[0]);
        int burst_time[] = {10, 5, 8};
        int quantum = 2;
        findingAvgTime(process, n, burst_time, quantum);
        return 0;
    }