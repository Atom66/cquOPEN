#include<stdio.h>
#include<ctype.h>  //ATTENTION 1 :�����ж��Ƿ��Сд��ĸ
#include<string.h> 
#define MAX 100

int main()
{
	char s[MAX];
	int k;
	int i,len;
	printf("������һ���ַ�����ƫ��k���ո������");
	scanf("%s %d",s,&k);
    len = strlen(s);
	for(i = 0 ; i < len ; i++)
	{
		if(islower(s[i]))  s[i] = (s[i] - 'a' + k ) % 26 + 'a';
        if(isupper(s[i]))  s[i] = (s[i] - 'A' + k ) % 26 + 'A';
	}
	printf("���ܺ���ַ�����%s",s);
	return 0;
}







/*
#include<stdio.h>
#include<ctype.h>  //ATTENTION 1 :�����ж��Ƿ��Сд��ĸ
#include<string.h> 
#define MAX 40

char* encrypt(char* str,int k);
int main()
{
  char str[MAX] ;
  int k;
  printf("������һ��ֻ��Ӣ�ĺ����ֵ��ַ�����");
  gets(str);    //ATTENTION 2��gets()�ɶ���ո�
  printf("������ƫ����k��");
  scanf("%d",&k);   
  printf("���ܺ���ַ�����%s",encrypt(str,k));
  return 0;
}
/*   ASCIIֵ��41 42 43 44 45 46 ...96
  �����ַ����� A  B  C  D  E  F ...Z
    ���λ�ã� 0  1  2  3  4  5 ...25
   �٣�str[i] - 'A' ��ȡ���λ�ã��� 45(E)-41(A)=4
          char���������ͣ��洢����ASCIIֵֻ�������%c����ʾ��Ӧ�ַ�
       str[i]-'A' == str[i]��ASCIIֵ-'A'��ASCIIֵ
          ������-'0'������Ҫ������A��ASCIIֵ,��������
   �ڣ�+k ����ƫ��ֵ
   �ۣ�%26 �൱��E������K��λ�ã�%26����ѭ����26��ĸ
   �ܣ��״�1������ƫ��+'A' �õ�E���ܺ���ʵASCIIֵ
   
char* encrypt(char str[],int k)
{
  int i;
  for(i = 0 ; i < strlen(str); i++)
  {
	  if(islower(str[i])) //�����Сд
		  str[i] = (str[i] - 'a' + k ) % 26 + 'a';
	  else if(isupper(str[i])) //upper��д
		  str[i] = (str[i] - 'A' + k ) % 26 + 'A';
  }
  return str ; //ATTENTION 3���������ڿ��Է������飬�������Ͳ�����
}
*/