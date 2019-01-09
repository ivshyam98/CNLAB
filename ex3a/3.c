#include<stdio.h>
#include<stdlib.h>
int min(int x,int y)
{
 if(x>y)
return y;
else
return x;
}
void belman(int source,int cost[10][10],int dist[20],int n)
{
int i,k,j;
for(i=1;i<=n;i++)
{
	if(i!=source)
		dist[i]=999;
	else
		dist[i]=0;
}
for(k=1;k<=n;k++)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
dist[j]=min(dist[j],dist[i]+cost[i][j]);
}
}
}
for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(dist[j]>dist[i]+cost[i][j])
			{
				printf("\nThe Graph contains Negative Cycles!\n");
				exit(0);
			}
		}	
	}
}
void main()
{
int i,j,n,source,cost[10][10],dist[20];
printf("Enter no of vertices\n");
scanf("%d",&n);
printf("Enter the Cost matrix\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
}
}
printf("Enter the source node\n");
scanf("%d",&source);

belman(source,cost,dist,n);
for(i=1;i<=n;i++)
{
if(i!=source)
printf("Distance from soure %d to node %d is %d\n",source,i,dist[i]);
}
}
