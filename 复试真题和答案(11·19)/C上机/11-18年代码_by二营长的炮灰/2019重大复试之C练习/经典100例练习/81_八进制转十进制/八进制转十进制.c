#include<stdio.h>
#include<math.h>
#define MAX 100

int octToDec(int oct);
int main()
{
	int oct;
	printf("������һ���˽�������");
	scanf("%d",&oct);
	printf("��Ӧ�İ˽������ǣ�%d",octToDec(oct));
	return 0;
}

/*
  �˽���תʮ���ƣ���[ѭ����ȡ��λ���ֲ�����]ģ��
   special: ��������ǴӸ�λ��ʼ��ʮ���ƣ�ÿ��ѭ��ǰ����Ȩ��*8
*/
int octToDec(int oct)
{
	int sum = 0 ,temp = oct;
	int i;
	for(i = 0 ; temp != 0 ; i++)
	{
		sum += (temp%10) * pow(8,i);
		temp = temp/10;
	}
    return sum;
}







/*
#include<stdio.h>
#include<string.h>

int _8to10(char* s);
int main()
{
	char s[100];   //�״� 1��ֱ�Ӷ���ָ�벻��ʼ��
	scanf("%s",s); //ע�����λ%s����ѭ����ȡ��λ����ģ�����%d(��%��/�Ȳ���)
    printf("%d",_8to10(s));
	return 0;
}

/*
  �˽���תʮ���ƣ�01234567���Ӹ�λ��ʼ������
      1.�����λ��ʼ����ʼ��sum = 0
	  2.ÿһλ�� sum = sum*8 + s[i] -'0';
    (�൱��ÿѭ������һ��λ��ǰ������Ȩ��*8)

int _8to10(char* s)
{
    int sum = 0; //
	int i;
	for(i = 0 ; i < strlen(s);i++)
	{
       sum = sum * 8 + s[i] -'0';
	}
    return sum;
}
*/