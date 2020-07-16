#include<stdio.h>
#include<math.h>

int isPrime(int num);
int isSym(int num);
int main()
{
  int is4 , i; 
  printf("5λ�����ڵĶԳ�����: \n");
  /*
     ��λ�������ǶԳ�����:
	 abba����1000a+100b+10b+a=1001a+110b = 11(91a+10b)����������11������ 
  */
  for(i = 0 ;i <= 9999;i++) //�Գ������Ӽ�λ��ʼ�㣿
  { 
	is4 = i>=1000 && i<=9999;
    if(!is4 && isPrime(i) && isSym(i))
		printf("%d\t",i);
  }
  return 0;
}

//�ж��Ƿ�Գ�����
int isPrime(int num)
{
	int i;
	for(i = 2 ; i <= sqrt(num) ;i++ )
	{ 
        if(num % i == 0)
			return 0;
	}
	return 1;
}

//�ж��Ƿ������
int isSym(int num)
{
	int temp = num;
    int sum = 0;
	while(temp != 0)
	{
      sum = sum * 10 + temp %10 ;
	  temp = temp / 10;
	}
	return sum == num ;
}
