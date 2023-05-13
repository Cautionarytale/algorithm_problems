//求第k小的数字 
//对顶堆，所有add的数字都先进入大顶堆，保持大顶堆中的数字为k-1个且是前k-1个数字 
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m;
int a[maxn],u[maxn];
int idx;
priority_queue<int,vector<int>,greater<int>>s;
priority_queue<int>b;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>u[i];
	for(int i=1;i<=m;i++)
	{
		while(idx<u[i])
		{
			idx++;
			b.push(a[idx]);
			s.push(b.top());
			b.pop();
		}
		cout<<s.top()<<endl;
		b.push(s.top());s.pop();
	}
	return 0;
}
