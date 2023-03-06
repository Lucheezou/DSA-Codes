///////////////////////////////////////
// Round Robin                      //
// Luke Vincent M. Samson          //
// BSCS-3C                        //
///////////////////////////////////
#include <bits-stdc++.h>
int n,bt[10],wt[10],tat[10],ct[10],i,j, q,t1,t2,btc[10];
double avewt=0,avetat=0;
using namespace std;

void printcredits(){
cout << "=============================\nRound Robin SCHEDULING by\n=============================" << endl;
cout << "Luke Vincent Samson\nBSCS-3C" << endl;
cout << "=============================" << endl;
}

int main()
{   
    printcredits();
    cout<<"Enter total number of processes:";
    cin>>n;

    cout<<"Enter Quantum:";
    cin>>q;
 
    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
                
    }
    
    //copy to temporary array btc
    for (i=0; i<n; i++){
        btc[i] = bt[i];
    }


   

    //calculate completion time
    list<int> queue;
    for (i=0;i<n;i++){
        queue.push_back(i);
    }

    int time = 0;
    while(queue.empty() == 0){
        
       for (i = 0; i < q; i++){
        btc[queue.front()] = btc[queue.front()] - 1;
        time++;
        if (btc[queue.front()] == 0){
            ct[queue.front()] = time;
            break;
        }
       }
        
        
        if(btc[queue.front()] > 0){
            queue.push_back(queue.front());
        }

        queue.pop_front();

    }


    

    cout<<"\nP\tBT\tWT\tTAT";
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i];
        
    }

    //calculating waiting time
    for(i=0;i<n;i++)
    {
        wt[i] = tat[i] - bt[i];
        avewt+=wt[i];
        avetat+=tat[i];
        cout<<"\nP["<<i + 1<<"]"<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i];
    }

    avewt/=i;
    avetat/=i;
    cout<<"\n\nAverage Waiting Time:"<<setprecision(4)<<avewt;
    cout<<"\nAverage Turnaround Time:"<<setprecision(4)<<avetat << endl;
 
    return 0;
}