#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,lg[maxn],f[maxn][22];
int main(){
	cin>>n>>m;
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)cin>>f[i][0];
	for(int j=1;j<=lg[n];j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n-m+1;i++)
	{
		int l=i,r=i+m-1;
		int k=lg[r-l+1];
		cout<<min(f[l][k],f[r-(1<<k)+1][k])<<endl;
	}
	
	return 0;
}
