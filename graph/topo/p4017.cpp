#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
#define MOD 80112002 
int n,m;
vector<int>G[maxn];
int num[maxn],in[maxn],out[maxn];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		in[v]++;out[u]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0){
			num[i]=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			in[v]--;
			num[v]=(num[u]+num[v])%MOD;
			if(in[v]==0)q.push(v);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(out[i]==0)ans=(ans+num[i])%MOD;
	cout<<ans;
	return 0;
}
