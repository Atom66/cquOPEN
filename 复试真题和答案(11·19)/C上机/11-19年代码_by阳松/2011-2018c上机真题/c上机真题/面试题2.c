#include <stdio.h>
//����n��ֱ���ܽ�1��ƽ��ֳɶ��ٸ�ƽ�� 
int divide_palne (int n);

int main ()
{
	int ret;
	int n=100;
	ret=divide_palne(n);
	printf("%d",ret);
	return 0;
 } 
 
int divide_palne (int n)
{
	if(n==1)
	{
		return 2;
	}else
	{
		return divide_palne (n-1)+n;
	}

}
