#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//һ��һ�ж��ļ� ��Ҫ�������е�����������Ӵ�
//�����ڵڼ����Ӵ��еĵڼ���λ�� 
#define size 100 
int fide_substr(char *main_str,char *substr);
int main ()
{
	char s[size][size];
	char substr[size];
	int i,cnt=0,ret; 
	FILE *fin=fopen("filename20.in","r");
	if(fin==NULL)
	{
		printf("�ļ���ʧ��");
		exit(1);	
	} 
	
	while (fscanf(fin,"%s",s[cnt])==1)
	{
		cnt++;
	}
	
	scanf("%s",substr);
	for(i=0;i<cnt;i++)
	{
		if((ret=fide_substr(s[i],substr))!=-1)
		{
			printf("��%d���Ӵ��ӵ�%d����ĸ��ʼ",i+1,ret+1);
			break; 
		}
	}
	
	if(i==cnt)
	{
		printf("���޴˴�");
	}
	return 0;
}




int fide_substr(char *main_str,char *substr)	//�����Ӵ��ɹ��򷵻��Ӵ���ʼ��λ�ã�ʧ���򷵻�-1 
{
	int i,j;
	int len_m,len_s;
	len_m=strlen(main_str);
	len_s=strlen(substr);
	
	if(len_m<len_s)
	{
		return -1;
	}else
	{
		for(i=0;i<len_m;i++)
		{
			j=0;
			while (main_str[i+j]==substr[j]&&substr[j]!='\0')
			{
				j++;
			}
			if(j==len_s)
			{
				return i;
			}		
		}
		return -1;	
	}
	
}
