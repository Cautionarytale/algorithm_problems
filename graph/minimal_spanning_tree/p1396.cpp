#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int INF=0x3fffffff;
typedef pair<int,int> pii;
vector<pii>G[maxn];
int n,m,s,t;
int dis[maxn];
bool vis[maxn];
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
			if(dis[v]>dis[u]+w&&w<=mid){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	if(dis[t]==INF)return false;
	return true;
}
int main(){
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	int ans=0,l=0,r=INF;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(dijkstra(s,mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans;
	return 0;
}
