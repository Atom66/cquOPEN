#include<stdio.h>
#include<string.h>
#define MAX 100

void move1_m(int A[],int N ,int m);
void move2_m(int A[],int N ,int m);
int main()
{
	int A[MAX] = {0}; //������ֹ��1.����-1��Ԫ��2.���ó���
	int i ,len, m ;
	/*
	 ���ܣ�1.��ctrl+c�������в������ϴ��� 
	       2.���ܻ�����-1����ֻ����ô�жϡ������ַ�%c��ת����ֻ��ת0-9
		   3.[ע]���ﲻ��getchar()
	*/
	printf("����������Ԫ�أ�����-1�س�������Ԫ�ؿո������");
	for(i = 0 ; scanf("%d",&A[i]) && A[i] != -1 ; i++);   
    len = i;
	printf("��ָ������ƫ��m��");
	scanf("%d",&m);
	move1_m(A,len,3);
	//move2_m(A,len,3);
	for(i = 0 ; i < len ; i++)
		printf("%d  ",A[i]);
	return 0;	
}
/*
  ָ������ǰNλѭ������1��Ϊʲô������N��-1���Ϳ����ж���ֹ��
      ��Ϊ��Ϊ�˿�ά���ԣ�����ı���ֹ��������-1�أ�
*/
void move1_m(int A[],int N,int m)
{
	int A1[MAX] = {0};
	int i;
	for(i = 0 ; A[i] != -1 ; i++)
	{
		A1[i] = A[(i+m)%N];
	}
	memcpy(A,A1,sizeof(int)*N);//�ٴ�1: int���鸴�ƣ�ָ���ֽ�
}

//ѭ������˼·2      
void move2_m(int A[],int N,int m)
{
   m = m % N;  //mȡ��
   int temp , i ,j; //temp��¼AβԪ��A[N-1]
   for(i = 0 ; i < m ; i++) //ƫ��m�ƶ�m��
   {
	   temp = A[N-1];
	   for(j = N-1; j > 0 ; j--)
	   {
		   A[j] = A[j-1]; //����:A[j-1] = A[j]
	   }
	   A[0] = temp; //βԪ��ƫ��+1 = ��Ԫ��
   }
}






















/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void move1_m(int A[],int N,int m); //���ö���ָ�룬û�н���
void move2_m(int A[],int N,int m); 
int main()
{
  int A[100] = {0}, i = 0 , N = 0 ,m;  //����������ԭ�򣺼���
  char c ;
  //ATTENTION 0�������û���������,SCANF()��ǰ
               //���û�ָ��N���򵥣�for(i =0 ; i < N ;i++) {scanf()}
  while(scanf("%c",&c) && c != 'y') //scanf����ֵ�ǳɹ�����������>=0
  {
	  getchar();//�����״�1��getchar()�����س�(��ո�)���������
	  A[i++] = c-'0';
	  N++;   //���鳤��+1
  }
  printf("ָ��ƫ�ƣ�");
  scanf("%d",&m);
  for(i = 0 ; i < N ; i++) 
	  printf("%d",A[i]);
 // move1_m(A,N,m); 
  move2_m(A,N,m);
  for(i = 0 ; i < N ; i++) 
	  printf("%d",A[i]);
  return 0;
}

/*ѭ�����ƶ����飺
ATTENTION 1:����Ȼ�ɴ�������A����A���׵�ַ�����ܸı䣬�޷���ָ�뽻��Ԫ�ص�ַ
            �ڻ��д����鳤�ȣ�ȷ����ֹ����
       ˼·1��A [6] = {1 2 3 4 5 6}
	       (1) �ȿ����������һ����λ��Ϊ�˱���˼�����һλ6�ƶ�Խ��ѭ��������
		          �ٽ�6�ݴ棬12345�����ƶ� A[i] = A[i-1]
				  �����6���ƶ�һλ�� A[0] = 6
		   (2)Ҫ�ƶ�mλ�����ظ�(1)����m�μ��ɡ�
	   ˼·2: �Ա��ַ����ƫ�ƣ�s1[i] =(s[i]+m)%256; //���Զ�ȡ��256��ʡ
	       (1) �ٶ���һ������ A1[6] 
	       (2) A1[i] = A[(i+m)%6] 
	���߲�ͬ��s1��s�൱���ַ���Ӧ�±�(ASCIIֵ)��s1[i]�����ַ�ƫ�ƺ���±�
		         A1��A�����ֵ��A1[i]�����ַ�ƫ�ƺ���±꣬����Ӧֵ

void move1_m(int A[],int N,int m)
{
   int _m = m % N;  //mȡ��
   int temp , i ,j; //temp��¼AβԪ��A[N-1]
   for(i = 0 ; i < m ; i++) //ƫ��m�ƶ�m��
   {
	   temp = A[N-1];
	   for(j = N-1; j > 0 ; j--)
	   {
		   A[j] = A[j-1]; //����:A[j-1] = A[j]
	   }
	   A[0] = temp; //βԪ��ƫ��+1 = ��Ԫ��
   }

}

//�ඨ��һ�����飬ʵ��ƫ��
void move2_m(int A[],int N,int m)
{
	int A1[100] = {0} ,i;
    for(i = 0 ; i < N ; i++)
	{
		A1[i] = A[(i+m)%6]; //ATTENTION 1 :����û���ȶ�mȡ��
	}
	memcpy(A,A1,sizeof(A1));//ATTENTION 2 : int���鸴�ƣ�sizeof��ȡA1����100*4�ֽ�
}
*/