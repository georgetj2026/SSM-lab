#include<stdio.h>
void main()
{
   int n,i,temp,j;
   printf("Enter the number of process:\n");
   scanf("%d",&n);
   int p[n],bt[n],pri[n],wt[n],tat[n];
   printf("Enter the process number and burst time and priority:\n");
   for(i=0;i<n;i++)
   {
      scanf("%d%d%d",&p[i],&bt[i],&pri[i]);
   }
   for(i=0;i<n;i++)
   {
     for(j=i+1;j<n;j++)
     {
        if(pri[i]>pri[j])
        {
           temp=pri[i];
           pri[i]=pri[j];
           pri[j]=temp;
           temp=bt[i];
           bt[i]=bt[j];
           bt[j]=temp;
           temp=p[i];
           p[i]=p[j];
           p[j]=temp;
        }
     }
   }
   wt[0]=0;
   tat[0]=bt[0];
   float totwt=0,tottat=tat[0];
   
   for(i=1;i<n;i++)
   {
     wt[i]=wt[i-1]+bt[i-1];
     tat[i]=tat[i-1]+bt[i];
     totwt+=wt[i];
     tottat+=tat[i];
   }
   
   printf("process\tbt\tpri\twt\ttat\n");
   for(i=0;i<n;i++)
   {
     printf("%d\t%d\t%d\t%d\t%d\n",p[i],bt[i],pri[i],wt[i],tat[i]);
   }
    printf("Grand chart\n");
    printf(" ________________________________\n");
   for(i=0;i<n;i++)
   {
     printf("|    p%d  ",p[i]);
   }
   printf("|\n");
   printf(" ________________________________\n");
   for(i=0;i<n;i++)
   {
     printf("%d\t",wt[i]);
   }
   printf("%d\n",tat[n-1]);
   
   printf("Average waiting time=%f\nAverage turn around time=%f\ntotal waiting time=%f\ntotal turn around time=%f\n",totwt/n,tottat/n,totwt,tottat);
   }
