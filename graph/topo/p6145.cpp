#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e5+10;
int n,m,c;
int s[maxn],ret[maxn],in[maxn];
vector<pii>G[maxn];
int main(){
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		ret[i]=s[i];
	}
	for(int i=0;i<c;i++)
	{
		int a,b,x;cin>>a>>b>>x;
		in[b]++;
		G[a].push_back({b,x});
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)q.push(i);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i].first,w=G[u][i].second;
			ret[v]=max(ret[v],ret[u]+w);
			in[v]--;
			if(in[v]==0)q.push(v);
		}
	}
	for(int i=1;i<=n;i++)cout<<ret[i]<<endl;
	return 0;
}
