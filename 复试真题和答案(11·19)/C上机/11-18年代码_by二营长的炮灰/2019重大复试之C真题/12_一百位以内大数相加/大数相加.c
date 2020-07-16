#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char* bigNumAdd(char* a,char* b);
int main()
{
	char a[MAX], b[MAX] ,*result;
	printf("���������a b���ո������");
	scanf("%s %s",&a,&b);
	result = bigNumAdd(a,b);
	//result = bigNumAdd("112233445566778899","998877665544332211");
	printf("���Ϊ��%s",result);//�����һλ����Ϊ0
	return 0;
}
/*
  ������ӣ���
  1.[��1]��ν��ַ���a���ƣ���֪���ƺ󳤶�lm��
     (1) ���� i = la-1,k = lm-1�ֱ�ָ���ƶ�ǰ/��ĩβ
	 (2) ��i���ڵ���0ʱ��a[k] = a[i] //�ٴ�1��ע��=��
	     ��i���ڵ���0ʱ��//������������0
  2.[��2]β����ӣ�ÿ�δ�1�������λ
*/

char* bigNumAdd(char* a,char* b)
{
	char* result = (char*)malloc(sizeof(char)*(MAX+1));
	int la,lb,lm; //����
	int i,j,k;    //λ�ƿ���
	int ta,tb,t,carry = 0;  //��λ�����ʱ����
	la = strlen(a);
	lb = strlen(b);
	lm = la > lb ? la : lb;
	lm = lm+1;   //����1����ʱlm��ʾ��Ϊ��׼��ĳ���
	for(i=la-1,j=lb-1,k=lm-1; k>=0 ;i--,j--,k--) //����k<0 
	{
		if( i >= 0)	a[k] = a[i];
		else        a[k] = '0'; //�ٴ�1���ַ�����0 ��''
		if( j >= 0)	b[k] = b[j];
		else        b[k] = '0';
	}
	//�ѻ���׼����ʼ��ӣ�ֻ���������������һλ�������λ
	for(i = lm-1 ; i >=0  ; i--)
	{
		ta = a[i]-'0';
		tb = b[i]-'0';
		t = ta + tb + carry;
		result[i] = t % 10 + '0'; //ֻ�������һλ
		carry = t / 10;   //�����λ   
	}
	a[lm] = b[lm] = result[lm] = '\0'; //�ٴ�2���ַ���һ������ĩβ
    return result;
}

















/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
char* bigNumAdd(char num1[],char num2[]);
int main()
{
 char* result;
 int i = 0;
 //result = bigNumAdd("112233445566778899","998877665544332211");
 //result = bigNumAdd("123456","34567");
 result = bigNumAdd("987654321","56789");
 //������
 if(result[0] == '0')//��һλΪ0�����
 { 
		i = 1;
 }
 for( ; i < strlen(result);i++)
 {
      printf("%c",result[i]);
 }
 return 0;
}

//������ӣ������ַ�����ģ���λ���
char* bigNumAdd(char num1[],char num2[])
{
  //�ȴ����ַ�����99+8 = 099 + 008
    //ATTENTION 1 :strlen()���س���18��������sizeof()�����ܳ���100
	int l1,l2,lm,i,j,flag = 0 ,x,y,z;
    char* n1 ,*n2 , *result,c1,c2; //�洢�������ַ����ͽ��
	l1 = strlen(num1);
	l2 = strlen(num2);
	lm = l1 > l2 ? l1:l2;//��ȡ��󳤶�
	n1 = (char*)malloc(sizeof(int) * (lm+2));//ATTENTION 3: +2��
	n2 = (char*)malloc(sizeof(int) * (lm+2));
	result = (char*)malloc(sizeof(int) * (lm+2));
	//����1������lm+1����lm
	//����2��char������ĩβ����\0��񱨴�
	//����3��n1[i] = num1[i]; Ӧ����num[j++]
	       //������÷ֿ�������������j++����
	n1[lm + 1] = n2[lm + 1] = result[lm + 1] = '\0'; 
    for(i = 0 ,j = 0; i < lm + 1; i ++)//�����λ��0
	{
        if(lm + 1 - i > l1) 
			n1[i] = '0';   
		else           
			n1[i] = num1[j++]; 
	}
	for(i = 0 ,j = 0; i < lm + 1; i ++)//�����λ��0
	{
        if(lm + 1 - i > l2) 
			n2[i] = '0';   
		else           
			n2[i] = num2[j++]; 
	}

  //��ʼģ���λ����
	//�״�4��ָ���ʼ��ĩβ��lm������lm-1��ǰ������0
	for(i = lm  ; i >= 0 ; i--) 
	{
	// ATTENTION 2:-'0' ����ʾcharתint��+'0':��ʾ int ת char
	  //�״�5��char��int��ת��:(int)n1[i]��ȡ����ASCII�룬����
	   x = n1[i] - '0';
	   y = n2[i] - '0';
	   z = x + y + flag;
	   if( z >= 10) //�н�λ
	   {
         flag = 1 ; //��ʶ��λ���������������1
		 z = z % 10 ;
	   }
	   else
	   {
		   flag = 0 ; //����6���޽�λʱҪ��ʶ0������һֱ1
	   }
	   result[i] = z + '0'; //��һλ����Ϊ0
	}
	return result;
}
*/