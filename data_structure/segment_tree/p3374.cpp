//单点修改，区间查询 
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
struct node{
	int left,right;
	int val;
}tree[maxn*4];
int n,m;
int a[maxn],ans;
void build(int idx,int l,int r){
	tree[idx].left=l;tree[idx].right=r;
	if(l==r){
		tree[idx].val=a[l];
		return;
	}
	int mid=l+(r-l)/2;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,r);
	tree[idx].val=tree[idx<<1].val+tree[idx<<1|1].val;
	return;
}
void p_add(int idx,int dis,int k){//单点修改 
	if(tree[idx].left==tree[idx].right){
		tree[idx].val+=k;
		return;
	}
	if(dis<=tree[idx<<1].right)p_add(idx<<1,dis,k);
	else p_add(idx<<1|1,dis,k);
	tree[idx].val=tree[idx<<1].val+tree[idx<<1|1].val;//更新
	return; 
}
int search(int idx,int l,int r){//区间查询 
	if(tree[idx].left>=l&&tree[idx].right<=r){
		return tree[idx].val;
	}
	int ret=0;
	//if(tree[idx].right<l||tree[idx].left>r)return 0;
	if(tree[idx<<1].right>=l)ret+=search(idx<<1,l,r);
	if(tree[idx<<1|1].left<=r)ret+=search(idx<<1|1,l,r);
	return ret;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	while(m--)
	{
		int op;cin>>op;
		int x,y,k;
		if(op==1){
			cin>>x>>k;
			p_add(1,x,k);
		}else{
			cin>>x>>y;
			
			ans=search(1,x,y);
			cout<<ans<<endl;
		}
	}
	return 0;
}
