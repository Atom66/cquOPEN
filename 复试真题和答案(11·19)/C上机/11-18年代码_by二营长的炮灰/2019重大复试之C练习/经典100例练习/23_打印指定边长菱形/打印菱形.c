#include<stdio.h>

void printSpace(int n);
void printSpark(int n);
int main()
{
	int N;
	int i;
	printf("��ָ��Ҫ��ӡ�����β�����");
	scanf("%d",&N);
	for(i = 1 ; i <= N ; i++)
	{
		if( i <= N/2+1 )//�ϰ��
		{
			printSpace(N/2+1 - i); //�ȴ�ӡ�ո�
            printSpark(2*i-1);     //�ٴ�ӡ*��
		}
		else//�°��
		{
			printSpace(i - (N/2+1)); //�ȴ�ӡ�ո�
            printSpark(2*(N-i)+1);    //�ٴ�ӡ*��
		}
	}
	return 0;
}
void printSpace(int n)
{
	int i;
	for(i = 0 ; i < n ; i++)  printf(" ");
}
void printSpark(int n)
{
	int i;
	for(i = 0 ; i < n ; i++)  printf("*");
	printf("\n");  //�ٴ�1������*�ž�Ҫ������
}




















/*
#include<stdio.h>

int main()
{
  int space;
  int i , j ,N;
  printf("������߳���");
  scanf("%d",&N);
  //�ȴ�ӡ�ϰ벿��N��
  for( i = 0 ; i < N ;i++) //�ϰ벿��N��
  {
	  for(space = N-1-i ; space > 0 ;space--)//��ӡ��i��ո�
		  printf(" ");
	  for(j = 0 ; j < 2*i + 1 ; j++)//��ӡ��i��*
		  printf("*");   
	  printf("\n");
  }
  //�ٴ�ӡ�°벿��N-1��
  //�״�1��ע�� j = 2*(N-2-i) + 1 �����°벿�ֲ�ӵ�0�㿪ʼ��ó�
  for( i = 0 ; i < N - 1 ;i++) //�°벿��N-1��
  {
	  for(space = 0 ; space < i+1 ;space++)//��ӡ��N+i��ո�
		  printf(" ");
	  for(j = 2*(N-2-i) + 1 ; j > 0 ; j--)//��ӡ��N+i��*
		  printf("*");   
	  printf("\n");
  }
  return 0;
}
*/

