#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<limits.h>
#include<cstring>
using namespace std;
int main()
{
	
	int n,d;
	cin>>n>>d;
	vector<int>adj[n+1];
	for(int i=0;i<d;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	int minn=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		int invites=0;
		bool visit[n+1];
		memset(visit,false,sizeof visit);
		queue<int>q;
		q.push(i);
		visit[i]=true;
		while(!q.empty())
		{
			int top=q.front();
			cout<<top << " ->";
			invites+=adj[top].size();
			for(int i=0;i<adj[top].size();i++)
			{
				if(visit[adj[top][i]]==false)
				{
					q.push(adj[top][i]);
					visit[adj[top][i]]=true;
				}
			}
			q.pop();
		}
		cout<<i<<invites<<"\n";
		if(invites<minn)
			minn=invites;
	}
	cout<<minn;
	return 0;
}

