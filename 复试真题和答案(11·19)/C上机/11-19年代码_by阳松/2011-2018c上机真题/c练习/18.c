#include <stdio.h>
//һ�������ǡ�õ�����������֮�ͣ�1 �ǣ������ǣ���������ͳ�Ϊ"����
//���� 6=1 ��2��3.����ҳ� N���ڵ�����������
int is_perfect (int x);

int main ()
{
	int i;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(is_perfect(i))
		{
			printf("%d ",i);
		}
	}
	

	return 0;
} 

int is_perfect (int x)
{
	int sum=0,i;
	for(i=1;i<x;i++)
	{
		if(x%i==0)
		{
			sum+=i;
		}

	}
	
	if(sum==x)
	{
		return 1;
	}else
	{
		return 0;
	}
	
}
