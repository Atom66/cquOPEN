#include <stdio.h> 
//�����������������ǵ����Լ��������С������ 


int main ()
{
	int m,n;
	int temp;

	int mul; 
	
	scanf("%d %d",&m,&n);	
	mul=n*m;
	
	if(m<n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	
	temp=m%n;
	while (temp!=0)
	{
		m=n;
		n=temp;
		temp=m%n;
	}
	
	printf("���Լ��Ϊ%d",n);
	//����С��������
	
	printf("��С������Ϊ%d",mul/n) ;
	
	
	
	
	return 0;
}
