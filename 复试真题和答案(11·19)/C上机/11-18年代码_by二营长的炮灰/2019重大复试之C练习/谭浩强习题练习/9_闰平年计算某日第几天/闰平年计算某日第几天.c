#include<stdio.h>
struct Date
{
	int year;
	int month;
	int day;
}date; // �״�:�����date�Ǳ�����ֱ���ã��������typedef�����ͣ�
int days(int year,int month,int day);
int main()
{
  int day;
  printf("�������� �� �գ��Կո�ָ���");
  scanf("%d %d %d",&date.year,&date.month,&date.day); 
  day = days(date.year,date.month,date.day);
  printf("������ %d ��� %d ��", date.year,day);
  return 0;
}
  
int days(int year,int month,int day)
{
   int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};  
   int sum,i;
   sum=day;
   for(i=0;i<month-1;i++)
  	     sum+=a[i]; 
  //����: 1.�ܱ�4���������ܱ�100���� 2.�ܱ�400����
  if(((year%4==0 && year%100!=0)|| year%400==0) && month>2)
      sum = sum + 1; //��1��
  return sum;
}


