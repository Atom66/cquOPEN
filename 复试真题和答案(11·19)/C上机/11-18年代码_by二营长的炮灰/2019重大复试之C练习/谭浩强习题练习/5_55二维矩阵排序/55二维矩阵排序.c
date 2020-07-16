#include<stdio.h>
#define n 5

void sort(int A[][n]); //ATTENTION 0��A[][]�Ƿ�
void swap(int A[][n],int i,int j,int i1,int j1);
int main()
{
	int A[n][n] = {{7,1,5,3,2},{5,4,8,0,9},{1,2,3,4,5},{6,7,8,9,10},{1,7,9,3,5}};
	sort(A);
	swap(A,n/2,n/2,n-1,n-1); //����
	//swap(A,0,0,0,0); 
	swap(A,0,n-1,0,1); //���Ͻ�
	swap(A,n-1,0,0,2); //���½�
	swap(A,n-1,n-1,0,3); //���½�
	return 0;
}

/*
  ���Զ�ά��������ð��ģ��
  ���ַ�������ͬ�����ַ�����Ȼ�൱��һά����Ƚ�
                    �ڽ������ǵ�ַ��ָ�룩�����ｻ��Ԫ�ء�
*/
void sort(int A[][n])
{
	int i ,j,N = n*n ;
	int temp;
	for(i = 0 ; i < N ; i++) //���Է��ʶ�ά����
		for(j = 0 ; j < N-1-i ; j++)
		{
           if(A[j/n][j%n]> A[(j+1)/n][(j+1)%n]) //���ｻ�����������ַ
			   swap(A,j/n,j%n,(j+1)/n,(j+1)%n);  
		}
}

void swap(int A[][n],int i,int j,int i1,int j1)
{
	int temp;
	temp = A[i][j];
    A[i][j] = A[i1][j1];
	A[i1][j1] = temp;
}