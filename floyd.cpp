#include <stdio.h>
#include <string.h>
int d[1001][1001];
int path[1001][1001];
void dfs(int i,int j)
{
	if (path[i][j]!=-1)
	{
	dfs(i,path[i][j]);
	printf("%d ",path[i][j]);
	dfs(path[i][j],j);
	}
}
int n,m,s,t;
int main()
{
	memset(d,0x7f/2,sizeof(d));
	memset(path,-1,sizeof(path));
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i=1;i<=m;i++)
	{
		int uu,vv,w;
		scanf("%d%d%d",&uu,&vv,&w);
		d[uu][vv]=d[vv][uu]=w;
	}
	for (int i=1;i<=n;i++)
	d[i][i]=0;
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (d[i][k]+d[k][j]<d[i][j])
	{
	d[i][j]=d[i][k]+d[k][j];
	path[i][j]=k;
	}
	printf("%d\n",d[s][t]);
	printf("%d ",s);
	dfs(s,t);
	printf("%d",t);
	return 0;
}

