#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int MOD=100003;
const int INF=0x3fffffff;
typedef pair<int,int> pii;
int n,m;
vector<int>G[maxn];
int dis[maxn],num[maxn];
bool vis[maxn];
void dijkstra(int s){
	fill(dis,dis+maxn,INF);
	dis[s]=0;num[s]=1;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(dis[v]>dis[u]+1){
				num[v]=num[u];
				dis[v]=dis[u]+1;
				q.push({dis[v],v});
			}else if(dis[v]==dis[u]+1){
				num[v]=(num[u]+num[v])%MOD;
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dijkstra(1);
	for(int i=1;i<=n;i++)cout<<num[i]<<endl;
	return 0;
}
