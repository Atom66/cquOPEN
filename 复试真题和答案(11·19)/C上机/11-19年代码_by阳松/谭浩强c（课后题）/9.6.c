#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

//n����Χ��һ�ţ��ӵ�һ���˿�ʼ���������� m ���˳��У������ʣ�µ��˵��������� ���� 
int fun (int *arr,int n,int m);

int main ()
{
	
	int n,m;
	int i;
	int index;
	scanf("%d%d",&n,&m);
	int *arr;
	arr=(int *)calloc(n,sizeof(int));
                                                		//	memset(arr,1,n);   //memset ֻ�ܵ��ֽڸ�ֵ�������memset��int �ͱ�����ֵ�ͻ�������� 
	for(i=0;i<n;i++)
	{
		arr[i]=1;
	}
	index=fun(arr,n,m);
	printf("���ʣ�µ��˵ı����%d",index+1);
	return 0;
}

int fun (int *arr,int n,int m)
{
	
	int i;
	int num=0,ret;
	int cnt=0;		//������ӵ����� 
	while (cnt<n)
	{

		for(i=0;i<n;i++)
		{
			if (arr[i]==1)
			{
				num++;
				if(num%m==0)
				{
					cnt++;
					arr[i]=0;
					printf("%d ",i+1);
				}
			}
			if(cnt==n)
			{
				ret=i;
				break;
			}
		}	

	}
	
	
	return ret;
}


