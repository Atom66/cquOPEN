#include <stdio.h>
#include <string.h>
//��һ�� 8 ������תΪ 10 ���ơ��磺
#define size 100
int main ()
{
	int i,len;
	int cnt=0,sum=0;
	char num[size];
	gets(num);
	
	len=strlen(num);
	for(i=0;i<len;i++)
	{
		sum=sum*8+(num[i]-'0');
	}	
	
	printf("%d",sum);
	return 0;
} 
