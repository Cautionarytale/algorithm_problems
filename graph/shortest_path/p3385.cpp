#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=2e3+10;
const int INF=0x3fffffff;
int n,m;
int dis[maxn],num[maxn],inq[maxn];
vector<pii>G[maxn];
bool spfa(int s){
	fill(dis,dis+maxn,INF);
	fill(num,num+maxn,0);
	fill(inq,inq+maxn,false);
	dis[s]=0;
	queue<int>q;
	q.push(s);inq[s]=true;
	while(!q.empty()){
		int u=q.front();q.pop();inq[u]=false;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i].first,w=G[u][i].second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				num[v]=num[u]+1;
				if(num[v]>=n)return true;
				if(!inq[v])q.push(v);
			}
		}
	}
	return false;
}
int main(){
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int u,v,w;cin>>u>>v>>w;
			G[u].push_back({v,w});
			if(w>=0)G[v].push_back({u,w});
		}
		if(spfa(1))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		for(int i=1;i<=n;i++)G[i].clear();
	}
	return 0;
}
