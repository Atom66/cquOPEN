#include<stdio.h>
#include<ctype.h>

int main()
{
  char s[100];
  int i;
  int pos = 0 , max = 0,len = 0;
  printf("������һ���ַ�����");
  gets(s);
  for(i = 0 ; i < strlen(s); i++)
  {
	  if(isalpha(s[i]))
	  {
		  len++;
	  }
	  else
	  {
		  if(len > max) //��ǰ��¼���ȴ���max
		  {
			  pos = i - len; //�õ�������ĸλ��
			  max = len;
		  }
		  len = 0;
	  }
  }
  for(i = 0 ; i < max ; i++)
	  printf("%c",s[i+pos]);
  return 0;
}