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
	}//������ݾ���
	for(int i=n;i>=1;i--)
	{
		int pm=0;//��Ԫ������ 
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
		}//δ�ҵ���Ԫ
		else if(pm==m)
		{
			cout<<"�޽�"<<endl;
			break;
		}//���г�����޽� 
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
		}//�ҵ���Ԫ����Ԫ 
	}//Ѱ��ÿһ�е���Ԫ	
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
