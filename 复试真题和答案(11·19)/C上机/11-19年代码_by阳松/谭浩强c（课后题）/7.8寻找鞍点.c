#include <stdio.h>

//�ҳ�һ����ά�����е� ���㣬����������ڸ�������С
//4 5									
//1 2 3 4 5
//2 4 6 8 10
//3 6 9 12 15
//4 8 12 16 20
//4 5
//1 2 3 4 11
//2 4 6 8 12
//3 6 9 10 15
//4 8 12 16 7
#define M 100 

int main ()
{
	int aux[M][M];
	int i,j,k;
	int max;
	int n,m;//nΪ������mΪ���� 
	int flag;
	int row,col;//row �б꣬col�б� 
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&aux[i][j]);
		}
	}
	

	
	for(i=0;i<n;i++)
	{
		flag=1;
		max=aux[i][0];
		row=i;
		col=0;
		for(j=1;j<m;j++)			//�ҳ������Ԫ�� 
		{
			if(aux[i][j]>max)
			{
				row=i;
				col=j;
				max=aux[i][j];
			}			
		}
		for(k=0;k<n;k++)		//�ж��Ƿ�������СԪ�� 
		{
			if(aux[row][col]>aux[k][col]) 
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("�ҵ�����aux[%d][%d]=%d",row,col,aux[row][col]);
		}else
		{
			printf("δ�ҵ�����");
		}
	}
	
	
	
	return 0;
 } 
 
//int ismax_col(int *aux,int m,int n) 
//{
//	int i,j;
//	for(j=0;j<n;)
//}
