#include<stdio.h>
#include<math.h>
#define n 1000

//double _sin(double x); //�����ж��壬��������д
double area (double (*f)(double) , double a ,double b);
int main()
{
   double area_sin ,area_cos ,area_exp;
   area_sin = area(sin,0,1);  //�״�1��������ָ��sin���()!
   area_cos = area(cos,0,1);
   area_exp = area(exp,0,1);
   printf("sin[0,1]���֣�%lf,cos[0,1]���֣�%lf,exp[0,1]���֣�%lf",area_sin,area_cos,area_exp);
   return 0;
}

//ͨ�ü��㺯�����֣�����ָ���ʹ��
double area (double (*f)(double) , double a ,double b)
{
   double det = (b -a) / n ;
   double area = 0;
   int i; 
   for(i = 1 ; i <= n ; i++)
   {
	   area += (*f)(a+det * i) * det; //�״�2: f���Ǻ�������*f���ǣ�  
   }
   return area;
}