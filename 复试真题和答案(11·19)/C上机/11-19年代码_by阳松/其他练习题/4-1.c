#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//1.�������ַ����ֵ��ַ����ֿ�,ʹ�÷ֿ�����ַ���ǰһ���������ֺ�һ��������ĸ����
//��"h1ell2o3" ->"123hello"


//˼·�� �������ַ������飬һ���洢��ĸ��һ���洢���� 
int main (){
	
	char num [20] ;
	char str [20];
	char s[40];
	char temp;
	int i=0,j=0,k=0;
	
	gets(s);
	
	while(s[i]!='\0') 
	{
		temp=s[i];
		if(isupper(temp)||islower(temp))
		{
			str[j++]=temp;
		}else if(temp>='0'&&temp<='9')
		{
			num[k++]=temp;
		}
		i++;
	}
	str[j]='\0';
	num[k]='\0';
	printf("%s%s",num,str);
	return 0;
}
