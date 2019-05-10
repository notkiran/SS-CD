#include <stdio.h>
#include <stdlib.h>
int main()
{
int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10],
safeSequence[10];
int p,r,i,j,process,count;
count=0;
printf("Enter the no of processes : ");
scanf("%d", &p);
for(i=0;i<p;i++)
completed[i] = 0;
printf("\n\n Enter the no of resources : ");
scanf("%d", &r);
printf("\n\n Enter the Max Matrix for each process : ");
for(i=0;i<p;i++)
{
printf("\n For process %d : ", i + 1);
for(j=0;j<r;j++)
scanf("%d",&Max[i][j]);
}
printf("\n\n Enter the allocation for each process : ");
for(i=0;i<p;i++)
{
printf("\n For process %d : ",i + 1);
for(j=0;j<r;j++)
scanf("%d",&alloc[i][j]);
}
printf("\n\n Enter the Available Resources : ");
for(i=0;i<r;i++)
scanf("%d", &avail[i]);
for(i=0;i<p;i++)
for(j=0;j<r;j++)
need[i][j]=Max[i][j]-alloc[i][j];
do
{
printf("\n Max matrix:\t Allocation matrix:\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
printf("%d",Max[i][j]);
printf("\t\t");
for(j=0;j<r;j++)
printf("%d",alloc[i][j]);
printf("\n");
}
process=-1;
for(i=0;i<p;i++)
{
if(completed[i]==0)
{
process=i;
for(j=0;j<r;j++)
{
if(avail[j]<need[i][j])
{
process=-1;
break;
}
}
if(process!=-1)
break;
}
if(process!=-1)
{
printf("\n Process %d runs to completion!",process+1);
safeSequence[count]=process+1;
count++;
for(j=0;j<r;j++)
{
avail[j]+=alloc[process][j];
alloc[process][j]=0;
Max[process][j]=0;
completed[process]=1;
}
}
}
while(count!=p && process!=-1);
if(count==p)
{
printf("\n The system is in a safe state!!\n");
printf("Safe Sequence : <");
for(i=0;i<p;i++)
printf("%d",safeSequence[i]);
printf(">\n");
}
elses
printf("\n The system is in an unsafe state!!");
}
