#include <stdio.h>
//�� 1��2��3��4 �����֣�
//����ɶ��ٸ�ǧ��ʮλ������ͬ���ظ����ֵ���λ�������Ƕ��٣� 
//����� 123 124 ...432
int main ()
{
	int i,j,k,n;
	int cnt=0;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			if(i!=j)
			{
				for(k=1;k<=4;k++)
				{
					if(k!=i&&k!=j)
					{
						for(n=1;n<=4;n++)
						{
							if(n!=i&&n!=j&&n!=k)
							{
								printf("%d\n",i*1000+j*100+k*10+n);
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
