#include <stdio.h>
#include <string.h>
//���ļ�����һ����26����ĸ��������ɵ��ַ�����ͳ��ÿ���ַ�Ƶ�ʲ����
#define SIZE 100
int main ()
{
	char str[SIZE];
	FILE *fin,*fout;
	int i;
	int len;
	int sta[36];
	char ch;
	
	for(i=0;i<36;i++)
	{
		sta[i]=0;
	}
	
	fin=fopen("filename.in","r");
	fout=fopen("filename.out","w");
	if(fin==NULL||fout==NULL)
	{
		printf("���ļ�ʧ��"); 
	}
	
	fgets(str,SIZE,fin);
	
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		ch=str[i];
		if(ch>='a'&&ch<='z')
		{
			sta[ch-'a']++;
		}
		if(ch>='0'&&ch<='9')
		{
			sta[ch-'0'+26]++;	
		}
	}
	
	for(i=0;i<25;i++)
	{
		if(sta[i]>0)
		{
			fprintf(fout,"%c : %d\n",i+'a',sta[i]);
		}
	}
	
	for(i=26;i<36;i++)
	{
		if(sta[i]>0)
		{
			fprintf(fout,"%c : %d\n",i+'0'-26,sta[i]);
		}
	}
	
	return 0;
}
