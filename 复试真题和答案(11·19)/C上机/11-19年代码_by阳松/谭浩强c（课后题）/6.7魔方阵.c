#include <stdio.h>

//���ħ��������ÿһ�� ��ÿһ�У��Խ���֮�Ͷ���� 
#define M 100
int main ()
{
	int aux [M][M];
	int n;
	int i,j,k;
	scanf("%d",&n);
	 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			aux[i][j]=0;
		}
	}
	
	i=0;j=n/2;
	aux[i][j]=1;
	for(k=2;k<=n*n;k++)
	{
		if(i==0&&j==n-1)		//�ܲ��� �ж���ȵ�ʱ��Ҫ�ø�ֵ�� 
		{
			i++;
		}else 
		{
			i=(i-1+n)%n;
			j=(j+1)%n;
		}
		if(aux[i][j]==0)
		{
			aux[i][j]=k;
		}else
		{
			i=i+2;
			j=j-1;
			aux[i][j]=k;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",aux[i][j]);
		}
		printf("\n");
	}
	
	return 0;	
} 
