
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int mystrcmp(char* s1,char* s2);
int isSym(char* s);
int main()
{ 
  char* s[10] ; //������⣬����malloc�����ʾ10���ַ�ָ��
  char* temp; 
  int N =0 ; //��¼�ַ�������
  int i,j,k=0;
  printf("���������ַ���������null����:\n");
  //ATTENTION 1 ���û���֪��������ٸ��ַ���
  while(1) //����{}���滹Ҫ�����ڴ棬����while�︳ֵ
  {
	  s[N] = (char*)malloc(sizeof(char)*MAX);//�״�1�������ڴ�s[i]
	  scanf("%s",s[N]);
	  if(strcmp(s[N],"null") == 0)
		  break;//�״�2 ������ s[i++] == "null"��
	  N++;	  
  }
  //�޳��ǶԳƵ��ַ���
  for(i = 0 ; i < N ; i++)
  {
	  if(isSym(s[i]))
		  s[k++] = s[i]; 
  }
  N = k;  //�ǻ��Ĵ����ַ�������
  //[��]ð������ģ��
  printf("�����������Ϊ��\n");
  for(i = 0 ; i < N ; i++) //��дN-1��Ϊ�����s[N-1]
  {
	  for(j = N-1 ;j > i;j--) //ÿһ�ְѽ������Ұ���С��ǰ��
	  {
		  if(mystrcmp(s[j],s[j-1]) < 0)
		  {
             temp = s[j];
			 s[j] = s[j+1];
			 s[j+1] = temp;
		  }
	  }
	  printf("%s\n",s[i]); //���
  }
  return 0;
}

//�Ƚ��ַ�����С
//ATTENTION 2 :�ַ�����ָ����Ի�ȡ���ȣ�int���У�
int mystrcmp(char* s1,char* s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if(len1 > len2) return 1;
	if(len1 < len2) return -1;
	if(len1 == len2) return strcmp(s1,s2);
}

//[��]�ж��Ƿ���ģ���ת�ַ�ģ��
int isSym(char* s)
{
  int len = strlen(s);
  int i = 0 ,j = len-1;
  while(i < j)
  {
	  if(s[i++] != s[j--])
		  return 0;
  }
  return 1;
}
*/
