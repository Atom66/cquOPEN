#include <stdio.h>
#include <string.h>
//�����С�0���͡�1����ɵ��ַ��������ַ������ıȽϴ��ַ����ȳ��ĺ���1����ıȽϴ�
//strcmp ��� ���ַ������ 
#define size 100
int main ()
{
	char str1[size];
	char str2[size]; 
	int ret;
	gets(str1);
	gets(str2);
	ret=mystrcmp(str1,str2);
	printf("%d",ret);
	return 0;
}

int mystrcmp (char *s1,char *s2)
{
	int len_1,len_2;
	int cnt1=0,cnt2=0;
	int i;
	
	len_1=strlen(s1);
	len_2=strlen(s2);
	
	if(len_1 >len_2)
	{
		return 1;
	}else if(len_1 < len_2)
	{
		return -1;
	}else if(len_1==len_2)
	{
		for(i=0;i<len_1;i++)
		{
			if(s1[i]=='1')
			{
				cnt1++;
			}
			if(s2[i]=='1')
			{
				cnt2++;
			}
		}
		
		if(cnt1>cnt2)
			return 1;
		else if(cnt1<cnt2)
			return -1;
		else 
			return 0;		
	}
	
}
