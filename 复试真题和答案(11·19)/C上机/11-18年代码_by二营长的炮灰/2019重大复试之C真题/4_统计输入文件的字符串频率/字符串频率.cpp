#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int* strFrequency(char s[]);

int main()
{
	FILE *in,*out;
	char s[MAX];
	int* nums,i; //��¼�ַ�Ƶ��
    in = fopen("string.in","r");
	out = fopen("string.out","w");
	if(!in || !out)
	{
		printf("���ļ�ʧ�ܣ�");
		exit(1);
	}
    fscanf(in,"%s",s);
	nums = strFrequency(s);
	for(i = 0 ; i < 256;i++)//д���ļ�out
	{
		if(nums[i]) //����ַ�i��i����ASCII��ֵ��Ƶ�ʲ�Ϊ0��ִ��
			fprintf(out,"%c:%d\n",(char)i,nums[i]); 
	}
    fclose(in);
	fclose(out);
	return 0;
}

//[��]ͳ���ַ���Ƶ��:����ASCII��0~256
//����char*���ͣ�������printf����д����������int* 
int* strFrequency(char s[] )
{ 
	int* nums = (int*)malloc(sizeof(int) * 256 );
	int i ;
	int len = strlen(s); // �������治��ֱ����strlen(s)
	memset(nums,0,sizeof(int) * 256 );//�״�1����ʼ��ָ��ǰn�ֽ�Ϊ0��������len�ֽ�
	for(i = 0 ;i < len ; i++)
		nums[(int)s[i]] ++; //�磺A��ASCII���ʮ����64��num[64] = 1;
	return nums;
}