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
	}//������� 
	int pn=1,pm=1;//��Ԫλ�� 
	for(int i=1;i<=n;i++)//Ѱ�ҷ����У������û���ͬʱ������Ԫ������,Ȼ����Ԫ 
	{
		int flag=i;//������λ�� 
		while(pm<=m)
		{
			while(A[flag][pm]==0&&flag<=n)
			{
				flag++;
			}//Ѱ�ҷ����� 
			if(flag==n+1)
			{
				if(pm==m)break;
				flag=i;pm++;
			}//δ�ҵ������У���Ԫ�䵽��һ�У������ҷ����� 
			else if(flag<=n)
			{
				for(int k=1;k<=m;k++)
				{
					swap(A[flag][k],A[i][k]);
				}
				break;
			}//�ҵ������У����л������Լ����Լ�����Ҳ�У� 
		}
//		cout<<pm<<"&"<<endl;
//		print();cout<<endl;
		if(pm==m)//��Ԫ�ҵ����һ���� ,�����Ƿ��н� 
		{
//			cout<<"*"; 
			if(A[i][pm]==0)
			{
				break; 
			}
			else
			{
				cout<<"�޽�"<<endl;
				break;
			}
		}
		int a=A[i][pm];
		for(int j=i+1;j<=n;j++)//��Ԫ 
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
		pm++;//��Ԫ�䵽��һ�� 

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
