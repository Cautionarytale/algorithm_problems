#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m;
bool f[maxn][maxn];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;cin>>u>>v;
		f[u][v]=1;
	}
	for(int i=1;i<=n;i++)f[i][i]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=f[i][j]|f[i][k]&f[k][j];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		bool flag=true;//表示点i与其余所有点均连通
		for(int j=1;j<=n;j++)
			flag&=f[i][j]|f[j][i];
		ans+=flag; 
	}
	cout<<ans;
	return 0;
}
