#include<stdio.h>

int findM(int A[],int M ,int s , int r);
int main()
{
	int k , M;  //k��¼λ�����M����A���±�
	int A[] = {1 , 3 ,15 ,70 , 108};
	scanf("%d",&M);
	k = findM(A,M,0,4);
	printf("%d",k);
	return 0;
}

//�ݹ��M
//ATTENTION 0������M=20 s=3 r=4 mid = 3
//��ʱ������࣬findM(A,M,3,2) 3<2
int findM(int A[],int M ,int s , int r)
{
	int mid = (s+r)/2;
	if(A[mid] == M)  return mid;
    if(s > r)  return r;
	if(M < A[mid]) //M�����
		findM(A,M,s,mid-1); //��ǰ��ͬ��mid�Ѿ����ǣ�-1
	else//�Ҳ�
		findM(A,M,mid+1,r);    
}