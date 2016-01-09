#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

int n;
bool findplace(vector< vector<string> > & str, vector<string>  & board,vector<bool> & dia1,vector<bool> & dia2,vector<bool> & col,int row,int q)
{
	int dia=(2*n)-1;
	/*for(int i=0;i<n;i++)
		cout<<col[i];
	cout<<"\n";
	for(int i=0;i<dia;i++)
		cout<<dia1[i]<<dia2[i];
	*/
	if(q==0)
	 {
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<board[i][j];
			cout<<"\n";
		}
		str.push_back(board);
	}
	else
	{
		bool res=false;
		for(int i=0;i<n;i++)
		{
			if(!res && col[i]==1 && dia1[row+i]==1 && dia2[(n-1)+row-i]==1 )
			{		//cout<<col[i];
				col[i]=false;
				dia1[row+i]=false;
				dia2[(n-1)+row-i]=false;
				board[row][i]='Q';		
				res=findplace(str,board,dia1,dia2,col,row+1,q-1);
				if(res)
				{
					board[row][i]='Q';			
				//	return true;
				}
				
					//cout<<"backtrack";
					col[i]=true;
					dia1[row+i]=true;
					dia2[(n-1)+row-i]=true;
					board[row][i]='.';
				
			}
		}
		return res;
	}
}
int main()
{
	 vector<string> board;
	//int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string t;
		for(int j=0;j<n;j++)
		{
		t.push_back('.');
		}
		board.push_back(t);
	}
	int dia=(2*n)-1;
	vector<bool> col,dia1,dia2;
	vector < vector <string> >str;
	for(int i=0;i<n;i++)
		col.push_back(true);
	for(int i=0;i<dia;i++)
		dia1.push_back(true);
	for(int i=0;i<dia;i++)
		dia2.push_back(true);
	findplace(str,board,dia1,dia2,col,0,n);
	return 0;
}
