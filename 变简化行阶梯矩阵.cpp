#include<iostream>
using namespace std;
int n,m,A[1000][1000];
void print();
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>A[i][j];
		}
	}//输入阶梯矩阵
	for(int i=n;i>=1;i--)
	{
		int pm=0;//主元所在列 
		for(int j=1;j<=m;j++)
		{
			if(A[i][j]!=0)
			{
				pm=j;
				break;
			}
		}
		if(pm==0)
		{
			continue;
		}//未找到主元
		else if(pm==m)
		{
			cout<<"无解"<<endl;
			break;
		}//仅有常数项，无解 
		else
		{
			int a=A[i][pm];
		 	for(int j=i-1;j>=1;j--)
		 	{
		 		int b=A[j][pm];
		 		for(int k=1;k<=m;k++)
		 		{
		 			A[j][k]=A[j][k]*a-A[i][k]*b;
				}
			}
		}//找到主元，消元 
	}//寻找每一行的主元	
	print();cout<<endl;
} 
void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<A[i][j]<<"    ";
		}
		cout<<endl;
	}
}
