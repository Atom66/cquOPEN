#include <stdio.h> 
#include <math.h>
//�õ��������� x=a^0.5  x1=1/2(x0 + a/x0 )  Ҫ��ǰ�����������  x�Ĳ�ֵ С�� 10��-5 �η� 

int main ()
{
	double x0,x1;
	double a;
	scanf("%lf",&a);
	x0=1;
	x1=0.5*(x0 + a/x0 );
	while (fabs(x1-x0)>=1e-5)
	{
		x0=x1;
		x1=0.5*(x0 + a/x0 );
	}
	
	printf("%8.5lf",x1);
	
	return 0;
}
