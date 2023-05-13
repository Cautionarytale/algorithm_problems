#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int n,in[maxn];
vector<int>G[maxn];
int main(){
	set<int>st;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int u,m;cin>>u>>m;
		st.insert(u);
		for(int j=0;j<m;j++)
		{
			int v;cin>>v;
			//if(v>n||u>n)continue;
			in[v]++;
			G[u].push_back(v);
		}
	}
	queue<int>q;
	int num=n;
	for(int i=1;i<=maxn;i++){
		if(in[i]==0&&st.count(i)){
			num--;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(!st.count(v))continue;
			in[v]--;
			if(in[v]==0)q.push(v),num--;
		}
	}
	if(num==0)cout<<"YES";
	else cout<<num;
	return 0;
}
