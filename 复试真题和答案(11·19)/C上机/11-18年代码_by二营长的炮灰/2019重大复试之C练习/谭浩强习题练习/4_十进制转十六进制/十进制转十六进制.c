#include<stdio.h>

char* dectohex(int num);
int main()
{
	char* hex;
	int num;
	printf("������һ��ʮ��������");
	scanf("%d",&num);
	hex = dectohex(num);
    printf("%s",hex);
	return 0;
}

char* dectohex(int num)
{
	char* hex = (char*)malloc(sizeof(char)*100);
	char temp;
	int q; //��
	int r; //����
	int i = 0 , j = 0;
	while(q != 0)
	{
		q = num / 16;
		r = num % 16;
		if(r >= 10) hex[i++] = r - 10 + 'A'; //�ɣ�����10 char����Ҳ�治�ˣ��պô�A..F
        else        hex[i++] = r;
		num = q;
	}
	hex[i] = '\0';   //�״�
    //����ʹ��hex���򣬴Ӷ����� 
	for(i = i-1,j =0 ;j < i;i--,j++)//Ϊ����iָ�����һ���ַ�������'\0'
	{
      temp = hex[i];
	  hex[i] = hex[j];
	  hex[j] = temp;
	}
    return hex;
}
