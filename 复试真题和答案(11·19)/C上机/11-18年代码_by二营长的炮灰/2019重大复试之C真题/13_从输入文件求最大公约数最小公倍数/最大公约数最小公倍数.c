#include<stdio.h>

int gcd(int num1,int num2);
int main()
{
  FILE* in,*out;
  int num1,num2,g,lcm;
  in = fopen("number.in","r");
  out = fopen("number.out","w");//ATTENTION 0:��"w"ÿ�δ򿪶�������ļ�
                     // ��Ϊ��"w"�������ļ��Ƿ���ڶ������´���������
  if(!in || !out)
  {
	  printf("���ļ�ʧ�ܣ�\n");
	  exit(1);
  }
  while(!feof(in))
  {
	  //����1:fscanf����ָ��"r"
     fscanf(in,"%d %d",&num1,&num2);//�ո�ָ�����
     g = gcd(num1,num2);
	 lcm = num1 * num2 / g;//��󹫱�
     fprintf(out,"%d %d\n",g,lcm);
  }
  fclose(in);//����2�����ر��ļ���
  fclose(out);
  return 0;
}

/*
  �����Լ������ٷ��ҳ�����ܱ�����������
  �ж������� i < sqrt(min) ����ֻ��˵����������
             �����ҵ������������Ӧ�� i < min
 */
int gcd(int num1,int num2)//ATTENTION 1:��ʵ��build�ᱨ��
{
  int min,g = 1,i ; //ATTENTION 2:��ʼgΪ1����ֹû�����Լ
  min = num1 < num2? num1:num2;
  for(i = 2; i <= min;i++ ) //����3:<=����С�������Լ���
  {
    if( num1 % i == 0 && num2 % i == 0 )
	{
      g = i; //Ѱ�����Լ��
	}
  }
  return g;
}