//区间修改，单点查询
//建树时除叶子节点外，值均为0 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n,m,ans;
int a[maxn];

struct node{
	int left,right;
	ll sum;
}tree[4*maxn];
void build(int idx,int l,int r){
	tree[idx].left=l;tree[idx].right=r;
	if(l==r){
		tree[idx].sum=a[l];
		return;
	}
	int mid=l+(r-l)/2;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,r);
//	tree[idx].sum=tree[idx<<1].sum+tree[idx<<1|1].sum;
	return;
}
void q_add(int idx,int l,int r,int k){//区间修改 
	if(tree[idx].left>=l&&tree[idx].right<=r){
		tree[idx].sum+=k;
		return;
	}
	if(l<=tree[idx<<1].right)q_add(idx<<1,l,r,k);
	if(r>=tree[idx<<1|1].left)q_add(idx<<1|1,l,r,k);
}
void p_search(int idx,int dis){
	ans+=tree[idx].sum;
	if(tree[idx].left==tree[idx].right)return;
	if(dis<=tree[idx<<1].right)p_search(idx<<1,dis);
	if(dis>=tree[idx<<1|1].left)p_search(idx<<1|1,dis);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	while(m--)
	{
		int op;cin>>op;
		if(op==1){
			int x,y,k;cin>>x>>y>>k;
			q_add(1,x,y,k);
		}else{
			int x;cin>>x;
			ans=0;
			p_search(1,x);
			cout<<ans<<endl;
		}
	}
	return 0;
}
