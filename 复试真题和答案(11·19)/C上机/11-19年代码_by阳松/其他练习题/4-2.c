#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//�� �� �� �� �� �� �� �� �� �� �� "%020" �� �� �� "hello world how "
////->"hello%020%020%020world%020%020%020how%020%020%020%020"

void transform (char *str,char *after);

int main (){
	
	char str[300];
	char after[600];
	after[0]='\0';
	gets(str);
	transform (str,after);
	printf("%s",after);
	return 0;
}

void transform (char *str,char *after)
{
	int i=0,j=0;
	char ins[5]="%020";
	while (str[i]!='\0')
	{
		if(str[i]==' ')
		{
			strcat(after,ins);
			j=strlen(after);
		}else
		{
			after[j++]=str[i];
			after[j]='\0';					//��Ȼstrcat �ò��� 
		}
		i++;
	}
}
