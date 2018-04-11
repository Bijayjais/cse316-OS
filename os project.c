#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/queue.h>
struct process
{
    int pid;
    float AT;
    float BT;
    float WT;
    float priority;
    int status;
};

int main()
{
    printf("\n ************************* SHORTEST JOB SCHEDULING ALLGORITHM PROJECT ***********************************");
    printf("\n\n\n enter the number of processes you want to schedule :  ");
    int number;
    scanf("%d",&number);
    struct process proc[number];
    
    printf("\n enter the burst time of the processes \n");
 
    for(int i=0;i<number;i++)
    {
        printf("\n enter the burst time for the %d process  :  ",i+1);
        scanf("%f",&proc[i].BT);
        proc[i].pid=i+1;
        proc[i].status=0;
    }

    printf("\n enter the arival time of the processes \n");
    for(int i=0;i<number;i++)
    {
        printf("\n enter the arival time for the %d process  :  ",i+1);
        scanf("%f",&proc[i].AT);
    }

        printf("\n Process:     |   Burst Time:     |   Arival Time:     | ");
    for(int i=0;i<number;i++)
    {
        printf("\n   %d               %d                   %d      ",proc[i].pid,(int )proc[i].BT,(int )proc[i].AT);
    }
    printf("\n");
    for(int i=0;i<number;i++)
    {
        proc[i].WT=0;
    }

    int max_at=0;
    for(int i=0;i<number;i++)
    {
        if((int)proc[i].AT>max_at)
        {
            max_at=(int)proc[i].AT;
        }
    }    
 
 //   printf("\n max is %d ",max);

    int timer=0;
   int j=0;
   int seq[number];

    for (timer=0;timer<=max_at;timer++)
    {
        for(int i=0;i<number;i++)
        {
            if(timer>=(int)proc[i].AT)
            {
                if(proc[i].status==0)
                {
                    seq[j++]=proc[i].pid;
                    proc[i].status=1;
                }
            }
        }
    }
    printf("\n\n\n");
/*    for(int i=0;i<number;i++)
    {
        printf("    %d     ",seq[i]);
    }
*/
    int final_sequence[number];
    final_sequence[0]=seq[0];
    






}
