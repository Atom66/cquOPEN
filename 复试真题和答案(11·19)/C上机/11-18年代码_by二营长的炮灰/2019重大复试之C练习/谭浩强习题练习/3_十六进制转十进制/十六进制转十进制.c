#include<stdio.h>

int main()
{
	__int64 n16_10;
	int n10_16;

	  //16ת10(1)
	printf("������һ��ʮ��������(1)��");
	scanf("%X",&n16_10);
	printf("��Ӧʮ��������%d\n",n16_10); //�״�1��lld

	  //10ת16(1)
	printf("������һ��ʮ��������");
	scanf("%d",&n10_16);
	printf("��Ӧʮ����������%X",n10_16); 
	return 0;
}