#include<stdio.h>
#define MAX 1000

int* findPower2(int N);
int main()
{
  int *p2,N ,i; 
  scanf("%d",&N); //ATTENTION 0��gets(&N)����ֻ�����ַ���
  p2 = findPower2(N);
  //����1����ȡint���鲻��strlen(p2),ֻ��sizeof(������)/sizeof(int)
  for(i = 0 ; p2[i] != -1; i++)
     printf("%4d",p2[i]);
  return 0;
}

/*
  ��������������ָ��N����2���ݴ���
  ������һ����a��2�ݴΣ�������Ʊ��� 100..0��ʽ��a-1 �� 011..1��ʽ
        ���ǰ�λ�� & ���Ϊ000..0
*/
int* findPower2(int N)
{
  int *p2 ,i,k = 0 ;
  p2 = (int*)malloc(sizeof(int)*MAX);
  for( i = 2 ; i < N ; i++)
  {
	  if((i & i-1) == 0) 
		  p2[k++] = i;
  }
  p2[k] = -1;//������ֹ����
  return p2;
}