//ά����λ��
//�Զ��ѣ��󶥶Ѵ�Ž�С������С���Ѵ�Žϴ������ʼ��ά������������� 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
priority_queue<int,vector<int>,greater<int>>s;
priority_queue<int>b;
int n;
int val;
int main(){
	cin>>n>>val;
	b.push(val);cout<<b.top()<<endl;
	for(int i=2;i<=n;i++)
	{
		cin>>val;
		if(val<b.top())b.push(val);
		else s.push(val);
		if(abs((double)b.size()-(double)s.size())>1){
			if(b.size()>s.size())s.push(b.top()),b.pop();
			else b.push(s.top()),s.pop();
		}
		if(i&1)cout<<(b.size()>s.size()?b.top():s.top())<<endl;
	}
	
	return 0;
}
