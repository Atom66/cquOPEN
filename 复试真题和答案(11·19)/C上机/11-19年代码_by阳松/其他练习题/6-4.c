#include <stdio.h>
#include <stdlib.h>

//��һ����¼ѧ����Ϣ���ļ���ÿһ�м�¼һ��ѧ������Ϣ����ʽ���� ѧ��\t ����\t �Ա�\t ���� 1\t ���� 2\t ���� 3\n. Ҫ��
//��1����ȡ�ļ������ݣ�����һ������ ��2�������ֵܷݼ����򽫽�����浽ԭ�ļ���
#define N 50

typedef struct student {
	int id;
	char name [20];
	int sex;
	double score1,score2,score3;
	double sum;
	struct student *next;
	
}stu,*pstu;

void insert_sort_list (pstu *pphead,pstu *pptail,pstu pnew)	;

int main (){
	FILE *fin,*fout;
	pstu phead,ptail;
//	int cnt=0;
	pstu p;
	int ret;
	phead=ptail=NULL;
	
	fin=fopen("filename.in","r");
	fout=fopen("filename.out","w");
	if(fin==NULL||fout==NULL)
	{
		printf("�ļ���ʧ��");
		exit(1); 
	}
	p=(pstu)calloc(1,sizeof(stu));
	while((ret=fscanf(fin,"%d%s%d%lf%lf%lf",&p->id ,p->name ,&p->sex ,&p->score1 ,&p->score2 ,&p->score3 ))==6)			//ȡ��ַ���� 
	{
		p->sum =p->score1 +p->score2+p->score3;
//		s[cnt++]=p;
		insert_sort_list (&phead,&ptail,p)	;
		
		p=(pstu)calloc(1,sizeof(stu));
		if(p==NULL)
		{
			printf("��̬���ɿռ�ʧ��");
			exit(1); 
		}		
	}
	
	p=phead;
	while (p!=NULL)
	{
		fprintf(fout,"%d\t%s\t%d\t%lf\t%lf\t%lf\t%lf\n",p->id ,p->name ,p->sex ,p->score1 ,p->score2 ,p->score3,p->sum  );
		
		p=p->next ; 
	}
	return 0;
} 
 
void insert_sort_list (pstu *pphead,pstu *pptail,pstu pnew)			//�������� 
{
	pstu pprev,pcur;
	pprev=pcur=*pphead;

	if(*pphead==NULL)			//��ǰ����Ϊ�� 
	{			
		*pphead=pnew;
		*pptail=pnew;
	}else	if(pnew->sum >pcur->sum )			//��ͷ��� ǰ����� 
	{
		pnew->next =pcur;
		*pphead=pnew;
		
	}else					//����Ϊ�м�ڵ����β��� 
	{
		pcur=pcur->next ;
		while (pcur!=NULL)
		{
			if(pcur->sum > pnew->sum )
			{
				pprev=pcur;
				pcur=pcur->next ;
			}else
			{
				pnew->next =pcur;
				pprev->next =pnew;
				break;
			}
		}
		
		if (pcur==NULL)
		{
			pprev->next =pnew;
			*pptail=pnew;
		}
	}
	
	
}


