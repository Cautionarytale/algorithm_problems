#include<bits/stdc++.h>
using namespace std;
const int maxn=250010;
struct edge{
	int u,v,w;
}e[maxn];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int a,b,idx;
int fa[maxn];
int Find(int x){
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
int kruskal(){
	sort(e,e+b*b,cmp);
	int ans=0,num=0;
	for(int i=0;i<b*b;i++)
	{
		int faU=Find(e[i].u),faV=Find(e[i].v);
		if(faU!=faV){
			num++;
			ans+=e[i].w;
			fa[faU]=faV;
		}
		if(num==b-1)return ans;
	}
	return -1;
}
int main(){
	cin>>a>>b;
	iota(fa,fa+b+1,0);
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int w;cin>>w;
			if(w==0&&i!=j)w=a;
			w=min(w,a);
			e[idx].u=i;e[idx].v=j;e[idx++].w=w;
		}
	}
	int ret=kruskal();
	cout<<ret+a;
	return 0;
}
