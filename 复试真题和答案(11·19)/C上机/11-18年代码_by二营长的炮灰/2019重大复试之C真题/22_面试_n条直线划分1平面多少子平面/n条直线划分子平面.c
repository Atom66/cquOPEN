#include<stdio.h>

int f(int n);
int main()
{
  int n;
  scanf("%d",&n);
  printf("%d",f(n));
  return 0;
}

//��n��ֱ�߿ɽ�һ��ƽ��ֳɶ��ٸ���ƽ��
//�ݹ���
int f(int n)
{
	if(n == 1)  return 2;
	return n+f(n-1);
}