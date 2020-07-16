#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int* factorization(int num);
int main()
{
 int* factors;    //�洢��ʽ�ֽ������
 int num ,i;  
 printf("��������ֽ�����֣�");
 scanf("%d",&num);
 factors = factorization(num);
 printf("��ʽ�ֽ� %d = %d" ,num,factors[0]);//ע����д��A[0]
 for(i = 1; factors[i] != 0 ;i++)
	 printf(" * %d",factors[i]);
 return 0;
}

/*����������ʽ�ֽ�
  Ϊʲô��ֹ������ i <= temp �� ǿ�� = �ţ�
    1.��֤����ʱtemp���ܱ��ֽ�ʱ(��5)������ѭ����temp��i=temp������
	   ע�� i <= num ��Ҳ�ɵ�û��Ҫ��
	2.ͬʱ����ѭ��temp = 1�������� i = 2 <= temp ���˳�ѭ����
*/
int* factorization(int num)
{
	int i , j = 0 ,*factors,temp;
	factors = (int*)malloc(sizeof(int)*MAX);
	memset(factors,0,sizeof(int)*MAX);  //��ʼΪ0��Ҳ����ֹ����
    temp = num;
    for(i = 2 ; i <= temp ; i++) 	//��������ѭ��
		{
			if(temp % i == 0)      //�ҵ�����i
			{
              factors[j++] = i;     //�洢����i
			  temp = temp / i;     //�õ���������ģ�temp/i��
			  i = 1;    //�ٴ�1: i����1��i++�´�ѭ������2,Ѱ������
			}
		}
	return factors;
}