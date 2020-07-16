#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 10

char* max_substr (char *str,char *substr);

int main ()
{
	char str[MAXSIZE];
	char substr[MAXSIZE];
	char * ret;

	gets(str);
	gets(substr);
	
	ret=max_substr(str,substr);
	printf("��ִ�%d\n",strlen(ret));
	printf("%s\n",ret);
	return 0;
}


char* max_substr (char *str,char *substr)
{
	int i,j;
	char*ret;
	int maxlen=0,maxend=0,maxbegin=0;
	
	int str_len=strlen(str);
	int substr_len=strlen(substr);

	char **p=(char **)calloc(substr_len,sizeof(char *));
	
	for(i=0;i<substr_len;i++)
	{
		p[i]=(char *)calloc(str_len,sizeof(char));
	}
	

	
	for(i=0;i<substr_len;i++)
	{
		for(j=0;j<str_len;j++)
		{
			if(str[j]==substr[i])
			{
				if(i==0||j==0)
				{
					p[i][j]=1;
				}else
				{
					p[i][j]=p[i-1][j-1]+1;
				}
			}else
			{
				p[i][j]=0;
			}
			if(p[i][j]>maxlen)	//�жϵ�ǰƥ�䳤���Ƿ������ 
			{
				maxlen=p[i][j];
				maxend=j;
			}
		} 
		
	}
	
	maxbegin=maxend-maxlen+1;	//������һ���ռ����ڴ洢'\0' 
	
	ret=(char *)calloc(maxlen+1,sizeof(char));
	for(i=maxbegin,j=0;i<=maxend;i++,j++)
	{
		ret[j]=str[i];		//ע�� ret[0][j]
	}
	
	ret[j]='\0';
	return ret;
}


/*
�ο����� 
https://blog.csdn.net/qq_25800311/article/details/81607168
*/ 
 
