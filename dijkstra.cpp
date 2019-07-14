#include <stdio.h>
#include <string.h>
int d[1001];
int start;
int map[1001][1001];
int exist[1001];
int n,m,t;
int inf=0x7f/2;
int path[1001];
void dfs(int now)
{
	if (now!=start) dfs(path[now]);
	printf("%d ",now);
}
int main()
{
	memset(map,inf,sizeof(map));
	for (int i=1;i<=n;i++)
	map[i][i]=0;
	scanf("%d%d%d%d",&n,&m,&start,&t);
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		map[u][v]=map[v][u]=w;
	}
	for (int i=1;i<=n;i++)
	d[i]=map[start][i],exist[i]=false,path[i]=start;
	exist[start]=true;
	for (int i=2;i<=n;i++)
	{
		int temp=inf;
		int k=0;
		for (int j=1;j<=n;j++)
		if (!exist[j]&&d[j]<temp)
		temp=d[j],k=j;
		if (temp==inf) break;
		exist[k]=true;
		for (int j=1;j<=n;j++)
		if (!exist[j]&&d[k]+map[k][j]<d[j])
		d[j]=d[k]+map[k][j],path[j]=k;
	}
	printf("%d\n",d[t]);	
	dfs(path[t]);
	printf("%d",t);
	return 0;
}
