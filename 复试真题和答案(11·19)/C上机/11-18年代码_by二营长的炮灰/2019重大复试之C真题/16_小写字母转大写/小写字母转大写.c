#include<stdio.h>
#include<ctype.h>
#define MAX 100

int main()
{
	FILE* out;
	char s[MAX];
	int i ;
	gets(s);
	for(i = 0 ; s[i] != '\0';i++)
	{
		if(islower(s[i])) 	s[i] = toupper(s[i]);
	}
	out = fopen("E:\\test.txt","w"); //ATTENTION 0 :fopen����ûout!
	if(!out)   
		exit(1);	
	//2019.2.20 10:43 ���Ǹ�ɵzi�����԰�Сʱԭ����printfûf,fprintf��
	fprintf(out,"%s",s);
	fclose(out);  //�״� 1 ���ǵù��ļ���
	return 0;
}