#include <stdio.h>
#include <string.h>

//����һ���ַ�����ȡ����ַ�������������
#define M 100

void find_long_word (char *str);
int main ()
{
	char str [M];
	gets(str);
	find_long_word (str) ;
	
	return 0;	
} 


void find_long_word (char *str)
{
	int len =strlen(str);
	int index_key,last_key;
	int index;	//���ʿ�ʼ���±� 
	int i,max_len=0;
	int cnt=0;	//��¼��ǰ���ʵĸ��� 
	int flag=0;		//flag Ϊ 1 ���ʿ�ʼ��flagΪ0 ʱ���ʽ��� 
	
	for(i=0;i<len;i++)
	{
		if(islower(str[i])||isupper(str[i]))
		{
			if(flag==0)	//���ʿ�ʼ 
			{
				flag=1;
				cnt++;
				index=i; 
			}else if(flag==1)
			{
				cnt++;
			}
		}else 
		{
			if(flag==1)	//���ʽ��� 
			{
				if(cnt>max_len)
				{
					max_len=cnt;
					index_key=index;
					last_key=i-1;
				}
				flag=0;
				cnt=0;
			}
		}	
	} 
	
	if(flag==1)
	{
		if(cnt>max_len)
		{
			max_len=cnt;
			index_key=index;
			last_key=i-1;
		}
		flag=0;
		cnt=0;
	}
	
	for(i=index_key;i<=last_key;i++)
	{
		printf("%c",str[i]);
	}
	
	printf("\n");
}
