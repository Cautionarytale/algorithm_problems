#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int n,m;
vector<int>G[maxn];
int in[maxn];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		in[v]++;
	}
	queue<int>q,qq;
	bool flag=false;
	int num1=0;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)q.push(i),qq.push(i),num1++;
	}
	if(num1>1)flag=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		int num2=0;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			in[v]--;
			if(in[v]==0)q.push(v),qq.push(v),num2++;
		}
		if(num2>1)flag=true;
	}
	while(!qq.empty())cout<<qq.front()<<endl,qq.pop();
	cout<<flag;
	
	return 0;
}
