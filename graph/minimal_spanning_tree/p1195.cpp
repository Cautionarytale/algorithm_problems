#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
const int maxe=1e4+10;
const int INF=0x3fffffff;
struct edge{
	int u,v,w;
}e[maxe];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[maxn];
int n,m,k;
int Find(int x){
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
int kruskal(){
	int ans=0,num=0;
	sort(e,e+m,cmp);
	for(int i=0;i<m;i++)
	{
		int faU=Find(e[i].u),faV=Find(e[i].v);
		if(faU!=faV){
			num++;
			ans+=e[i].w;
			fa[faU]=faV;
		}
		if(num==n-k)return ans;
	}
	return -1;
}
int main(){
	
	cin>>n>>m>>k;
	iota(fa,fa+n+1,0);
	for(int i=0;i<m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		e[i].u=u;e[i].v=v;e[i].w=w;
	}
	int ret=kruskal();
	if(ret==-1)cout<<"No Answer";
	else cout<<ret;
	return 0;
}
