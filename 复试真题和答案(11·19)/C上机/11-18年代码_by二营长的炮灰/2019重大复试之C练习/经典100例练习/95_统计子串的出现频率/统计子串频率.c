#include<stdio.h>
#include<string.h>
#define MAX 100

int match(char* mainstr,char* substr);
int main()
{
	char mainstr[MAX],substr[MAX];
	int times;
	printf("��ֱ������������Ӵ����ո������\n");
	scanf("%s %s",mainstr,substr);
	times = match(mainstr,substr);
	//times = match("ABCCDFEFCDCDFFCD","CDF");
	printf("�Ӵ����������ֵ�Ƶ���ǣ�%d",times);
	return 0;
}
/*
  �����Ӵ���������ƥ��ɹ��Ĵ�����һ�α�����������β��i����k����һ��j
    1.һ�α�����������β��
    2.i����k��ÿ��i����һ�ζ�Ҫ��k=i�������Ӵ��Ƿ�ƥ�䡣
    3.��һ��j���ж�j==len��ƥ��ɹ�iλ��slen-1��j��ԭ��0���״�
*/
int match(char* m,char* s)
{
	int mlen = strlen(m),slen = strlen(s);
	//int flag = 1; //��ʶ�Ƿ���ȫƥ��ɹ��Ӵ�[����j==len�жϣ�ͬʱ��ȥѭ��break]
	int i,j,k,first = 0;
	int times = 0; //�ٴ�0��ע���ʼ��
	for(i = 0 ; i <= mlen-slen ; i++)//�ٴ�1��һ�α�����������β
    {
		if(m[i] == s[0])//���Ӵ���ƥ��
		{
           first = i;   
		   for(k = i+1,j = 1; m[k]==s[j] && j < slen;k++,j++);//kj�����ж�
		}
		if(j == slen)
		{
			times++;
		    i += slen-1; //ATTENTION 0:���ﻹ��i++���ʼ�1
			j = 0; //�ٴ�1����ֹ�´�ƥ��ʧ��ѭ�������ж�j==len
		}
	}
	return times;
}













/*
#include<stdio.h>
#define MAX 100

int count(char* mainstr,char* substr);
int betterCount(char* m,char* s);
int main()
{
  int n;      //ͳ���Ӵ����ִ���
  /*
  char mainstr[MAX],substr[MAX];
  gets(mainstr);  //��ȡ����ABCCDFEFCDCDFFCD
  gets(substr);  //��ȡ�Ӵ�CDF
  n = count(mainstr,substr);
  
  n = betterCount("ABCCDFEFCDCDFFCD","CDF");
  printf("�Ӵ�����Ƶ�ʣ�%d",n);
  return 0;
}

//ͳ���Ӵ����ִ���
int count(char* mainstr,char* substr)
{
  int mlen = strlen(mainstr);
  int slen = strlen(substr);
  int count =0 , i ,j ,first; //����1��һ��Ҫ��ʼ�������������count++������
  for(i = 0 ; i < mlen ; i++)//һ�α���ĸ��
	  if(mainstr[i] == substr[0]) //�����˵�һ��ƥ���Ӵ�
	  {
		  first = i++; //�洢i�ս�����λ�� AND i+1 ��j+1(����)
          for(j = 1 ; j < slen && i < mlen; j++) //ATTENTION 1������i����
		  {
             if(mainstr[i++] != substr[j]) //ƥ��ʧ�ܣ�i�����ʼ����
			 {
               i = first; //ƥ��ʧ�ܸ�ԭi������λ��Ȼ��++���ɹ�iָ��+�Ӵ����ȡ�
			   break; //�˳�ѭ��
			 }
		  }	
	      if(j == slen) count++; //����2��Ҫ��if(j == slen)������j<slenƥ��ɹ���+1��
	  }
	  return count;
}

/*
  ���õĴ��룺ͳ���Ӵ����ִ���
    ��i <= mlen - slen������ƥ�������ͬʱforѭ���������õ���k>=melen
	��k=i,���ô�i��ʼֵ��iֵ���ᱻ�ı䡣�´�ѭ��һ��ִ����һ��
	   ����ƥ��ɹ�ʱ��ҲҪָ����һ��������i+�Ӵ����ȼ���ƥ��(���Ż�)
	�� ͬʱs[j] == m[k]д��for��𵽲������breakЧ�������ٴ���
  
int betterCount(char* m,char* s)
{
  int mlen = strlen(m);
  int slen = strlen(s);
  int count =0 , i ,j ,k;
  for(i = 0 ; i <= mlen - slen ; i++)  //С���Ӵ����ȾͲ�ƥ�䣬ע��=
  {
      for(j = 0 , k = i ; j < slen && s[j] == m[k] ; j++,k++);
	  if(j == slen)
	  {
        count++; 
		i = i + slen-1; //ƥ��ɹ�,iֱ�Ӻ���slen-1.ע��-1����Ϊi�������ѭ��i++
	  }
  }
	  return count;
}
*/