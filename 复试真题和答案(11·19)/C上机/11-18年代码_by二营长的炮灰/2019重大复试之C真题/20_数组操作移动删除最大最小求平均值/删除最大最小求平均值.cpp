#include<stdio.h>
#define MAX 100

void del(int A[],int len, int p1 , int p2);
int main()
{
  int A[MAX] = {0}; //ATTENTION0 : {0}��ȫ����ʼ0��{1}ֻA[0]=1����0
  int i,min,max,len;
  float average , sum = 0;  //�״�1������sum��ʼ��ʹ�û�����ֵ���
  i = max = min = len = 0;
  /*
    1.ATTENTION 1��������ֵ��ctrl+c�˳�
	2.ʹ��while + scanf������ֵ����getchar()��ȡ�ո�/�س�
	3.���ܻ����޴���ox4001005���󣬸�����ԡ�
  */
  while((scanf("%d",&A[i++])) != EOF)
	  getchar(); 
  len = i - 1;
  for(i = 1; i < len ; i++)//����һ�α���Ѱ�ҵ�������С
  {
	 if(A[i] < A[min])
	   min = i;
	 else if(A[i] > A[max]) //ע��else if
	   max = i;
  }
  del(A,len,min,max);
  len = len - 2; //��¼ɾ�������鳤��
  for(i = 0; i < len ; i++)
    sum += A[i];
  average = sum / len;
  printf("ƽ��ֵ = %f",average);
  return 0;
}
//����o(n)ɾ����������������Ԫ�أ�����ָ��ɾ���±�p1��p2��Ӧ��
void del(int A[], int len,int p1 , int p2)
{
  int i , k = 0;
  for(i = 0; i < len ; i++) 
  {
    if( i == p1 || i == p2)
		continue;     //�������ѭ����iָ����ƣ�kָ�벻��
	A[k++] = A[i] ; //�������Ҫɾ���ľ͸�ֵ��i��kһ�����
  }
}