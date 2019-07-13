#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int n,m;
int map[1001][1001];
int visited[1001];
void dfs(int now)
{
	for (int i=1;i<=n;i++)
	if (!visited[i]&&map[now][i]==1)
	{
		visited[i]=1;dfs(i);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		map[x][y]=map[y][x]=1;
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	if (!visited[i])
	ans++,visited[i]=1,dfs(i);
	printf("%d",ans);
	return 0;
}
