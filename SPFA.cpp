#include <stdio.h>
#include <string.h>
int n,m,ts,te;
struct node
{
	int u,v,next;
	int w;
};
node edge[100000];
int first[3000];
int tot;
int dis[3000];
bool exist[3000];
int q[1000000];
int head;
int tail;
inline void add_edge(int x,int y,int z)
{
	edge[++tot].u=x;edge[tot].v=y;edge[tot].w=z;edge[tot].next=first[x];first[x]=tot;
	edge[++tot].u=y;edge[tot].v=x;edge[tot].w=z;edge[tot].next=first[y];first[y]=tot;
}
void SPFA(int s)
{
	dis[s]=0;
	head=0;
	tail=1;
	q[head]=s;
	exist[s]=true;
	while (head<tail)
	{
		int temp=q[head];
		head++;
		exist[temp]=false;
		for (int i=first[temp];i;i=edge[i].next)
		{
			int vv=edge[i].v;
			if (dis[temp]+edge[i].w<dis[vv])
			{
				dis[vv]=dis[temp]+edge[i].w;
				if (!exist[vv])
				{
					q[tail]=vv;
					tail++;
					exist[vv]=true;
				}
			}
		}
	}
}
int main()
{
	memset(exist,false,sizeof(exist));
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d%d",&n,&m,&ts,&te);
	for (int i=1;i<=m;i++)
	{
		int rs,re,ci;
		scanf("%d%d%d",&rs,&re,&ci);
		add_edge(rs,re,ci);
	}
	SPFA(ts);
	printf("%d",dis[te]);
	return 0;
}
