#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//�� �� �� �� �� �� �� �� �� �� �� �� �� ȥ �� �� �� �� ���� �� �� �� �� �� ��
//ʾ���� "___hello____world___how_are_you__" ->"hello_world_how_are_you"

void delete_duplicate (char *str,char ch);

int main (){
	char ch='_';
	char str[200];
	gets(str);
	delete_duplicate (str,ch);
	printf("%s",str);
	return 0;
}

void delete_duplicate (char *str,char ch)
{
	int i,k;
	int flag=1;
	int len=strlen(str);
	
	for(i=0,k=0;i<len;i++)
	{
		if(str[i]==ch)
		{
		 	if(flag==0)
			{
				flag=1;
				str[k++]=str[i];
			}
		}
		else 
		{
			if(flag==1)
			{
				flag=0;
				
			}
			str[k++]=str[i];
		}
	}
	
	if(str[k-1]==ch)
	{
		str[k-1]='\0';
	}else
	{
		str[k]='\0';
	 } 
	
	
}
