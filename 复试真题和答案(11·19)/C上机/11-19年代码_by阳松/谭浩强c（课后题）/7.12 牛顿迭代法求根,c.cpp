#include <stdio.h> 
#include <math.h>
//��ţ�ٵ�������� ax^3 +bx^2 +cx +d=0 ��÷����� x =1 ������  
double func (double a,double b,double c,double d);
int main ()
{
	double a,b,c,d;	
	double ret;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d); 
	ret=func (a,b,c,d);
	printf("%10.7lf",ret);
	return 0;
} 

double func (double a,double b,double c,double d)
{
	
	double x=1,x0,f,f1;
	x0=x;
	f=((a*x0+b)*x0+c)*x0+d;
	f1=(3*a*x0+2*b)*x0+c;
	x=x0-f/f1;
	while (fabs(x-x0)>1e-3)
	{
		x0=x;
		f=((a*x0+b)*x0+c)*x0+d;
		f1=(3*a*x0+2*b)*x0+c;
		x=x0-f/f1;	
	} 
	
	return x;
}


