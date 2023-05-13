#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m;
int lg[maxn],f[maxn][20];
int main(){
	cin>>n>>m;
	lg[1]=0;
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)scanf("%d",&f[i][0]);
	for(int j=1;j<=lg[n];j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(int i=0;i<m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		int k=lg[y-x+1];
		cout<<max(f[x][k],f[y-(1<<k)+1][k])<<'\n';
	}
	return 0;
}
