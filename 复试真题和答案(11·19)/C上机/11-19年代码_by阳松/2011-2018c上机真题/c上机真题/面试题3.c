#include <stdio.h>
//.��������������� A[N],ָ��������M��ʹ�ö��ֲ��ҷ���
//������ A[N]�к�M�������λ �ã��������±� k�� 
//���û���ҵ��򷵻� A ������ <M�����±� k��
//�磺A[5] = {1 , 3 , 15 ,70 , 108}
//,����M=20������ k = 2��
int bianry_search (int *arr,int begin,int end,int key);

int main ()
{
	int ret;
	int arr[5] = {1,3,15,70,108};
	ret=bianry_search (arr,0,4,20);
	printf("%d",ret);
	
	return 0;
 } 
 
int bianry_search (int *arr,int begin,int end,int key)
{
	int mid;
	
	while (begin<end)
	{
		mid=(begin+end)/2;
		if(arr[mid]==key)
		{
			begin=mid;
			break;
		}else if(arr[mid] < key)
		{
			begin=mid+1;
		}else if(arr[mid] > key)
		{
			end=mid-1;
		}
	}
	
	if(arr[begin]<=key)
	{
		return begin;
	}else
	{
		return begin-1;
	}
}
