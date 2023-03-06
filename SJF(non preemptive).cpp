////////////////////////////////////////
// Short Job First Scheduling        //
// Non Preemptive                   //
// Luke Vincent M. Samson          //
// BSCS-3C                        //
///////////////////////////////////
#include <bits-stdc++.h>
int n,bt[10],wt[10],tat[10],i,j, p[10];
using namespace std;
double avewt=0,avetat=0;
void printcredits(){
cout << "=============================\nSJF SCHEDULING by\n=============================" << endl;
cout << "Luke Vincent Samson\nBSCS-3C" << endl;
cout << "=============================" << endl;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}



void bubbleSort(int arr[],int arr2[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swap(&arr2[j], &arr2[j + 1]);
                }
}

int main()
{   
    printcredits();
    cout<<"Enter total number of processes:";
    cin>>n;
 
    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
        p[i] = i+1;


                
    }
    bubbleSort(bt,p,n);
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
        cout<<"\nP["<<p[i]<<"]"<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i];
    }

    avewt/=i;
    avetat/=i;
    cout<<"\n\nAverage Waiting Time:"<<setprecision(4)<<avewt;
    cout<<"\nAverage Turnaround Time:"<<setprecision(4)<<avetat<< endl;
 
    return 0;
}