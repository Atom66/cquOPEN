#include <stdio.h>
//99�����ɶ��ٶ�����Ӷ���

int main ()
{
	int i;
	int cnt=0;
	for(i=0;i<50;i++)
	{
		printf("99=%d+%d\n",i,99-i);
		cnt++;	
	}	
	
	printf("%d\n",cnt);
	return 0;
} 
