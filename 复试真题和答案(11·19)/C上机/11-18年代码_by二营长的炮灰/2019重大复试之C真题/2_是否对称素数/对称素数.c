#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isPrime(int num);
int isSym  (int num);
int main()
{
  int num;
  int is4;  //��λ������Գ�����
  printf("������һ������:\n");
  scanf("%d",&num);
  is4 = num >=1000 && num <= 9999;
  //����1��isPrime && isSym ��������
  if(!is4 && isPrime(num) && isSym(num))
	  printf("%d �ǶԳ�������\n",num);
  else
	  printf("%d ���ǶԳ�������\n",num);
  return 0;
}

/*
      �ж��Ƿ�������һ���������Խ��������ֽ⣬��ô�ֽ�ʱ�õ���������һ����
  һ��С�ڵ���sqrt(n)��һ�����ڵ���sqrt(n)���ݴˣ����������sqrt(n)���ɣ�
  ��Ϊ��sqrt(n)����Ҳ���Լ������ô�Ҳ�Ҳһ���Ҳ���Լ��
*/
 int isPrime(int num)
 {
	 int i ;
	 for(i = 2; i <= sqrt(num);i++)
	 {
		 if(num % i == 0)
			 return 0;         //ע��������Ǿ�ֱ��return�˳�����
	 }
	 return 1 ;
 }

 //�ж��Ƿ�Գ�:��������Ļ���������321 �����123 ���Ƚ���ȷ�
 //������ȡ����ÿһλ��������ģ��
 int isSym  (int num)
 {
	 int temp = num;
	 int sum  =0;
	 while(temp != 0)
	 {
		 //ÿ�μ�����������λtemp%10���ͼ���֮ǰ��������λ*10��һλ
		 sum = sum*10 + temp%10 ; //����
		 temp = temp /10 ;       
	 }
	 return sum==num;    //����3:��Ҫд sum == temp����
 }