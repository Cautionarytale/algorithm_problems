#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m,p,input[maxn];
struct node{
	int left,right;
	ll sum,mlz,plz;
}tree[maxn<<2];
void build(int idx,int l,int r){
	tree[idx].left=l;tree[idx].right=r;tree[idx].mlz=1;
	if(l==r){
		tree[idx].sum=input[l];
		return;
	}
	int mid=l+(r-l)/2;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,r);
	tree[idx].sum=tree[idx<<1].sum+tree[idx<<1|1].sum;
}
inline void pushdown(int idx){
	ll k1=tree[idx].mlz,k2=tree[idx].plz;
	tree[idx<<1].sum=tree[idx<<1].sum*k1+k2*(tree[idx<<1].right-tree[idx<<1].left+1);
	tree[idx<<1|1].sum=tree[idx<<1|1].sum*k1+k2*(tree[idx<<1|1].right-tree[idx<<1|1].left+1);
	tree[idx<<1].mlz*=k1;
	tree[idx<<1|1].mlz*=k1;
	tree[idx<<1].plz=tree[idx<<1].plz*k1+k2;
	tree[idx<<1|1].plz=tree[idx<<1|1].plz*k1+k2;
	tree[idx].plz=0;
	tree[idx].mlz=1;
}
void mul(int idx,int l,int r,ll k){
	if(tree[idx].right<l||tree[idx].left>r)return;
	if(tree[idx].left>=l&&tree[idx].right<=r){
		tree[idx].sum*=k;
		tree[idx].plz*=k;
		tree[idx].mlz*=k;
		return;
	}
	pushdown(idx);
	if(tree[idx<<1].right>=l)mul(idx<<1,l,r,k);
	if(tree[idx<<1|1].left<=r)mul(idx<<1|1,l,r,k);
	tree[idx].sum=tree[idx<<1].sum+tree[idx<<1|1].sum;
}
void add(int idx,int l,int r,ll k){
	if(tree[idx].left>r||tree[idx].right<l)return;
	if(tree[idx].left>=l&&tree[idx].right<=r){
		tree[idx].sum+=k*(tree[idx].right-tree[idx].left+1);
		tree[idx].plz+=k;
		return;
	}
	pushdown(idx);
	if(tree[idx<<1].right>=l)add(idx<<1,l,r,k);
	if(tree[idx<<1|1].left<=r)add(idx<<1|1,l,r,k);
	tree[idx].sum=tree[idx<<1].sum+tree[idx<<1|1].sum;
}
ll search(int idx,int l,int r){
	if(tree[idx].left>r||tree[idx].right<l)return 0;
	if(tree[idx].left>=l&&tree[idx].right<=r){
		return tree[idx].sum;
	}
	pushdown(idx);
	ll ret=0;
	if(tree[idx<<1].right>=l)ret+=search(idx<<1,l,r);
	if(tree[idx<<1|1].left<=r)ret+=search(idx<<1|1,l,r);
	return ret;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>input[i];
	build(1,1,n);
	while(m--){
		int op,x,y,k;cin>>op;
		if(op==1){
			cin>>x>>y>>k;
			add(1,x,y,k);
		}else{
			cin>>x>>y;
			cout<<search(1,x,y)<<endl;
		}
	}
	return 0;
}
