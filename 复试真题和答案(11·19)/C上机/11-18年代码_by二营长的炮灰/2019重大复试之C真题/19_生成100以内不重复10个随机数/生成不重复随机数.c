#include<stdio.h>
#include<time.h> //ע������ʱ���

int exist(int r[],int n);
int main()
{
  int r[10];
  int i ,temp;
  srand((int)time(0));//ATTENTION 0:������������ӣ���ֹ����һ��
  for(i = 0 ; i < 10 ; i++)
  {
    temp = rand() % 101 ; //�ٴ�1��101
	if(!exist(r,temp)) //ATTENTION 1 : !0 = 1,!��0 = 0
	{
       r[i] = temp;
	   printf("%5d",r[i]);
	}
  }
  return 0;
}

//�ж��Ƿ�����ظ�
int exist(int r[],int n)//[��]���ﶨ�庯����ֱ��дmain���
{
	int i;
	for(i = 0; i < 10 ; i++)
	{
      if(n == r[i]) //���ظ�
		   return 1;
	}
	return 0;
}