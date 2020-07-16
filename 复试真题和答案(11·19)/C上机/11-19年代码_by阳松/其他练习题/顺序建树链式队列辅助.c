#include <stdio.h> 
#include <stdlib.h>

//������ �½�ˮƽ������ 

typedef struct bnode {
	int value;
	struct bnode *left;
	struct bnode *right;
}BNode,*pBNode;

//�½���ʽ����

typedef struct lnode {
	pBNode pb;					//ָ��������ڵ��ָ�� 
	struct lnode *next;
	
}LNode,*pLNode; 

typedef struct Queue {
	int queue_cnt;
	struct lnode *front;
	struct lnode *rear;
}Queue,* pQueue; 

//�Ƚ�һ������ �����к��������Է���������� 
Queue queue; 

void en_queue (pQueue pqueue,pBNode pb); 
pBNode cat_queue (pQueue pqueue);
void de_queue (pQueue pqueue);
int is_empty_queue (pQueue pqueue);
void insert_bitree (pBNode *bitree,int value);

void in_order (pBNode pt); 

int main ()
{
	int value ;
	int i;
	pBNode bitree=NULL;
	int a[10]={20,65,32,15,36,87,5,63,39,14};
	
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);	
	}
	printf("��ʼ����\n");	
	
	for(i=0;i<10;i++)
	{
		insert_bitree(&bitree,a[i]);
	}
//	while (scanf("%d",&value)!=EOF)
//	{
//		//���� 
//		insert_bitree(&bitree,value);
//		
//	}
	//������� 
	in_order (bitree); 
	
	return 0;
}


void insert_bitree (pBNode *bitree,int value)
{
	pBNode pnew_BNode=(pBNode)calloc(1,sizeof(BNode));
	pnew_BNode->value =value;
	
	en_queue(&queue,pnew_BNode);
		pBNode ret;  //���ڽ��� cat_queue ���ص�ָ�����ڵ��ָ�� 
	if(*bitree==NULL)				//����Ϊ��ʱ ����ָ������ָ��ָ���һ���½ڵ� 
	{
		*bitree= pnew_BNode; 
	}else
	{
		if(is_empty_queue(&queue)!=1)
		{
			ret=cat_queue(&queue);
			if(ret->left ==NULL)		//���ýڵ����ָ��ΪNULL���ͽ��½��Ľڵ�ָ�����ӵ��ýڵ����ָ���� 
			{
				ret->left =pnew_BNode;
			}else
			{
				ret->right =pnew_BNode;
				//���� 
				de_queue(&queue);
			}
		}
	}
	
}

void in_order (pBNode pt)		//������������� 
{
	if(pt!=NULL)
	{
		in_order(pt->left );
		printf("%d\t",pt->value  ) ;
		in_order(pt->right );
	}
}

void en_queue (pQueue pqueue,pBNode pb)
{
	 pLNode pnew_queue=(pLNode)calloc(1,sizeof(LNode));
	 pnew_queue->pb =pb;
	 if(pqueue->front ==NULL)
	 {
	 	pqueue->front=pqueue->rear =pnew_queue;
	 }else
	 {
	 	pqueue->rear->next =pnew_queue;
	 	pqueue->rear=pnew_queue;
	 }
 	pqueue->queue_cnt ++;	
}

void de_queue (pQueue pqueue)
{
	pLNode pcur;

	pcur=pqueue->front ;
	pqueue->front =pcur->next ;

	free(pcur);
	if(pqueue->front==NULL)
	{
		pqueue->rear =NULL;
	}
	pqueue->queue_cnt --;

}

pBNode cat_queue (pQueue pqueue)
{
	pLNode pcur;
	pBNode ret;
	pcur=pqueue->front ;
	ret=pcur->pb ;
	return ret;
}

int is_empty_queue (pQueue pqueue)
{
	if(pqueue->queue_cnt ==0)
	{
		return 1;
	}else
	{
		return 0;
	}
}
