#include<stdio.h>
#include<math.h>

int isPrime(int num);
int main()
{
  int n , i;
  scanf("%d",&n);
  for(i = 2 ; i <= n ; i++) 
  {
	  if(isPrime(i) && isPrime(n-i))// i+n-i = n,����֮��
		  printf("%d,%d\n",i,n-i);
  }
  return 0;
}
/*
  �ж��Ƿ��������������¼���2019/2/23 12:38
  ����math.h��sqrt()���������ǲ���Ч�����i=num%num==0��������
*/
int isPrime(int num)
{
	int i;
	for( i = 2 ; i <= sqrt(num) ; i++) //ע��=
    {
		if(num % i == 0) 
		  return 0;
	}
    return 1; //ATTETION 1:1������������Ҳ��ֱ�ӷ���1�����ж�
} 