#include <stdio.h>
#include <stdlib.h>


//���������� a��b����a������ɾ����b��������ͬ��Ԫ��

typedef struct student{
	int num;
	struct student *next;
}Node,*pNode;
int main ()
{
	
	return 0;	
} 

void delete_list_a (pNode phead1,pNode phead2)		//������������������� 
{
	pNode p1,prev;
	pNode p2= phead2;
	p1=prev= phead1;
	pNode pt;
	while (p1==NULL||p2==NULL)
	{
		if(p1->num <p2->num )
		{
			prev=p1;
			p1=p1->next ;
		}else if(p1->num >p2->num)
		{
			p2=p2->next ;
		}else		//�����ڵ��ѧ����ͬ ����ô��ɾ�� phead1 �Ľڵ� 
		{
			//ɾ�� ����Ľڵ�
			pt=p1;
			p1=pt->next ;
			
			if(pt==phead1)
			{
				phead1=phead1->next ;
				free(pt);
			}else
			{
				prev->next =p1;
				free(pt);
			}
			
		}
	}
}
