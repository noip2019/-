#include<iostream>
#include<windows.h>
using namespace std;
int n,m,A[1000][1000],B[1000][1000],C[1000][1000];
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
	}//输入矩阵 
	int pn=1,pm=1;//主元位置 
	for(int i=1;i<=n;i++)//寻找非零行，进行置换，同时更新主元所在列,然后消元 
	{
		int flag=i;//非零行位置 
		while(pm<=m)
		{
			while(A[flag][pm]==0&&flag<=n)
			{
				flag++;
			}//寻找非零行 
			if(flag==n+1)
			{
				if(pm==m)break;
				flag=i;pm++;
			}//未找到非零行，主元变到下一列，继续找非零行 
			else if(flag<=n)
			{
				for(int k=1;k<=m;k++)
				{
					swap(A[flag][k],A[i][k]);
				}
				break;
			}//找到非零行，进行互换（自己和自己互换也行） 
		}
//		cout<<pm<<"&"<<endl;
//		print();cout<<endl;
		if(pm==m)//主元找到最后一列了 ,检验是否有解 
		{
//			cout<<"*"; 
			if(A[i][pm]==0)
			{
				break; 
			}
			else
			{
				cout<<"无解"<<endl;
				break;
			}
		}
		int a=A[i][pm];
		for(int j=i+1;j<=n;j++)//消元 
		{
			if(A[j][pm]==0)
			{
				continue;
			}
			else
			{
				int b=A[j][pm];
				for(int k=pm;k<=m;k++)
				{
					A[j][k]=a*A[j][k]-b*A[i][k];
				}
			}
		}
		pm++;//主元变到下一列 

	}
	print();
//	while(1)
//	{
//		system("pause");
//	}
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
