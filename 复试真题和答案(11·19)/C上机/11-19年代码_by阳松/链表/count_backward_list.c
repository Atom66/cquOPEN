#include <stdio.h>

//�ҳ�����ĵ������ĸ��ڵ�
typedef struct student {
	int number;
	char name [20];
	double score;
	struct student *next;
}stu,*pstu;

int main (){
	
	
	
	return 0;
}


pstu find_backward_list (pstu phead,int n)		//�ҵ�����ĵ�����n����� 
{
	
	pstu prev,pcur;
	int cnt=0;//��¼���ƫ���˼������� 
	prev=NULL;
	pcur=phead;
	while(pcur->next !=NULL&&cnt<n-1)
	{
		pcur=pcur->next ;
		cnt++; 
	}
	if(cnt==n-1)
	{
		while (pcur!=NULL)
		{
			if(prev==NULL)
			{
				prev=phead;
				
			} else
			{
				prev=prev->next ;
				
			}
			pcur=pcur->next ;
		}
	}
	
	return prev;
}
