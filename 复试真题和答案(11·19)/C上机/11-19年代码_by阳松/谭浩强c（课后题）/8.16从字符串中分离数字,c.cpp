#include<stdio.h> 
#include <string.h>
//8.16  ����һ���ַ����������е� ������������Ϊһ���������δ����int������ 
 
#define M 100
int divide_number (char *str,int *ret);

int main ()
{
	char str[M];
	int ret[M];
	gets(str); 
	int i,cnt;
	cnt=divide_number (str,ret);
	for(i=0;i<cnt;i++)
	{
		printf("%d\n",ret[i]);
	}
	return 0;
}

int divide_number (char *str,int *ret)
{
	int len=strlen(str);
	int i;
	int cnt=0;	//cnt �������ֵĸ��� 
	int flag=0;		//flag==0 ��������û��ʼ��flag==1�������ֿ�ʼ 
	int sum=0;//sum�������ֵ�ֵ 
	
	for(i=0;i<len;i++)
	{
		if(str[i]>='0'&&str[i]<='9') 
		{
			if(flag==0)		//���ֿ�ʼ 
			{
				flag=1;
				sum=str[i]-'0';
				
			}else if(flag==1)
			{
				sum=sum*10+str[i]-'0';
			} 
		}else 
		{
			if(flag==1)		//���ֽ��� 
			{
				ret[cnt]=sum;
				sum=0; 
				cnt++;
				flag=0; 
			}
		}
	}
	if(flag==1)		//flag==1������ǰ���һ�����ֻ�û��¼ 
	{
		ret[cnt]=sum;
		cnt++;
		
	}
	return cnt;
}
