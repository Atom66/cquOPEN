#include <stdio.h>

//��һ���������á� �磺 1->2 ->3 ->4 ->5 ->NULL�� ���: 5 -> 4 -> 3 ->2 ->1 -> NULL ��
typedef struct student {
	int number;
	char name [20];
	double score;
	struct student *next;
}stu,*pstu;

int main (){
	
	
	
	return 0;
}

void reverse_list (pstu *pphead,pstu *pptail)			//�������� 
{
	
	pstu prev,pcur;
	pstu pnext=NULL;
	prev=pcur=*pphead;
	if(pcur==NULL)
	{
		return;
	}
	pcur=pcur->next ;
	while (pcur!=NULL)
	{
		pnext=pcur->next ;
		pcur->next =prev;
		prev=pcur;
		pcur=pnext;
	}
	
	(*pphead)->next =NULL;
	*pptail=*pphead;
	*pphead=prev;
	
}
