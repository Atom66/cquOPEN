#include<stdio.h>
#include<string.h>
 
int main(int argc,char* argv[]) //��ά�ַ�����
{
  int i , j , flag ;
  char* temp;
  for(i = 1 ; i < argc - 1 ; i++) //ð��n-1�֣������0�β���
  {
	flag = 0 ; //�ڱ�
    for(j = argc-1; j - i > 0 ; j--)//ִ��argc-1-i��
	{
      if(strcmp(argv[j-1],argv[j])>0)//����0��>0,-1Ҳ��ִ��
	  {
        temp = argv[j];
		argv[j] = argv[j-1];
		argv[j-1] = temp;  //����1:д�� argv[j-1] = argv[j];
        flag = 1; //�ڱ�����������
	  }
	}
	if(flag == 0) 		break; 
  }
 //���
  for(j = 0 ; j < argc ; j++)
	  printf("%s\n",argv[j]);
  return 0;
}
