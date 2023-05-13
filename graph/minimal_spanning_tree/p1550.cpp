#include<bits/stdc++.h>
using namespace std;
const int maxn=310;
struct edge{
	int u,v,w;
}e[maxn*maxn];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int n,cnt;
int fa[maxn];
int Find(int x){
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
int kruskal(){
	int ans=0,num=0;
	sort(e,e+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		int faU=Find(e[i].u),faV=Find(e[i].v);
		if(faU!=faV){
			fa[faU]=faV;
			num++;
			ans+=e[i].w;
		}
		if(num==n)return ans;
	}
	return -1;
}
int main(){

	cin>>n;
	iota(fa,fa+n+1,0);
	for(int i=1;i<=n;i++)
	{
		int w;cin>>w;
		e[cnt].u=0;e[cnt].v=i;e[cnt++].w=w;
		e[cnt].u=i;e[cnt].v=0;e[cnt++].w=w;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int w;cin>>w;
			if(i!=j){
				e[cnt].u=i;e[cnt].v=j;e[cnt++].w=w;
			}
		}
	cout<<kruskal();
	return 0;
}
