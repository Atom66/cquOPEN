#include<stdio.h>
#include<stdlib.h>
#define MAX 100

char* dectoB(int dec); //ATTENTION 0:������char*��int*��

int main()
{
	int dec;
	char* binary;
	printf("������һ��ʮ�������֣�");
	scanf("%d",&dec);
    binary = dectoB(dec);
	printf("��Ӧ����������%s",binary);
	return 0;
}

//[��]����ת�����ƣ���2ȡ�࣬���̸��̣���������
//�ٴ�1:����0 1�ǵ�ת����char����,��ֻ��binary[i] = r + '0';
//      binary[i] = (char)r;  ����
char* dectoB(int dec)
{
   int r; //����
   int q; //��
   int i , j;
   char* binary = (char*)malloc(sizeof(char)*MAX),temp;
   for(i = 0 ; q != 0 ; i++ )
   {
	   r = dec % 2;
	   binary[i] = r + '0'; 
	   q = dec / 2;
	   dec = q;
   }
   binary[i] = '\0';  //�ٴ�2���ַ�����һ��Ҫ�ǵ�����'\0'
   i = i-1;  //i-1�Ǵ�ʱbinary����±�
   for(j = 0 ; j < i ; j++,i-- )  //��תbinary��ʵ�ֶ���������
   {
	   temp = binary[j];
	   binary[j] = binary[i];
       binary[i] = temp;
   } 
   return binary;
}























/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* intToB(int integer);
int* decToB(double decimal);
#define MAXSIZE 100

int main()
{
  //�ٴ�ǿ����c89��ðѱ�����������ǰ�档�����񱨴���
  double num;                 
  int integer;
  double decimal;
  int* B1 ,* B2;        //�洢������С�����ֶ�Ӧ��ʮ��������
  int i ;
  printf("������һ��ʮ�������� ");
  scanf("%lf",&num);    //����1��double�ͱ���Ӧ����%lf����
  integer = (int)num; //��ȡ����������
  decimal = num - integer; //��ȡ������С��
  printf("\n ��%f��2 =  ", num);
  //���������
  B1 = intToB(integer);
  B2 = decToB(decimal);
  for(i = 0 ; B1[i] != -1 ; i ++); //�ҵ�B1ĩβָ��-1��
  while(i != 0)
  {
	  i--; //�������
	  printf("%d",B1[i]);
  }
  printf(".");
  for(i = 0 ; B2[i] != -1 ; i ++)
  {
	  printf("%d",B2[i]);
  }
  return 0;
}

//����ת�����ƣ���2ȡ�࣬���̸��̣���������
int* intToB(int integer)
{
	int* B1 = (int*)malloc(sizeof(int) * MAXSIZE);
	//����2����ʼ�ͼ����̷�ֹ0ʱ����ѭ��
	int quotient = integer / 2 ,remainder ; 
	int i = 0;
	while(quotient != 0)//ATTENTION 1 :���̲�����0
	{
      quotient  = integer / 2; //��
      remainder = integer % 2; //����
	  B1[i++] = remainder; //����2�������̡����������� 
      integer = quotient ;
	}
    B1[i] = -1; //������ֹ����
	return B1;
}

//С������ת�����ƣ���2ȡ������С��С��˳������
int* decToB(double num)
{
  int* B2 = (int*)malloc(sizeof(int) * MAXSIZE);
  int integer ;
  //����4����ʼ�ͼ���С����ֹ0ʱ����ѭ��
  double dec =  num - (int)num ;  //����5��ǧ��ע��С�����ֶ����double��
  int i = 0;
  while(dec != 0)//ATTENTION 2 :��С�����ֲ�����0
  {
	  num = num*2;
      integer = (int)num; 
      dec = num - integer;
	  B2[i++] = integer;   //��������
	  num = dec;          //��ʱnum����ֵΪС������
  }
  B2[i] = -1; //��ֹ����
  return B2;
}
*/