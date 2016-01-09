#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
bool  helper(vector<int> & arr,vector<char> &oper,int n,int r)
{
	if(oper.size()==n-1)
	{
		int prev=arr[0],curr,sum=arr[0],o;
		for(int i=0,j=1;i<oper.size();i++,j++)
		{
			char a=oper[i];
			curr=arr[j];
			if(a=='+')
				prev+=curr;
			else
				{
					prev-=curr;
					if(prev<0)cout<<prev;}
			
		}

			cout<<prev<<"\n";
		if(prev!=r)
			return false;
		else
			return true;
	}
	else
	{
		bool plus=true,minus=true;
		while(plus || minus)
		{
			if(plus)
			{
				oper.push_back('+');
				//cout<<oper.size()<<"+"<<"\n";
				if(helper(arr,oper,n,r))
				{
			//		cout<<"+";
					return true;
				}
				else
				{
					plus=false;
					oper.pop_back();
				}
			}
			else if(minus)
			{
				oper.push_back('-');
				//cout<<oper.size()<<"-"<<"\n";
				if(helper(arr,oper,n,r))
				{
			//		cout<<"-";
					return true;
				}
				else
				{
					minus=false;
					oper.pop_back();
				}
			}
		}
		return false;
	}
}
	
int main()
{
	int n;
	cin>>n;
	vector<int> arr;

	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		arr.push_back(k);
	}
	cout<<"rhs:";
	int r;
	cin>>r;
	vector<char>oper;
	if(!helper(arr,oper,n,r))
	{
		cout<<"not possible";
	}
	else
	{
		cout<<arr[0];
		for(int i=0,j=1;i<oper.size();i++,j++)
		{
			char a=oper[i];
			int curr=arr[j];
			if(a=='+')
				cout<<"+"<<curr;
			else
					cout<<"-"<<curr;
		
			
		}
		cout<<"="<<r;
	
	}
	return 0;
}

