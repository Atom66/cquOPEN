#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int main()
{
	char s[MAX];
	int nums[MAX] , num = 0;
	int flag = 1;  //�״�0:��ʼΪ1����ֹ����0��nums
	int i , j = 0 , len = strlen(s) ;
	printf("������һ���ַ���");
	gets(s);
    for(i = 0 ; i < len ; i++)
	{
       if(isdigit(s[i]))
	   {
		   flag = 0 ; //��ʶ�ϴν�������һ�����ֶ�������
		   num = num * 10 + s[i] - '0';
           if(i == len-1) //�״�1����ʱ�Ѿ��������ַ�ĩβ������ִ��else��
		   {
			   nums[j] = num; 
			   printf("%d\t",nums[j++]);
 
		   }     
	   }	   
	   else
	   {
		   if(flag == 0)//�״�2���ϴν�����������&&��ζ�������ֲŴ����� 
		   {
			   nums[j] = num; 
			   printf("%d\t",nums[j++]);
		   }
		       
		   flag = 1;
	       num = 0;
	   }
	}
	return 0;
}