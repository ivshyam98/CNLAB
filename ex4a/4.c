#include<stdio.h>
void dijkstra(int,int [20][20],int [20],int [20],int);
void main()
{
	int i,j,n,visited[20],source,cost[20][20],dist[20];
	printf("Enter no of vertices:");
	scanf("%d",&n);

	printf("Enter the cost adjacency matrix\n");
	for(i=1;i<=n;i++)
	{
 	  for(j=1;j<=n;j++)

 	  {
  	    scanf("%d",&cost[i][j]);
  	  }
	}

	printf("\nEnter the source node:");
	scanf("%d",&source);

	dijkstra(source,cost,visited,dist,n);

	for(i=1;i<=n;i++)
 	if(i!=source)
  		printf("\nShortest path from %d to %d is %d",source,i,dist[i]);
    return 0;
}

void dijkstra(int source,int cost[20][20],int visited[20],int dist[20],int n)
{
	int i,j,min,u,w;

	for(i=1;i<=n;i++)
	{
  	   visited[i]=0;
 	   dist[i]=cost[source][i];
         
    }

	visited[source]=1;
	dist[source]=0;

	for(j=2;j<=n;j++)
	{
 	  min=999;
 	  for(i=1;i<=n;i++)
 	  {
  	    if(!visited[i])
  	    {
    		 if(dist[i]<min)
   		 {
    	  	  min=dist[i];
    		  u=i;
  		 }
  	    }
	  }
 		visited[u]=1;

	 	for(w=1;w<=n;w++)
	  	{
	 	 if(cost[u][w]!=999&&visited[w]==0)
	   	{
	   	if(dist[w]>cost[u][w]+dist[u])
	   	  dist[w]=cost[u][w]+dist[u];
	  	}
	    }
   	}
}
