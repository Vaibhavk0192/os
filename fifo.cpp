#include <bits/stdc++.h>
using namespace std;

void findingWaitingTime(int process[], int n, int burst_time[], int waiting_time[])
{
    waiting_time[0]=0;
    for(int i=1;i<n;i++)
    {
        waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
    }
}

void findingTurnAroundTime(int process[], int n, int burst_time[], int waiting_time[],int turn_around_time[])
{
    for(int i=0;i<n;i++)
    {
        turn_around_time[i]=waiting_time[i]+burst_time[i];
    }
}

void display(int process[],int n,int burst_time[],int waiting_time[],int turn_around_time[])
{
    int total_wt = 0, total_tat = 0;
    cout<<"Process  "<<" Burst Time  "<<" waiting Time  "<<" Turn Around Time "<<endl;
    for(int i=0;i<n;i++)
    {
        total_tat=total_tat+turn_around_time[i];
        total_wt=total_wt+waiting_time[i];
        cout<<" "<<i+1<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turn_around_time[i]<<endl;
    } 
    cout<<"total turn around time = "<<(float)total_tat/(float)n<<endl;
    cout<<"total waiting time = "<<(float)total_wt/(float)n;
}

void findingAvgTime(int process[], int n, int burst_time[])
{
    int waiting_time[n], turn_around_time[n], total_wt = 0, total_tat = 0;
    findingWaitingTime(process, n, burst_time, waiting_time);
    findingTurnAroundTime(process,n,burst_time,waiting_time,turn_around_time);
    display(process,n,burst_time,waiting_time,turn_around_time);
}

int main()
{
    int process[] = {1, 2, 3};
    int n = sizeof(process) / sizeof(process[0]);
    int burst_time[] = {10, 5, 8};
    findingAvgTime(process, n, burst_time);
    return 0;
}