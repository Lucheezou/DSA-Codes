////////////////////////////////////////
// First Come First Serve Scheduling //
// Luke Vincent M. Samson           //
// BSCS-3C                         //
////////////////////////////////////
#include <bits-stdc++.h>

using namespace std;


void printcredits(){
cout << "=============================\nFCFS SCHEDULING by\n=============================" << endl;
cout << "Luke Vincent Samson\nBSCS-3C" << endl;
cout << "=============================" << endl;
}

int main()
{   
    printcredits();
    double avewt = 0, avetat = 0;
    int n,bt[10],wt[10],tat[10],i,j;
    cout<<"Enter total number of processes:";
    cin>>n;
 
    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }
    wt[0]=0;    //waiting time for first process is 0
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    cout<<"\nP\tBT\tWT\tTAT";
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avewt+=wt[i];
        avetat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i];
    }
    
    avewt/=i;
    avetat/=i;
    cout<<"\n\nAverage Waiting Time:"<<setprecision(4)<<avewt;
    cout<<"\nAverage Turnaround Time:"<<setprecision(4)<<avetat<< endl;
 
    return 0;
}