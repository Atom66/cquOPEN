#include <stdio.h>


//�����λ�����ڵĶԳ����� 
int main ()
{
	int i;
	int cnt=0;
	for(i=2;i<10001;i++)
	{
		if(is_balance(i)&&is_prime(i))
		{
			printf("%d",i);
			cnt++;
			if(cnt%10==0)
			{
				printf("\n");
			}else
			{
				printf(" ");
			}
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
	int i;
	int flag=1;//flag=1������������flag=0����������	
	if(x<2)
		flag=0;
	
	for(i=2;i<x-1;i++)
	{
		if(x%i==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
 
 
