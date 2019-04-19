#include<stdio.h>
#include<conio.h>
void aakash(int no,int RemainTime[10],int CompTime,int ArivTime[10],int BurTime[10]);
int main()
{
	int ProcessNo,j,no,CompTime,RemainProcess,indic,TimeQuant,Wait,TAT,ArivTime[10],BurTime[10],RemainTime[10],x=1;
	indic = 0;
    Wait=0;
    TAT = 0;
    printf("Enter the number of processes: ");
    scanf("%d",&no);
    RemainProcess = no;
    printf("\nEnter the Arrival Time and Burst Time of the Processes:\n");
     for(ProcessNo = 0;ProcessNo < no;ProcessNo++)
    {
        printf("\nProcess P%d\n",ProcessNo+1);
        printf("Arrival Time = ");
        scanf("%d",&ArivTime[ProcessNo]);
        printf("Burst time = ");
        scanf("%d",&BurTime[ProcessNo]);
        RemainTime[ProcessNo]=BurTime[ProcessNo];
    }
      printf("The details for Time Quantum are as follows:\n");
    printf("The Time Quantum for First Round is 3.\n");
    TimeQuant=3;
    CompTime=0;
    for(ProcessNo=0;RemainProcess!=0;)
    {
        if(RemainTime[ProcessNo]<=TimeQuant && RemainTime[ProcessNo]>0)
        {
            CompTime+=RemainTime[ProcessNo];
            RemainTime[ProcessNo]=0;
            indic=1;
        }
        else if(RemainTime[ProcessNo]>0)
        {
            RemainTime[ProcessNo]-=TimeQuant;
            CompTime+=TimeQuant;
        }
        if(RemainTime[ProcessNo]==0 && indic==1)
        { printf("%d",ProcessNo);
            RemainProcess--;
            printf("P %d",ProcessNo+1);
            printf("\t\t\t%d",CompTime-ArivTime[ProcessNo]);
            printf("\t\t\t%d\n",CompTime-BurTime[ProcessNo]-ArivTime[ProcessNo]);
          Wait+=CompTime-ArivTime[ProcessNo]-BurTime[ProcessNo];
            TAT+=CompTime-ArivTime[ProcessNo];
            indic=0;
            
        }
        if(ProcessNo==no-1)
		{
            x++;
            if(x==2)
			{
            	ProcessNo=0;
            	TimeQuant=6;
            	printf("The Time Quantum for the second round is 6.\n");
			}
			else
			{
                break;
            }
        }
        else if(CompTime >= ArivTime[ProcessNo+1])
		{
            ProcessNo++;
        }
        else
		{
            ProcessNo=0;
        }
    }
     aakash(no,RemainTime,CompTime,ArivTime,BurTime);
    
    return 0;
}

    
    void aakash(int no,int RemainTime[10],int CompTime,int ArivTime[10],int BurTime[10])
	{
    	float AvgWait,AvgTAT;
    	int i,j,n=no,Temp,BTime[20],ProcessNo[20],WTime[20],TAT[20],Total=0,loc;
		printf("Third round with least burst time.\n");
		for(i=0;i<n;i++)
    	{
       		 BTime[i]=RemainTime[i];
        	WTime[i]=CompTime-ArivTime[i]-BurTime[i];
        	ProcessNo[i]=i+1;
    	}
    
    	for(i=0;i<n;i++)
   		{
        	loc=i;
        	for(j=i+1;j<n;j++)
        	{
            	if(BTime[j]<BTime[loc])
				{
                	loc=j;
            	}
        	}
        	Temp=BTime[i];
        	BTime[i]=BTime[loc];
        	BTime[loc]=Temp;
        	Temp=ProcessNo[i];
        	ProcessNo[i]=ProcessNo[loc];
        	ProcessNo[loc]=Temp;
    	}
    	for(i=1;i<n;i++)
   		{
        //	for(j=0;j<i;j++)
		//	{
         //  		WTime[i]+=BTime[j];
        //	}
        	Total+=WTime[i];
    	}
    
    	AvgWait=(float)Total/n;
    	Total=0;
    	printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");
    	for(i=0;i<n;i++)
    	{
        	TAT[i]=BTime[i]+WTime[i];
		    Total=Total + TAT[i];
        	printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",ProcessNo[i],BTime[i],WTime[i],TAT[i]);
    	}
   		AvgTAT=(float)Total/n;
    	printf("\n\nAverage waiting time = %f",AvgWait);
    	printf("\n Average turnaround time = %f\n",AvgTAT);
	}
