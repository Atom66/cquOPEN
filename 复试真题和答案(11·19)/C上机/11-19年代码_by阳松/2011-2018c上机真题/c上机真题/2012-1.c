#include <stdio.h> 
//�ж��Ƿ�Գ����� 
int main ()
{
	int x;
	while (scanf("%d",&x)!=EOF)
	{
		if(is_balance (x)&&is_prime (x)) 
		{
			printf("%d�ǶԳ�����",x);
		}else
		{
			printf("%d���ǶԳ�����",x);
		}
	}
	
	return 0;
}

int is_balance (int x)
{
	int n;
	int sum=0;
	n=x;
	while (n>0)
	{
		sum=sum*10+n%10;
		n/=10;
	}
	if(sum==x)
	{
		return 1;
	}else
	{
		return 0;
	}
	
 } 
 
 
int is_prime (int x)
{
	int flag=1;
	int i;
	
	if(x<2)
	{
		flag=0;
	}
	for(i=2;i<x;i++)
	{
		if(x%i==0)
		{
			flag=0;
		}
	}
	
	return flag; 
}
