#include<stdio.h>

int FindMin(int A[],int s ,int r);
int main()
{
	int A[] = {5,7,2,4,6}; 
	int min;
	min = FindMin(A,0,4);
    return 0;
}

//�ݹ������Сֵ
int FindMin(int A[],int s,int r)
{
    int k1 , k2;
	if( s == r)  
		return A[s];
	else
	{
		k1 = FindMin(A,s, (s+r) / 2); //��ǰn/2������ȡ����������С
	    k2 = FindMin(A,(s+r) / 2 + 1 ,r); 
		return k1 < k2 ? k1 : k2; //(*)
	}
}