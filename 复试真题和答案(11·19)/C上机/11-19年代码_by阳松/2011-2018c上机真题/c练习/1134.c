#include <stdio.h>
#include <string.h>
//�ܶ��ִ�����Щ�ǶԳƵģ���Щ�ǲ��ԳƵģ�
//�뽫��Щ�ԳƵ��ִ�����С�����˳�� ������ִ����Գ����۴�С��
//���������ͬ������ ASCII ��ֵΪ��С��׼
#define size 100
int compare (const void *a,const void *b);
int is_symmetry (char *s);

int main ()
{
	char *str[size];
	char s[size][50];
	int i,k=0,cnt=0;
	while (scanf("%s",s[cnt])!=EOF)
	{
		cnt++; 
	}
	
	for(i=0;i<cnt;i++)
	{
		if(is_symmetry(s[i]))	
		{
			str[k++]=s[i];	
		}	
	}	
	
	qsort(str,k,sizeof(char*),compare);
	
	for(i=0;i<k;i++)
	{
		printf("%s\n",str[i]);
	}
	
	return 0;
}

int compare (const void *a,const void *b)
{
	int len_1,len_2;
	char *s1=(char*)a;
	char *s2=(char*)b;
	
	len_1=strlen(s1);
	len_2=strlen(s2);
	
	if(len_1<len_2)
	{
		return -1;
	}else if(len_1>len_2)
	{
		return 1;
	}else 
	{
		return strcmp(s1,s2);
	}

}

int is_symmetry (char *s)
{
	int len=strlen(s);
	int i=0,j=len-1;
	int flag=1;

	while (i<j)
	{
		if(s[i++]!=s[j--])
		{
			flag=0;
			break;
		}
	}
	
	return flag;
}
