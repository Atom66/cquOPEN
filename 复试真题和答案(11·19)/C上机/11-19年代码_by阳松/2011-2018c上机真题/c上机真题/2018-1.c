#include <stdio.h>
#include <string.h>
//�ɿ���̨�򿪳��� ������n�������в����������������ų� 
//���������в����� welcome to our new world �����
//E:\Second\Debug\2.exe new our to welcome world
int main (int argc,char *argv[])
{
	int i,j;
	char temp[50];
	for(i=argc-1;i>1;i--)
	{
		for(j=1;j<i;j++)
		{
			if(strcmp(argv[j],argv[j+1])==1)
			{
				strcpy(temp,argv[j]);
				strcpy(argv[j],argv[j+1]);
				strcpy(argv[j+1],temp);
			}
		}
	}
	printf("%s\n",argv[0]);
	for(i=1;i<argc;i++)
	{
		printf("%s ",argv[i]);
	}
	return 0;
}
