#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
string s;
struct node{
	int w;
	int l,r;
	bool operator<(const node &b)const{
		if(w!=b.w)return w>b.w;
		else return l>b.l;
	}
};
priority_queue<node>q;
int a[maxn],l[maxn],r[maxn],ansl[maxn],ansr[maxn];
int cnt;
bool vis[maxn];
int main(){
	cin>>n;
	s+='A';
	string ss;cin>>ss;
	s+=ss;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)
	{
		if(s[i]!=s[i+1])q.push((node){abs(a[i]-a[i+1]),i,i+1});
	}
	for(int i=1;i<=n;i++)l[i]=i-1,r[i]=i+1;
	while(!q.empty()){
		node tmp=q.top();q.pop();
		int x=tmp.l,y=tmp.r;
		if(!vis[x]&&!vis[y]){
			l[r[y]]=l[x];
			r[l[x]]=r[y];
			cnt++;
			ansl[cnt]=x,ansr[cnt]=y;
			vis[x]=vis[y]=1;
			if(!vis[l[x]]&&!vis[r[y]]&&l[x]>=1&&r[y]<=n){
				if(s[l[x]]!=s[r[y]])q.push((node){abs(a[l[x]]-a[r[y]]),l[x],r[y]});
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)cout<<ansl[i]<<' '<<ansr[i]<<endl;
	return 0;
}
