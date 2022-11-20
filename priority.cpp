#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int pid;
    int priority;
    int burst_time;
    Process(int pid, int burst_time, int priority)
    {
        this->pid = pid;
        this->burst_time = burst_time;
        this->priority = priority;
    }
    Process()
    {
    }
};

void findingWaitingTime(Process proc[], int n, int waiting_time[])
{
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = waiting_time[i - 1] + proc[i-1].burst_time;
    }
}

void findingTurnAroundTime(Process proc[], int n, int waiting_time[], int turn_around_time[])
{
    for (int i = 0; i < n; i++)
    {
        turn_around_time[i] = waiting_time[i] + proc[i].burst_time;
    }
}

void display( Process proc[], int n, int waiting_time[], int turn_around_time[])
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
        cout << " " << proc[i].pid<< "\t\t" << proc[i].burst_time << "\t\t" << waiting_time[i] << "\t\t" << turn_around_time[i] << endl;
    }
    cout << "total turn around time = " << (float)total_tat / (float)n << endl;
    cout << "total waiting time = " << (float)total_wt / (float)n;
}

void findingAvgTime(Process proc[], int n)
{
    int waiting_time[n], turn_around_time[n], total_wt = 0, total_tat = 0;
    findingWaitingTime(proc, n, waiting_time);
    findingTurnAroundTime(proc, n, waiting_time, turn_around_time);
    display(proc, n, waiting_time, turn_around_time);
}

bool comparison(Process a, Process b)
{
    return (a.priority > b.priority);
}

void PriorityScheduling(Process proc[], int n)
{
    sort(proc,proc+n,comparison);
    cout<<"the sequence in which process will be exexcuted"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<proc[i].pid<<" "<<endl;
    }
        findingAvgTime(proc,n);
    
}

int main()
{
    Process proc[] = {{1, 10, 2}, {2, 5, 10}, {3, 8, 1}};
    int n = sizeof(proc) / sizeof(proc[0]);
    PriorityScheduling(proc,n);
    return 0;
}