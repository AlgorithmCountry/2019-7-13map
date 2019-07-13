#include <stdio.h>
int n,m;
struct node
{
	int u,v,next;	
};
node edge[1001];
int first[2002];
int tot=0;
int visited[1001];
inline void add_edge(int x,int y)
{
	edge[++tot].u=x;edge[tot].v=y;edge[tot].next=first[x];first[x]=tot;
	edge[++tot].u=y;edge[tot].v=x;edge[tot].next=first[y];first[y]=tot;
}
void dfs(int now)
{
	for (int i=first[now];i;i=edge[i].next)
	{
		int vv=edge[i].v;
		if (!visited[vv])
		visited[vv]=1,dfs(vv);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
    }
    int ans=0;
	for (int i=1;i<=n;i++)
	if (!visited[i])
	ans++,visited[i]=1,dfs(i);
	printf("%d",ans);
	return 0;
}
