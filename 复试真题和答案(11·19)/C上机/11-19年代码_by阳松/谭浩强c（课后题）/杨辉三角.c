#include <stdio.h>

//���������� 
#define SIZE 100
int main ()
{
	int i,j;
	int aux [SIZE][SIZE];
	for (i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			aux[i][j]=0;
		}		
	 } 
	

	for (i=0;i<10;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==0||j==i)			//����Ϊʲô���� Ū�ɸ�ֵ 
			{
				aux[i][j]=1;
			}else
			{
				aux[i][j]=aux[i-1][j-1]+aux[i-1][j];
			}
			printf("%d ",aux[i][j]);
		}
		printf("\n");
	 } 
	
	
	return 0;
} 
