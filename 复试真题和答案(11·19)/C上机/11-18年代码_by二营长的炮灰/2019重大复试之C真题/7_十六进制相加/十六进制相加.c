#include<stdio.h>

/*
  //ATTENTION 1�������Ϊ%X���-1A,-12=ffffffd4����ffffffffffffd4
*/
int main()
{
  __int64 A,B,sum;  //ATTENTION :__int64 �ȼ���longlong����vc6��֧��
  while(1)
  {
  printf("����������ʮ�����ƣ��м�ո������-1A +2A\n");
  scanf("%I64X %I64X",&A,&B); //����1��%I64X�������ճ�����16
  sum = A+B;                     
  printf("\n%I64X\n",sum);        
  }
  return 0;
}