#include<stdio.h>
#include<stdlib.h>
void main(){
  int ch=1,c;
  while(ch==1){
    printf("enter the choice\n 1)FCFS 2)sjf 3)priority 4)roundrobin 5)exit \n");
    scanf("%d",&c);
    switch(c){
       case 1:{
        int i,n;
  float avgwt=0,avgtat=0;
  printf("enter the number of process\n");
  scanf("%d",&n);
  int pid[n],bt[n],wt[n],tat[n];
     printf("enter the process id amd burst time of process\n");
  for(i=0;i<n;i++){
     scanf("%d%d",&pid[i],&bt[i]);
  }
  wt[0]=0;
  tat[0]=bt[0];
 
   for(i=1;i<n;i++){
       wt[i]=wt[i-1]+bt[i-1];
       tat[i]=tat[i-1]+bt[i];
       avgwt=avgwt+wt[i];
       avgtat=avgtat+tat[i];
   }
    avgtat=avgtat+tat[0];
    printf("GANT CHART:\n");
    for(i=0;i<n;i++)
       printf("\tP%d",pid[i]);
    printf("\n");
     for(i=0;i<n;i++)
        printf("     %d\t",wt[i]);
     printf("   %d",tat[n-1]);
     printf("\n");
   printf("PID\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\n",pid[i],bt[i],wt[i],tat[i]);
    }
    printf("total waiting time=%f\n",avgwt);
    printf("total turn around time=%f\n",avgtat);
    printf("Average waiting time=%f\n",avgwt/n);
    printf("Average turn around time=%f\n",avgtat/n);
    break;
 }
        case 2:{
        int i,n,j,temp;
  float avgwt=0,avgtat=0;
  printf("enter the number of process\n");
  scanf("%d",&n);
  int pid[n],bt[n],wt[n],tat[n];
  printf("enter the process id amd burst time of process\n");
  for(i=0;i<n;i++){
     scanf("%d%d",&pid[i],&bt[i]);
  }
   for(i=0;i<n;i++){
     for(j=i+1;j<n;j++){
       if(bt[i]>bt[j]){
          temp=bt[i];
          bt[i]=bt[j];
          bt[j]=temp;
           temp=pid[i];
          pid[i]=pid[j];
          pid[j]=temp;
          }
        }
    }
  wt[0]=0;
  tat[0]=bt[0];
 
   for(i=1;i<n;i++){
       wt[i]=wt[i-1]+bt[i-1];
       tat[i]=tat[i-1]+bt[i];
       avgwt=avgwt+wt[i];
       avgtat=avgtat+tat[i];
   }
    avgtat=avgtat+tat[0];
    printf("GANT CHART:\n");
    for(i=0;i<n;i++)
       printf("\tP%d",pid[i]);
    printf("\n");
     for(i=0;i<n;i++)
        printf("     %d\t",wt[i]);
     printf("   %d",tat[n-1]);
     printf("\n");
     
   printf("PID\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\n",pid[i],bt[i],wt[i],tat[i]);
    }
    printf("total waiting time=%f\n",avgwt);
    printf("total turn around time=%f\n",avgtat);
    printf("Average waiting time=%f\n",avgwt/n);
    printf("Average turn around time=%f\n",avgtat/n);
    break;
 }
    case 3:{
        int i,n,j,temp;
  float avgwt=0,avgtat=0;
  printf("enter the number of process\n");
  scanf("%d",&n);
  int pid[n],bt[n],wt[n],tat[n],pri[n];
     printf("enter the process id ,burst time and priority of process\n");
  for(i=0;i<n;i++){
     scanf("%d%d%d",&pid[i],&bt[i],&pri[i]);
  }
   for(i=0;i<n;i++){
     for(j=i+1;j<n;j++){
       if(pri[i]>pri[j]){
          temp=bt[i];
          bt[i]=bt[j];
          bt[j]=temp;
          temp=pri[i];
          pri[i]=pri[j];
          pri[j]=temp;
          temp=pid[i];
          pid[i]=pid[j];
          pid[j]=temp;
          }
        }
    }
  wt[0]=0;
  tat[0]=bt[0];
 
   for(i=1;i<n;i++){
       wt[i]=wt[i-1]+bt[i-1];
       tat[i]=tat[i-1]+bt[i];
       avgwt=avgwt+wt[i];
       avgtat=avgtat+tat[i];
   }
    avgtat=avgtat+tat[0];
    printf("GANT CHART:\n");
    for(i=0;i<n;i++)
       printf("\tP%d",pid[i]);
    printf("\n");
     for(i=0;i<n;i++)
        printf("     %d\t",wt[i]);
     printf("   %d",tat[n-1]);
     printf("\n");
     
   printf("PID\tBT\tWT\tTAT\tpriority\n");
    for(i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\n",pid[i],bt[i],wt[i],tat[i],pri[i]);
    }
    printf("total waiting time=%f\n",avgwt);
    printf("total turn around time=%f\n",avgtat);
    printf("Average waiting time=%f\n",avgwt/n);
    printf("Average turn around time=%f\n",avgtat/n);
    break;
 }
 case 4:{
      printf("enter the time quantum:\n");
int TIME_QUA;
scanf("%d",&TIME_QUA);
printf("enter the number of processes:\n");
int limit;
scanf("%d",&limit);
int process[limit],bt[limit],rem_bt[limit],wt[limit],tat[limit],tt[30],i,j=0,last=0;
int time =0;
int completed =0;
tt[j]=time;

printf("enter the process and burst time:\n");
for(i=0;i<limit;i++)
    {
    scanf("%d%d",&process[i],&bt[i]);
    rem_bt[i]=bt[i];
    }
    while(completed<limit){
    for(i=0;i<limit;i++) {
     if(rem_bt[i]>0){
     if(rem_bt[i]>TIME_QUA){
     time+=TIME_QUA;
     tt[++j]=time;
     last++;
     rem_bt[i]-=TIME_QUA;
     printf("     p%d\t",process[i]);
     }
     else{
     time +=rem_bt[i];
     tt[++j]=time;
     wt[i]=time-bt[i];
      printf("     p%d\t",process[i]);
      rem_bt[i]=0;
      completed++;
      tat[i]=time;
      }}}}
      
      printf("\n");
       for(i=0;i<=j;i++) 
      {
      printf("%d\t",tt[i]);
      }
      printf("\n");
      float tot_wt=0,tot_tat=0;
      printf("process\tBT\tWT\tTAT\n");
      for(i=0;i<limit;i++) {
       printf("%d\t%d\t%d\t%d\n",process[i],bt[i],wt[i],tat[i]);
       tot_wt+=wt[i];
       tot_tat+=tat[i];
       }
       printf("Average_wt=%.2f\n Average TAT =%.2f\n Total WT =%.2f\n total TAT=%.2f\n",tot_wt/limit,tot_tat/ limit,tot_wt,tot_tat);
      }
      case 5:{
      exit(0):
      } 
  }
}
}
