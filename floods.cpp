#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int find(int x,int parent[])
{
	if(parent[x]==x)
		return x;
	else
		return parent[x]=find(x,parent);
}
void uni(int k,int s,int parent[])
{
	int x=find(k,parent);
	int y=find(s,parent);
	parent[y]=x;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int parent[n+1];
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
	}
	for(int i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		if(find(a,parent)!=find(b,parent))
			uni(a,b,parent);
		//cout<<a<<" "<<b<<" "<<parent[b];
	}
	int count =0;
	cout<<"\n";
	for(int i=1;i<n+1;i++)
	{
		if(parent[i]==i)
			count++;
		//cout<<parent[i];
	}
	cout<<count;
	return 0;
}
