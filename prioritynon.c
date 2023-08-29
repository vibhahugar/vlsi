#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void main()
{
    int pid[10],arr[10],burst[10],ta[10],wt[10],prio[10],n,ct[10],i,j,sum=0;
    float avgta=0,avgwt=0;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    printf("Enter the arrival time,priority and burst time for each process\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
         scanf("%d",&prio[i]);
        scanf("%d",&burst[i]);
       
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(prio[j]<prio[j+ 1])
            {
                swap(&arr[j],&arr[j+1]);
                swap(&burst[j],&burst[j+1]);
                swap(&prio[j],&prio[j+1]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        sum+=burst[i];
        ct[i]=sum;
        ta[i]=ct[i]-arr[i];
        wt[i]=ta[i]-burst[i];
        if(sum<arr[i+1])
        {
            int t=arr[i+1]-sum;
            sum+=t;
        }
    }
    printf("\nTuraround time\t Waiting time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\n",ta[i],wt[i]);
        avgta+=ta[i];
        avgwt+=wt[i];
    }
    avgta=(float)avgta/n;
    avgwt=(float)avgwt/n;
    printf("average ta=%f\n",avgta);
    printf("average waiting time=%f\n",avgwt);

}
