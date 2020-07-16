#include <stdio.h>
#include <string.h>

//����һ���ַ��������ַ�����ת ��
//Input: I____am__a__student
//Output: student__a__am____I
void inverse (char *str,int m,int n);
void divide_word (char * str);
 
int main (){
	int m=0;
	int n;
	char str[20];
	gets(str);
	n=strlen(str);
	//�Ƚ��ַ����� ��������
	inverse (str,m,n); 
//	printf("%s",str); 	
	//�ٽ�ÿ���������� 
	divide_word (str); 
	printf("ת�ú������\n"); 
	printf("%s",str); 
	
	return 0;
}

void inverse (char *str,int m,int n)			//inverse �������������ַ������ ͷ  ��β 
{
	
	int i,j;
	char temp;
	i=m;
	j=n-1;
	while (i<j)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
	return ;
}


void divide_word (char * str)
{
	int i;
	int index=-1;
	int flag=0;
	int len;
	len=strlen(str);
	
	for(i=0;i<len;i++)
	{
		if(isupper(str[i])||islower(str[i]))
		{
			if(flag==0)			//���ʿ�ʼ 
			{
				flag=1;
				index=i;
			}
		}else
		{
			if(flag==1)			//���ʽ��� 
			{
				flag=0;
				inverse(str,index,i); 
				index=-1;
			}
		}
		
	}
	
	if(index!=-1)			//������������һ�����ʺ���û���������ţ�ֱ�ӽ��� 
	{
		inverse(str,index,i); 
	}
} 

