#include<stdio.h>

double sumEven(int n);
double sumOdd(int n);
/*
 ATTENTION 0������ָ��/��ָͨ�붨��
   ��ָͨ�룺 double *ptr;
   ����ָ�룺 double *ptr(int a); //���Ӳ����б�
      ����: double *p[2] ָ������ ���� double (*p)[2] ָ������ָ��
	  ����>����ָ������double (*ptr)(int a); //��������*ptr��ϱ�ʾָ��
*/
int main() 
{
  int n;
  double (*psum)(int) , result; 
  scanf("%d",&n);
  if( n % 2 ==0)   
	  psum = sumEven; //�Ӻ���ֻ��ʹ��ʱ
  else
      psum = sumOdd;
  result = (*psum)(n); //�ٴ�1�����ʹ�ú���ָ�루������󶨵ĺ���������
  printf("%lf",result);��
  return 0;
}

//��ż���ͣ�1/2+1/4+...+1/n
double sumEven(int n)
{
	double sum = 0;
	int i;
	for(i = 2; i <= n; i+=2)//�����¼�:�ֵ��԰�Сʱ��i+2����Ӧ��i+=2!
	{
		sum += 1.0/i;
	}
	return sum;
}
//�������ͣ�1/1+1/3+...+1/n
double sumOdd(int n)
{
	double sum = 0;
	int i;
	for(i = 1; i <= n; i+=2)
	{
		sum += 1.0/i;
	}
	return sum;
}
