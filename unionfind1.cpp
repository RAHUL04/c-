#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int find(int s,int parent[])
{
	while(parent[s]!=s)
	{
		s=parent[s];
	}
	return s;
}

void uni(int x,int y,int parent[],int size[])
{
	int rootx=find(x,parent);
	int rooty=find(y,parent);
	if(rootx==rooty)
		return ;
	int sum=size[rootx]+size[rooty];


	if(size[rootx]<size[rooty])
	{
		parent[rootx]=y;
		size[rooty]=sum;
	}
	else
	{
		parent[rooty]=x;
		size[rootx]=sum;
	}
}

int main()
{
	int n;
	cin>>n;
	char arr[n];
	int parent[n+1];
	int size[n+1];
	for(int i=0;i<n;i++)
	{
		 cin>>arr[i];
		parent[i+1]=i+1;
		size[i+1]=1;
	}
	int t=3;
	while(t--)
	{

		int x,y;char e;
		cout<<"enter the x";
		cin>>x;
		cout<<"enter the y";
		cin>>y;
		uni(x,y,parent,size);
		//cout<<"end?";
		//cin>>e;
		//if(e=='.');
		//	break;
		
	}

	for(int i=1;i<=n;i++)
	{
		cout<<parent[i];
		//cout<<size[i];
	}
	cout<<"\n";
	for(int i=1;i<=n;i++)
	{
		//cout<<parent[i];
		cout<<size[i];
	}
	return 0;
}
	
		


