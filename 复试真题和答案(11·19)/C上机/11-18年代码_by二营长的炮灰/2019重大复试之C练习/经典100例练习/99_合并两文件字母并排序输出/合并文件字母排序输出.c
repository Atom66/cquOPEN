#include<stdio.h>

void mysort(char* s); //����ָ�뷽��
int main()
{
  FILE* in1,*in2,*out;
  char s1[100],s2[100];
  in1 = fopen("txt1.in","r");
  in2 = fopen("txt2.in","r");
  out = fopen("txt3.out","w");
  if(!in1 || !in2 || !out)
	  exit(0); // ����1:���԰�Сʱ��д����exist(0)
  fscanf(in1,"%s",s1);
  fscanf(in2,"%s",s2);
  strcat(s1,s2);   //ATTENTION 1 :strcat()�����ַ���
  mysort(s1);
  fprintf(out,"%s",s1);
  fclose(in1);
  fclose(in2);
  fclose(out);
  return 0;
}

//�ַ�ð���������򣺰�ASCII��
void mysort(char* s)
{
	int len = strlen(s);
	int i , j;
	char temp;
	for(i = 0 ; i < len-1;i++)
	{
		//��ǰ��������ź��棺j=0��ʼ��ÿ��ǰ>��ͽ���
		for(j = 0 ; j < len-1-i;j++) //ATTENTION 2:����len-1
		{
			if(s[j]-s[j+1] > 0)//�״�1:�Ƚ��ַ�ֱ�ӱ�,����strcmp()!
			{
              temp = s[j];
			  s[j] = s[j+1];
			  s[j+1] = temp;
			}
		}
	}
}