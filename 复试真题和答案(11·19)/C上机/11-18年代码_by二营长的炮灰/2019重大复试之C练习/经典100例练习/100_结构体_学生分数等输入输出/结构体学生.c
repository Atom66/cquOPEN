#include<stdio.h>

struct student
{
	int ID;
	char name[10];
	int cpp;
	int c;
	float average;
}stu;      //ATTENTION 1 : �ṹ�����������ʽ1
int main()
{
  FILE* out;
  struct student  s[2]; //ATTENTION 2 : �ṹ�����������ʽ2
  int i;
  for(i = 0 ; i < 2 ;i++)
  {
	//�״�1���Զ���Ϊ�ָ������������֮��Ĵ��󣬽���ո�/*c
    scanf("%d %s %d %d",&s[i].ID,&s[i].name,&s[i].cpp,&s[i].c);
	s[i].average = (s[i].cpp + s[i].c) / 2.0;
  }
  //д���ļ�
  out = fopen("stu.out","w");
  for(i = 0 ; i < 2 ;i++)
  {
    fprintf(out,"%d,%s,%d,%d,%f\n",s[i].ID,s[i].name,s[i].cpp,s[i].c,s[i].average);
  }
  fclose(out);
  return 0;
}