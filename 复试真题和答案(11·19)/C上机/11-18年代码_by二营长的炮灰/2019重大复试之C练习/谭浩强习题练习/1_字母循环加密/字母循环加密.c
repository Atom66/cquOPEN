#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char* code(char* s);
int main()
{
   char* s = (char*)malloc(sizeof(char)*MAX);
   char* c;
   printf("������һ���ַ�����");
   gets(s);
   c = code(s);
   printf("���ܺ�%s\n",c);
   printf("���ܺ�%s\n",code(c));	  
   return 0;
}

//�����ַ�:���ܺ�ASCII����ȡ��������
//1.�����ַ������������s[i] = ������ʽ
char* code(char* s)
{
	int i , len = strlen(s);
    for(i = 0 ; i < len ; i++)
	{
		if(islower(s[i]))
			s[i] = 'z' - (s[i] - 'a') ;
		else if(isupper(s[i]))
			s[i] = 'Z' - (s[i] - 'A') ;
		else
			continue; //����ĸ���ı�
	}
	return s;
}

