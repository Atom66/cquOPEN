#include<stdio.h>
#define N 1000
#define MAX 100

int isPerfectNum(int num);
int main()
{
  int i;
  printf("%d���ڵ�ȫ����ȫ���ǣ�\n",N);
  for(i = 2 ; i <= N ; i++)
  {
	  if(isPerfectNum(i))
		  printf("%d  ",i);
  }
  return 0;
}
/*
  [��]�ж��Ƿ���ȫ��������ȫ+�������
      [ע]���ﲻ����ʽ�ֽ⣬�����ܱ�num��������������������
*/
int isPerfectNum(int num)
{
	int  temp = num , factors[MAX];
	int  sum = 0; 
	int i , j ;
	for(i = 1 ,j = 0 ; i < temp ; i++)
	{
		if(temp % i == 0)
		{
			factors[j++] = i;
			sum += i;
		}
	}
    return sum == num;
}






















/*
#include<stdio.h>
#include<stdlib.h>

int* perfectNum(int N);
int main()
{
  int N,i;
  int *pNum ;
  printf("������ָ��N���ڵ���ȫ����");
  scanf("%d",&N);
  pNum = perfectNum(N);
  for(i = 0 ; pNum[i] != 0 ; i++) //�����ȫ��
	  printf("%5d",pNum[i]);
  return 0;
}

//����N���ڵ���ȫ��
//��ȫ�� = ��������������֮�� ���� 6 = 1+2+3
int* perfectNum(int N)
{
	int *pNum = (int*)malloc(sizeof(int)*100);
	int i , j ,k = 0,sum ;
	for(i = 2 ; i<= N/2 ;i++) //ATTENTION 1 : Ѱ��������ֹ���� i<N --> i <= N/2 
	{
	  sum = 0;     //�״�1 ��ÿ�ν���ѭ��sum = 0 ��������i��ͳ������֮�ͣ�
      for(j = 1 ; j < i ; j++) //Ѱ��i���г�����������
	  {
         if( i % j == 0)  
			 sum += j; //����i��������,1��
	  }
	  if(sum == i) 
		  pNum[k++] = i;
	}
	pNum[k] = 0;//����int������ֹ����
	return pNum;
}
*/