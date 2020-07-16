#include <stdio.h>
#include <stdlib.h>

//��ÿһ�����ֵ����Լ������С�������������ļ� filename16.in ,����ļ�filename16.out
//�������ļ��ж�ȡ���֣�ÿһ���������֣��ж���
#define SWAP(a,b) {int temp;temp=a;a=b;b=temp;}

int max_yueshu (int m,int n);
int min_beishu (int m,int n);
 
int main ()
{
	int m,n;
	int max,min;
	FILE *fin,*fout;
	fin=fopen("filename16.in","r");
	fout=fopen("filename16.out","w");
	
	if(fin==NULL||fout==NULL)
	{
		printf("�ļ���ʧ��");
		exit(1); 
	}
	
	while (fscanf(fin,"%d%d",&m,&n)!=EOF)
	{
		//���ú��� �����Լ������С������ 
		max=max_yueshu (m,n);
		min=min_beishu (m,n);
		fprintf(fout,"%d %d\n",max,min);
	}
	
	return 0;	
} 



int max_yueshu (int m,int n)
{
	int t;
	if(m<n)
	{
		SWAP(m,n);
	}
		
	t=m%n;
	while (t!=0)
	{
		m=n;
		n=t;
		t=m%n;
	}
	return n;
}  


int min_beishu (int m,int n)
{
	int mult;
	mult=m*n;
	return mult/max_yueshu(m,n);
}
