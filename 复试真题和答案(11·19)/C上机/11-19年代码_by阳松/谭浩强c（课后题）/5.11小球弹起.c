#include <stdio.h>

int main ()
{
	double hn=100;
	double distance=0;
	int i;
	for(i=0;i<10;i++)
	{
		distance+=hn*2;
		hn/=2;
	}
	
	printf("10�����ߵ�·��%lf����ʮ�η����ĸ߶�%lf",distance-100,hn);
	return 0;
}
