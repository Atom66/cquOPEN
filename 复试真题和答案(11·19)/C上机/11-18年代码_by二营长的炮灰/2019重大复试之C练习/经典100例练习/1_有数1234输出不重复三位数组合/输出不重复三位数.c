#include<stdio.h>
#define N 5 //�ٴ�1�����ܳ��ֵ�������4����Ҫд5 0-4

int isdifferent(int num);
int main()
{
/*
   int i , j ,k ,n;
  //1.������������˼�룺�������ǧ��λ���ظ���λ��
   //֮ǰ������1��n = i*100+j*10+k��sum = i*5+j*2+1��ͬ��nһ�������ظ����֣�
   for(i = 1 ; i <= 4 ; i++ )//ǧ
	   for(j = 1 ; j <= 4 ; j++ ) //��
		   for(k = 1 ; k <= 4 ; k++ ) //ʮ
		   {
			   if(i!=j && i!=k && k!=j ) //ijk��ͬnһ�������ظ�
			   {
				 n = i*100+j*10+k;
				 printf("%d\n",n);
			   }	  
		   }
}
*/
  int i;
  for(i = 1234 ; i <= 4321 ; i++)
  {
	  if(isdifferent(i))
		  printf("%d\t",i);
  }
  return 0; 
}
//[��]�ж�num�Ƿ�����ͬ��һλ����+ѭ����ȡ��λ����ģ��
int isdifferent(int num)
{
	int A[N] = {0},low;
	int temp = num;
	while(temp != 0)
	{
		low = temp%10;
		if(low==0 ||low>4 ||++A[low]>1)//�ٴ�2����Ҫ�ж�ֻ�ܳ���1-4
			return 0;
		temp = temp/10;
	}
	return 1; 
}