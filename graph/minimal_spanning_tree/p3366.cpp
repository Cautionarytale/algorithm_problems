#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct edge{
	int u,v,w;
}e[maxn];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int n,m;
int fa[maxn];
int Find(int x){
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
int kruskal(){
	int ans=0,num=0;
	sort(e,e+m,cmp);
	for(int i=0;i<m;i++)
	{
		//int u=e[i].u,v=e[i].v,w=e[i].w;
		int faU=Find(e[i].u),faV=Find(e[i].v);
		if(faU!=faV){
			ans+=e[i].w;
			fa[faU]=faV;
			num++;
			if(num==n-1)return ans;
		}
		
	}
	 return -1;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		e[i].u=u;e[i].v=v;e[i].w=w;
	}
	iota(fa,fa+n+1,0);
	int ret=kruskal();
	if(ret==-1)cout<<"orz";
	else cout<<ret;
	return 0;
}
