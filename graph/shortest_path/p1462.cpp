#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int INF=0x3fffffff;
typedef pair<int,int> pii;
int n,m,b;
int f[maxn],dis[maxn];
bool vis[maxn];
vector<pii>G[maxn];
bool dijkstra(int s,int mid){
	fill(dis,dis+maxn,INF);
	fill(vis,vis+maxn,false);
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
			if(dis[v]>dis[u]+w&&f[v]<=mid){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	return dis[n]<=b;
}
int main(){
	cin>>n>>m>>b;
	for(int i=1;i<=n;i++)cin>>f[i];
	for(int i=0;i<m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	int ans=0,l=f[1],r=INF;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(dijkstra(1,mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	if(ans==0)cout<<"AFK";
	else cout<<ans;
	return 0;
}
