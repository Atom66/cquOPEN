#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct student
{
	int name;
	int ID;
};
int isNarcissisticNumber(int num);
int main()
{

	/*
	    //1.float��Чλֻ��6-7λ��double����15λ
	float  a = 123456789.123;
    double b = 123456789.123;
	printf("f = %f",a);
    printf("d = %f",b);//�������%f����ʾ�����������
	   //2.�ṹ��ĵ���
    struct	student s; // �ȼ� struct student s ��
	s.ID = 1; 
	printf("%d",s.ID);
		//3.ˮ�ɻ�������
	int a = isNarcissisticNumber(153);
	if(a == 1)
	{
		printf("��ˮ�ɻ�����");
	}
	else
	{
        printf("����ˮ�ɻ�����");
	}
	*/
	/*
        //4.����if(2),if(3)..ִ�����
	if(0)
	{
		printf("0\n");  //����if(0)��ִ�У���������������ִ��
	}
	if(-1)
	{
		printf("-1\n");
	}
    if(1)
	{
		printf("1\n");
	}
	if(2)
	{
		printf("2\n");
	}
	if(800)
	{
		printf("800\n");
	}
	*/
	/*
	  //5.����char����һЩ����
	//char c2;
	 char c = '0';         //ATTENTION 1 :�õ����Ŵ�����0
	 printf("%c\n",c);  //���0
	 printf("%d\n",c);  //���0 ASCII��ֵ48
	 char c1 = 48;         //ATTENTION 2 :Ҳ����ֱ�Ӵ洢0 ASCIIֵ
	 printf("%c\n",c1); //���0
	 printf("%d\n",c1); //���ASCII��ֵ48
	 char  c2 = c + 40;    //ATTENTION 3 :char���Ϳ���ֱ�Ӻ�������� = ��Ӻ��ASCII��ֵ
	 printf("%c\n",c2); //��� X
	 printf("%d\n",c2); //��� 88(X��Ӧ��ASCIIֵ)
	 char  c3 = c + 257;    //ATTENTION 4 :���Խ�糬��ASCII��ֵ256���Զ�ѭ��
	 printf("%c\n",c3); //��� 1
	 printf("%d\n",c3); //��� 49
	*/
	 //6.�����ַ�ָ������һЩ����
	  int len;
	  /*
	  char *p ;
	  p = "hello"; //���p�����鲻�ܸ�ֵ����Ϊ��ʱp����
	  len = strlen(p); //��ʱ���ȵ���5
      
	  char *p = (char*)malloc(sizeof(char)*100);
      p = "1"; 
	  len = strlen(p); //��ʱ���ȵ���1
	  p[0] = 0;
	  */
	  int A[256] = {0};
	  char c = '0';
	  A[c] = 1;
	  return 0;
}

//nλˮ�ɻ��������� = ��λ��^n + ʮλ��^n + ��λ��^n + ...
int isNarcissisticNumber(int num)
{
  int count = 0;//�ж��Ǽ�λ��
  int sum   = 0;//�ƺ�
  int temp  = num; //��������count��ʱ����
  while(temp != 0)
  {
	  temp = temp / 10; //ÿ�ζ�ȥ�����λ��ֱ��Ϊ0:153 - 15  15- 1 1-0
	  count++;
  }
  temp = num;      //�״�٣��ٴδ洢numֵ����������num���м��㣬�������num=0�����ܺ�sum�Ƚ�
  while(temp != 0)
  {
	  sum += pow(temp % 10 ,count); //��ȡ���λ��n�η�
	  temp = temp/10;//ȥ�����λ����nλ-->n-1λ����
  }
  if(sum == num){ return 1; }
  else          { return 0; }
}