#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ÿ��������һ����������N��M��2 <= N��M <=200��
//��������N�У���i��i = 1,2������N����ÿһ����һ������
//��ʾ����i-1��ϲ����ͼ��ı��P��1 <= P <= M��
//4 5
//2
//3
//2
//1

typedef struct {
	
	int cnt;		//��¼����Ǳ��������Ŀ 
	int book;
	
}stu,*pstu;

int main () {

	
	int n,m;
	int i,j;
	pstu s;
	int cnt;
	int book;
	while (scanf("%d %d",&n,&m)!=EOF)
	{
		s=(pstu)calloc(n,sizeof(stu));
		for(i=0;i<n;i++)
		{
			cnt=0;
			scanf("%d",&book);
			for(j=0;j<i;j++)
			{
				if(s[j].book ==book)
				{
					s[j].cnt ++;
					cnt++;
				}
			}
			s[i].book =book;
			s[i].cnt  =cnt;
		}
		
		for(i=0;i<n;i++)
		{
			if(s[i].cnt ==0)
			{
				printf("BeiJu");
			}else
			{
				printf("%d",s[i].cnt);
			}
			printf("\n");
		}
		
	}
	
	
	
	
	return 0;
} 
