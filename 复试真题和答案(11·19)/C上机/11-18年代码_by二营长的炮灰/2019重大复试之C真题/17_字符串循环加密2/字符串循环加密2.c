#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char* encrypt(char* s);
char* decode(char* s);
int main()
{
  char s[MAX] , str_encrypt[MAX];w
  gets(s);   //gets()�ɶ���ո�
  str_encrypt = encrypt(s);
  printf("���ܺ�%s\n",str_encrypt);
  printf("���ܺ�%s\n",decode(str_encrypt));
  return 0;
}

//�����ַ�
char* encrypt(char* s)
{
  char *s1 = (char*)malloc(sizeof(char)*MAX);
  int i;
  for(i = 0 ; i < strlen(s); i++)
  {
	  s1[i] = s[i] + i + 5; //����255���Զ�ȡ��
  }
  s1[i] = '\0';//�����δ���1�� �ַ�ָ��ĩβ��'\0'
  return s1;
}

//�����ַ�
char* decode(char* s)
{
  char *s1 = (char*)malloc(sizeof(char)*MAX);
  int i;
  for(i = 0 ; i < strlen(s); i++)
  {
	  s1[i] = s[i] - i - 5; 
  }
  s1[i] = '\0';
  return s1;
}