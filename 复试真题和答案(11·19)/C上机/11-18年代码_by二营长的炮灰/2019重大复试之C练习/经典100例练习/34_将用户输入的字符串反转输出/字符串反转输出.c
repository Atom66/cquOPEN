#include<stdio.h>
#include<string.h>

void reverse(char s[]);
int main()
{
	char s[100] = "2019-CQU-The cannon fodder of the second battalion commander";
	int i = 0;
	//while( s[i++] != '\0' ); //iָ��ĩβ'\0'��
    reverse(s);
	while( i < strlen(s) ) 
		printf("%c",s[i++]); 
	return 0;
}

//��ת
void reverse(char s[])
{
  int len = strlen(s);
  int i , j ;
  char temp;
  //ATTENTION 1��i<j ���� i<=j 
  for(i = 0 , j = len-1 ; i < j ; i++,j--)
  {
    temp = s[i];
	s[i] = s[j];
	s[j] = temp;
  }
}
