#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

int* multiply(int a[],int b);
int main()
{
	int N;
	int i;
	int* result = (int*)malloc(sizeof(int)*MAX);
	memset(result,-1,sizeof(int)*MAX);//ATTENTION 1����ֹ������Ҫ����0
	printf("��ָ���������λ�Ľ׳ˣ�");
	scanf("%d",&N);
	result[0] = 1; //��ʼΪ1
    for(i = 1 ; i <= N ; i++)
	{
	   result = multiply(result,i); 
	}
	printf("��������");
    for(i = 0 ; result[i] != -1 ; i++)
        printf("%d",result[i]);
	return 0;
}
//����a�ͷǴ���b��ˣ�b��a�ͣ������ͣ������λ
int* multiply(int a[],int b)
{
	int* result = (int*)malloc(sizeof(int)*MAX);
	int len;
	int i,j;
	int temp , carry = 0;
	memset(result,-1,sizeof(int)*MAX);
	for(len = 0 ; a[len] != -1 ; len++); //��ȡ����a����
	for(i = len-1,j=0 ; i >= 0 ; i--,j++)
	{
		temp = a[i]*b + carry;
		result[j] = temp % 10; //�������λ
		carry = temp / 10;
	}
	if(carry != 0)
      result[j] = carry; //�������һ����˵Ľ�λ
	else 
		j = j-1; //�ٴ�1����λΪ0ʱ����jָ���������һ��λ�ã�
	//�������ת����תģ��
	for(i = 0 ; i < j ; i++,j--)
	{
		temp = result[i];
		result[i] = result[j];
		result[j] = temp;
	}
	return result;
}





























/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* f(int n);
int main()
{ 
	int n,i,len;
	char* result; 
	printf("��ָ���׳�n���㣺");
	scanf("%d",&n);
	result = f(n);
	len = strlen(result) ;
	for(i = strlen(result)-1; i >= 0;i--) //Ҫ-1
		  printf("%c",result[i]);
	return 0;
}

/*
   ģ�����n�׳ˣ�
   1.     895   ���ڳ���35��<n�������ܻ��Ǵ���������35��895ÿ��
   	  *    35
	  ��������     �������ģ����㡣(���ֹ�ģ��������ͬ)     
	      175 //���´�ʱ5����λΪ17
		 315  //35 * 9 + �ϴν�λ17
	  ��������
	     332   //���´�ʱ2����λ33
		280
	  ��������
	    313    //���´�ʱ3����λ��ɡ�
		       //��󱣴����һ�ν�λ
   2.Ϊ�������ɶ���result[] ����洢������㣬����720: result[] = 027��
      �ʹ�����Ӳ�ͬ���������û����루�����Ǽ������������ġ�
	                  �鷳���ɴ�ת��ģʽ���㡣
   3.���׵�֪�������Ȼ������ѭ�������ȿ��� �ϴν��*i ���ڲ�ѭ��������1.
//
char* f(int n)
{
	char* result =(char*)malloc(sizeof(char)*1000);
	int i,j ,len,carry,temp;
	//�����״�1 ���ַ�����һ��Ҫ�Լ���'\0'!����strlen��(����֪������)
	//result = "1"; 
	//�����״�2:""�൱���·���ռ䣬��ָ�����������޸���Ԫ��ֵ�����
	result[0] = '1'; 
    len = 1;         
	for(i = 1 ; i <= n ; i++) //n���������׳�
	{
		carry = 0 ; //�����״�3 ��ÿ�ν�����Ҫcarry = 0����ֹ�浽�ϴν�λ
		for(j = 0 ; j < len;j++ ) //ÿ�ζ�Ҫ��i*��ǰresult���ȴ���
		{
		   temp = i*(result[j] - '0') + carry; //�״�1:��ǰ��˽��+��һ�ν�λ
		   carry = temp / 10 ; 
           result[j] = temp %10 + '0';//���λ��	   
		}        
		//�������һ��δ���temp��λ(����carry)
		while(carry != 0)
		{
          result[len++] = carry % 10 + '0'; //��ȡ���λ
		  carry = carry / 10 ; //ȥ�����λ
		}
	}
    result[len] = '\0';  //�״�3:�ǵ�'\0'��������Ȼ֪�����ȣ�main���޷���ȡ
	return result;
}
*/