#include <stdio.h>
#include <string.h>
//�ַ���ѭ�����ܣ����ַ���ѭ������� i+5 ��λ�� 
#define size 101
int main ()
{
	char str[size];
	int k;		// k Ϊ1������ܣ�kΪ0 ������� 
	int i,len;
	
	scanf("%s%d",str,&k);
	len=strlen(str);
	switch (k)
	{
		case 1:
			for(i=0;i<len;i++)
			{
				str[i]=(str[i]+i+5 )%256 ; 
			}
		break;
		case 0:
			for(i=0;i<len;i++)
			{
				str[i]=(str[i]-i-5+256)%256 ; 
			}
		break;
		default:
			printf("erro") ;
	 } 

	printf("%s",str);
	return 0;
}
