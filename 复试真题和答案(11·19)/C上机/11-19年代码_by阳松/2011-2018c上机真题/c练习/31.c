#include <stdio.h>
//�û�����ָ�� n����һ�������У�
//2/1��3/2��5/3��8/5��13/8��21/13...
//���������е�ǰ 20 ��֮�͡�
int main ()
{
	int up=2,down=1,t;
	int cnt=0;
	double sum=0,temp;
	temp=(double)up/down;
	
	while (cnt<3)
	{
		sum+=temp;
		cnt++;
		t=up;
		up=up+down;
		down=t;
		temp=(double)up/down;
	} 
	printf("%9.6lf",sum);
	return 0;
}
