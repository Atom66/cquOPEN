#include <stdio.h>

//���������ϵʽ����Բ���ʵ�ֵ��ֱ�����һ���ֵС�ڸ�����ֵ��


int main ()
{
	double temp;
	double up=1,bottom=1;
	double sum=1;
	double i=3,j=1;
	double limit;
	scanf("%lf",&limit);
	up*=j;
	j++;
	bottom*=i;
	i+=2;
	temp=up/bottom;

	while (temp>limit)
	{
		sum+=temp;
		up*=j;
		j++;
		bottom*=i;
		i+=2;
		temp=up/bottom;
	}
	
	sum+=temp;
	printf("%.6lf",sum*2);
	return 0;
}
