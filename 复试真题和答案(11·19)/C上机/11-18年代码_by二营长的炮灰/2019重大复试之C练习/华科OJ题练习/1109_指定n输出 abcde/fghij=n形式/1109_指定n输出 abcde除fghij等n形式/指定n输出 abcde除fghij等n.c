#include<stdio.h>

int diffrent(int a , int b);
int main()
{
	int n;
	int abcde,fghij; 
    //double abcdefghij ; //ab����a-��b����Ϊһ���жϲ�ͬ(����1����̫��)
	printf("������ָ��n��");
	scanf("%d",&n);
	//1.0 ����ѭ�� ��98762-1234��* ��98762-1234)ִ�в���ȥ
	//2.0 ����ָ��n������fghij++ͬʱ* n ,���abcde��abcde,fghij��ͬ������ 
	for(fghij = 1234 ; fghij*n <= 98765 ; fghij++)
	{
		abcde = fghij * n;
		if(diffrent(abcde,fghij))
			printf("%d / % d = %d \n" ,abcde,fghij,n);
	}
	return 0;
}

//�ж������Ƿ�ÿλ����ͬ
int diffrent(int abcde , int fghij)
{
	int A[10] = {0};
	int low ; //��ȡ���λ
	//�״�2������λ��ǰ��0ҲҪ���ǲ�Ҫ�ظ�
	if(abcde >= 1000 && abcde <= 9999) //��4λ��
		A[0]++;
    if(fghij >= 1000 && fghij <= 9999) //��4λ��
		A[0]++;
	while(abcde) //�״� 3 ��while(!abcde) abcdeΪ0��ִ�У�����
	{
		low = abcde % 10;
		A[low]++; //��ʶ��ʱnĳλ����low������+1
		if(A[low] > 1)
			return 0; //����ĳλ���ִ��ڸ���>1
		abcde = abcde /10;
	}
	while(fghij) 
	{
		low = fghij % 10;
		A[low]++; 
		if(A[low] > 1)
			return 0; 
		fghij = fghij /10;
	}
	return 1;
}