#include <stdio.h>
#include <string.h>
//�ַ���ѭ�����ܣ���һ���������������е�Ӣ���ַ����ܲ�������ܺ��Ӣ���ַ�����
//����A-Z ѭ������ a+ƫ��k,��Ӣ���ַ����� 
#define size 101
int main ()
{
	char str[size];
	int k;
	int i,len;
	
	scanf("%s%d",str,&k);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(isupper(str[i]))		//�Ǵ�д��ĸ 
		{
			str[i]=(str[i]-'A'+k )%26 +'A'; 
		}
		if(islower(str[i]))
		{
			str[i]=(str[i]-'a'+k )%26 +'a'; 
		}	
	}	
	
	printf("%s",str);
	return 0;
}
