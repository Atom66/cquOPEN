#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXKG 1001 //ATTENTION 1: ����1000����ΪҪ��Ҫ����1000g

int* farmarWeighing(int n1,int n2,int n3,int n5,int n10,int n20);
int main()
{
  int n1,n2,n3,n5,n10,n20 ,i,* N ;
  printf("������1��2,3,5,10,20���������,�磺5 3 2 2 1 1\n");
  scanf("%d %d %d %d %d %d",&n1,&n2,&n3,&n5,&n10,&n20);
  //N =farmarWeighing(5,3,2,2,1,1);
  N =farmarWeighing(n1,n2, n3, n5, n10, n20);
  for(i = 1 ;i < MAXKG ; i++ )
  {
	  if(N[i]) //����i��Ӧ���ط�ʽ��Ϊ0
       printf(" %d��:����%d�ַ�ʽ����\n",i,N[i]);
  }
  return 0;
}

/*
  ��ĿҪ������ܳƳ�������������1000�˺ͷ�ʽ�������� 1�� ��3�ַ�ʽ
  N* :	�±���ܳƵ�������ֵ�淽ʽ����
*/
int* farmarWeighing(int n1,int n2,int n3,int n5,int n10,int n20)
{
	int i,j,k,l,m,n,sum;
	int* N = (int*)malloc(sizeof(int) * MAXKG); 
	memset(N,0,sizeof(int) * MAXKG);//ATTENTION 2: [0-1000]����ʼ0����1000��
	for(i = 0 ; i<= n1 ;i++) //����2��С�ڵ��ںţ�
		for(j = 0 ; j<= n2 ;j++)
			for(k = 0 ; k<= n3 ;k++)
				for(l = 0 ; l<= n5 ;l++)
					for(m = 0 ; m<= n10 ;m++)
						for(n = 0 ; n<= n20 ;n++)
						{
							sum = i*1 + j*2 + k*3 + l*5 + m*10 + n*20;
                            if(sum)//ATTENTION 3��if(0)��ִ�У�����������ִ�� 
								N[sum] ++; //sum�˶�Ӧ���ط�ʽ+1
						}
    return N;
}