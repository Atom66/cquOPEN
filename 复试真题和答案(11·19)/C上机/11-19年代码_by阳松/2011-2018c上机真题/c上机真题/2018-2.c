#include <stdio.h>
#include <string.h>

//�Ӽ�������һ���ַ������������е�Сд��ĸȫ��ת��Ϊ��д��ĸ��
//������������� E:\test.txt �ļ��С��磺
#define size 100
int main ()
{
	int i=0;
	FILE *fout=fopen("E:\\test.txt","w");
	char str[size];
	gets(str);
	
	while (str[i]!='\0')
	{
		if(islower(str[i]))
		{
			str[i]-=32;
		}
		i++;	
	}
	
	printf("%s",str);//���ַ��������%d,���%dʱӦ�����������ĵ�һ��Ԫ�صĵ�ַ����str[0]��ַ
	fprintf(fout,"%s",str);
	return 0;
}
