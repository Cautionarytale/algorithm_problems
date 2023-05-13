#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int INF=2e31-1;
typedef pair<int,int> pii;
int n,m,s;
vector<pii>G[maxn];
int dis[maxn];
bool vis[maxn];
void dijkstra(int s){
	fill(dis,dis+maxn,INF);
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i].first,w=G[u][i].second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	cin>>n>>m>>s;
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		G[u].push_back({v,w});
	}
	dijkstra(s);
	for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
	return 0;
}
