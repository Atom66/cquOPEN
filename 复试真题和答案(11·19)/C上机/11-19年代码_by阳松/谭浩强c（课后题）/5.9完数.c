#include <stdio.h>

//��һ���� �Ƿ��������������Ķ����ǣ�һ����ǡ�õ�����������֮�ͣ��������������
int  if_perfect_num(int x);
int main ()
{
	int i;
//	if_perfect_num(28);
	for(i=2;i<=1000;i++)
	{
		if(if_perfect_num(i))
		{
			printf("%d ",i);
		}
	}
	
	
	
 } 
 
 
int  if_perfect_num(int x)
{
	int n=x;
	int i;
	int sum=1;
	for(i=2;i<x;i++)
	{
		if(n%i==0)
		{
			sum+=i;
//			n/=i;
//			printf("%d ",i);
		}
//		if(n==1)
//		{
//			break;
//		}
	}
	
	if(sum==x)
	{
		return 1;	
	}else
	{
		return 0;
	}	
}
