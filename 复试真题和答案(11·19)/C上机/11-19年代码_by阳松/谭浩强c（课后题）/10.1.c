#include <stdio.h>
#include <string.h>
//�Ӽ���������һ���ַ����������е�Сд��ĸȫ��ת��Ϊ��д��ĸ���������  tset �ļ��� 

int main ()
{
	int i;
	char str[100];
	int len;
	gets(str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(islower(str[i]))
		{
			str[i]=str[i]-32;
		}
	} 
	
	FILE *fp;
	fp=fopen("tset.txt","w");
	fputs(str,fp);
	
	
	return 0;
}
