#include<stdio.h>
#define MAX 100

int main()
{
	int A[MAX] = {1}, N; //A[0] = 1������Ϊ0
	int n , i , space;
	printf("��ָ��������ǵĲ�����");
	scanf("%d",&N);
    for(n = 1 ; n <= N ; n++)
	{
		//ATTENTION 1: ��N������0��λ����N-1������1��λ
		for(space = N-n ; space > 0 ; space--)
			printf("  ");
		for(i = n-1 ; i > 0 ; i--) //��n������������
		{
			A[i] = A[i] + A[i-1];
			printf("%5d",A[i]);//������1��ʼ��ӡ�����ԳƵȼ۴�����
		}
		printf("%5d\n",A[0]); //�ٴ�1��ע�⻻��
	}
	return 0;	
}





















/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int a[100] = {0} ;//�״�1����һ����ʼ��Ϊ1�������ʼ��Ϊ0
  int i , j , N ,space; 
  a[0] = 1;
  printf("��ָ����Ҫ��������ǲ�����");
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++ )//�������N��ѭ��
  {
	  //�״�1�����5%d��1һ�ո�ռ2������λ��
	  //��һ��N�ո񣬵ڶ���N-1�ո�.. 
	  for(space=1; space <= N-i; space++)
          printf("  "); 
	  for(j = i ; j > 0 ; j-- ) //��i��i+1��������Ӧ�±�[0,i],����[i,1]��
	  {                         
            a[j] = a[j]+a[j-1]; //���Ҳ��1Ҳ�Ǽ��������
            printf("%5d", a[j]);//�����Ҳ�1��ʼ��ӡ�����Գ�==��������ӡ

	  }
	  printf("%5d\n",a[0]); //��ӡ�����1
  }
 return 0;
                      
}
*/