#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int strcmp01(char* s1,char* s2);
int main()
{
	char** s,*temp; 
	int n;
	int i,j;
	printf("��ָ������01�ַ���������");
	scanf("%d",&n);
	s = (char**)malloc(sizeof(char*)*n); //�ٴ�1��ָ����ά�����С
    for( i = 0 ; i < n ; i++)
	{
		s[i] = (char*)malloc(sizeof(char)*MAX);
		printf("�������%d����",i+1);
		scanf("%s",s[i]);
	}
	//[��]βð�����򣺲�д������1.��2.ÿһ�ֿ�ȷ��һ����ֱ�����
	for(i = 0 ; i < n ; i++) //��дn-1�����������n���ַ���
	{
		for(j = n-1 ; j-i > 0 ; j--)//j-i��ʾִ��j-i�Σ�ÿ�ֵݼ�
		{
			if(strcmp01(s[j],s[j-1]) == -1)
			{
				temp = s[j]; 
				s[j] = s[j-1]; 
				s[j-1] = temp;
			}
		}
		printf("%s\n",s[i]); //���ÿ����С
	}
    return 0;
}

//�Ƚ�01�ַ�����С
int strcmp01(char* s1,char* s2)
{
	int len1,len2,s1_cout1 = 0,s2_cout1 = 0;
	int i,j;
	len1 = strlen(s1);
    len2 = strlen(s2);
	if(len1 > len2)  return 1;
	if(len1 < len2)  return -1;
	//�ַ��ȳ�����ʼ�Ƚ�1����
	for(i = 0 ; i < len1 ; i++)
		if(s1[i] == '1')  s1_cout1++;
	for(j = 0 ; j < len2 ; j++)
		if(s2[j] == '1')  s2_cout1++;
	if(s1_cout1 == s2_cout1)  return 0;
	if(s1_cout1 >  s2_cout1)  return 1;
	if(s1_cout1 <  s2_cout1)  return -1;
}









/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100
int strcmp01(char str1[],char str2[]);
void strSort01(char *s[],int N);

int main()
{
    
	/*
	  ����1��Ϊʲô����ָ�����飿
	         �Ƚ�ʱ����ָ�뼴�ɡ��������ǳ�����ֻ��strcpy���ƿ�����
      ����2��char *s[10] �� char (*s)[10] ����
	       char *s[10]��[]���ȼ������Ⱥ�s��ϣ���ʾs�����飬��10��char*
		   char (*s)[10]��s�Ⱥ�*��ϱ�ʾs��ָ�룬ָ����10��Ԫ�ص����顣
	
   int N , i; 
   char **s; 
   printf("��ָ��Ҫ������ַ�������:");
   scanf("%d", &N); //����2����&ѽ��
   s = (char**)malloc(sizeof(char*) * N); //��ָ̬����ά�����С
   //   char *s[N]; //����3������s[]��[]���볣��
   for(i = 0; i < N ; i++)
   {
	 s[i] = (char*)malloc(sizeof(char) * MAXSIZE);
     printf("\n�������ַ���%d :",i);
	 scanf("%s",s[i]);
   } 
   //���
   strSort01(s,N);
   for(i = 0; i < N ; i++)
   {
	   printf("%s\n",s[i]);
   }
	/*strcmp01()����ͨ��
   char* s1 = "0011";
   char* s2 = "1000";
   char* s3 = "11000";
   int a = strcmp01(s1,s2); //Ӧ��Ϊ1
   int b = strcmp01(s1,s3); //Ӧ��Ϊ-1
   int c = strcmp01(s2,s3); //Ӧ��Ϊ-1
   
   return 0;
}

//�Ƚ�����01�ַ����Ĵ�С
//ATTENTION 1: strcmp()�����ȽϺͳ����޹أ�ֻ�Ƚ�
//�����ĵ�һ����ͬ�ַ���ASCII���С
int strcmp01(char *s1,char *s2) //��ָ�뿪��С��
{
  int count0_s1,count0_s2,i;
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  if(len1 > len2) 
	  return 1 ;
  if(len1 < len2)
	  return -1 ;
  //ִ�е���˵���ȳ�,ͳ��0������0��С
  for(i = 0 ; i < len1 ; i++)
  {
	  if(s1[i] == '0')
	  {
       count0_s1++;
	  }
  }
  for(i = 0 ; i < len2 ; i++)
  {
	  if(s2[i] == '0') //һ��ʼдs1..�Ұ������
	  {
       count0_s2++;
	  }
  }
  if(count0_s1 == count0_s2)//0(����˵1)�������
	  return 0;
  if(count0_s1 > count0_s2) //����4:0��˵����С��
	  return -1;
  if(count0_s1 < count0_s2)
	  return 1;
}

//���01�ַ�������
//ATTENTION1 :���������������˻���ָ��ȡ�������鳤��
//���Ի������ַ�������N
void strSort01(char **s,int N) 
{
 char *ptemp ;//��Ϊ�Ժ󽻻�ָ���ǵ�ַ��������ʱָ��
 int i , j ;
 for(i = 0 ; i < N- 1 ; i++) //n����������n-1��
	 for(j = i+1; j < N ; j++) //��ָ̬��jָ��i+1��ʼ
	 {
	  //�������5��дif(strcmp01(s[i] , s[j] ))
		 //�ᵼ��s[i] < s[j] ȡ -1ʱҲִ��
       if(strcmp01(s[i] , s[j] ) == 1) //�������У���������top��С
	   {
		   ptemp = s[i];
		   s[i] = s[j];
		   s[j] = ptemp;
	   }
	 }
}
*/