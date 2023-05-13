#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
const int INF=0x3fffffff;
int n,m;
int tim[maxn],f[maxn][maxn];
void Floyd(int k){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(f[i][j]>f[i][k]+f[k][j])
				f[j][i]=f[i][j]=f[i][k]+f[k][j];
		}
}
int main(){
	cin>>n>>m;
	fill(f[0],f[0]+maxn*maxn,INF);
	for(int i=0;i<n;i++)cin>>tim[i],f[i][i]=0;
	for(int i=0;i<m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		f[u][v]=f[v][u]=w;
	}
	int t;cin>>t;
	int now=0;
	while(t--){
		int x,y,t;cin>>x>>y>>t;
		if(tim[x]>t||tim[y]>t){
			cout<<-1<<endl;
			continue;
		}
		while(tim[now]<=t&&now<n)
			Floyd(now++);
		//cout<<f[x][y]==INF?-1:f[x][y]<<endl;
		if(f[x][y]==INF)cout<<-1<<endl;
		else cout<<f[x][y]<<endl;
	}
	return 0;
}
