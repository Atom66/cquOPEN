#include<stdio.h>

int main()
{
	int i , j , k ;
	for( i = 1 ; i <= 9; i++)
	{
     	for(j = i, k = 1 ; j > 0 ; j--,k++)  //��ӡj���ʽ
		{
			printf("%d*%d = %d",i,k,i*k);
			printf(" "); //ATTENTION 1 :��ӡ1�ո�ֱ������\t��ӡ̫��
		}
		printf("\n");//����
	}
    return 0;
}