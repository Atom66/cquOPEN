#include <stdio.h>
#include <string.h>
//����һ���ַ������������ֺͷ������ַ���������������������Ϊһ������
#define size 100
int main ()
{
	char s[size];
	int num[size];
	int i,len;
	int flag=0;
	int sum=0,cnt=0;	

	gets(s);
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			if(flag==0)
			{
				flag=1;
			}
			
			sum=sum*10+(s[i]-'0');
		}else
		{
			if(flag==1)
			{
				num[cnt++]=sum;
				sum=0;
				flag=0;
			}
		}
	}
	
	if(flag==1)
	{
		num[cnt++]=sum;
	}

	for(i=0;i<cnt;i++)
	{
		printf("%d ",num[i]);
	}

	return 0;
 } 


