#include <stdio.h>
//�û�����ָ�� n���� 1+2!+3!+...+n!�ĺ͡��磺
int factorial (int n);
int main ()
{
	int i,n;
	int ret=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		ret+=factorial(i);
	}
	
	printf("%d",ret);	
	return 0;
}

int factorial (int n)
{
	int i,sum=1;
	for(i=1;i<=n;i++)
	{
		sum=sum*i;
	}
	
	return sum;
	
}
