# include <stdio.h>
#include <string.h>
#include <stdlib.h>

//���ļ��и�����һ��Ӣ�ģ��ָ���Ϊ�ո�Ӣ�Ķ��ţ���ţ���Ҫ���¼ÿ�����ʳ��ֵĴ��������Ұ������������ 

#define N 200		//N ��ʾstr �ַ���������� 
#define SIZE 20		//SIZE ��ʾ �ַ�ָ������� ���ȣ������ʵĸ��� ������ͬʱҲ�ǵ������ʳ��ȵ�����		

void mycopy (char *s[SIZE],int cnt,char *str,int head,int tail);
int divide (char *s[SIZE],char *str);

void count_words(int *a,char* s[SIZE],int cnt);

typedef struct word{
	char *s;				//ָ�򵥴ʵ� �ַ�ָ�� 
	int conut;			// ���ʳ��ֵ�Ƶ�� 
	
}word;
 
int main (){
	
	char str[N];
	char *s[SIZE];		//�ַ�ָ����ֵ ����Ϊ SIZE  
	FILE *fin;			//�ļ�ָ��
	int a[SIZE];		// ���� a �д洢�˵��ʵ�ͳ�ƴ���  ���� i ��ʾ���ʵ��±꣬a[i] ��ʾ�±�Ϊ i �ĵ��ʳ��ֵĴ�ʱ 
	
	word w[SIZE];		//�ṹ������  
	word temp;
	int i;
	int j;
	int cnt_1;
	 
	int cnt;			//���ʸ��� 
	fin=fopen("filename.txt","r");
	
	fgets(str,N,fin);
	
//	puts(str);			//������ļ�������һ��Ӣ�� 
	
	cnt=divide(s,str);		//��str �е�һ��Ӣ�� ���Ϊ���� ���� �ַ�ָ�������� 
	
	printf("%d\n",cnt);
	
//	for(i=0;i<cnt;i++){
//		printf("%s\n",s[i]);
//	} 
	
	count_words(a,s,cnt);	//���� ���ʼ��� 		//����������д����⡱ 
	
	for(i=0,j=0;i<cnt;i++){
		if(a[i]>0){
			w[j].s =s[i];
			w[j].conut =a[i];
			j++	;
		}
	}
	//������� 
	cnt_1=j;				//û���ظ��ĵ����� 
	
	for(i=cnt_1-1;i>0;i--){
		for(j=0;j<i;j++){
			if(w[j].conut >w[j+1].conut ){
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
			}
		}
	}
	
	for(i=cnt_1-1;i>=0;i--){
		printf("%s\t\t%d\n",w[i].s ,w[i].conut );
	}

	
	return 0;
} 

int divide (char *s[SIZE],char *str){		//divide �����ķ���ֵ���зֵ��ʵĸ��� 
	
	int i;
	int len;
	int flag=0;		//flag==1 ����ǰ���ڶ�ȡһ�����ʣ� flag==0 ����ǰû�ж�ȡһ������ //flag Ĭ����Ϊ ��1�� 
	int cnt=0;		//cnt ��ʾ���ʸ��� 	��ʼ������Ϊ0 
	int index;		//�����ʵĿ�ͷ��ĸ��str�е��±� 
	len=strlen(str);
	
	for(i=0;i<len;i++){
		if(str[i]==' '||str[i]==','||str[i]=='.'){
			if(flag==1){
				//����һ�����ʽ��� 
				cnt++; 
				mycopy(s,cnt,str,index,i); 		//����mycopy���� ����ǰ���ʸ��Ƶ��ַ�ָ�������� 
				flag=0;
			}
		}else{
			if(flag==0){
				//����һ�����ʿ�ʼ 
				index=i;
				flag=1;
			}
		} 
	} 

	return cnt;	
}

void mycopy (char *s[SIZE],int cnt,char *str,int head,int tail){		//mycopy ������divide�����зֵĵ��� ���Ƶ��ַ�ָ�������� 
	
	char *ret; 
	int i,j=0;
	ret=(char*)malloc(sizeof(char)*SIZE);
	
	for(i=head;i<tail;i++){
		ret[j++]=str[i];
	} 
	ret[j]='\0';
	
	s[cnt-1]=ret;
} 


//����������ַ�ָ��������ͳ�Ƶ��ʳ��ֵĴ���������ͳ�ƽ������ int ������

void count_words(int *a,char* s[SIZE],int cnt){
	
	int i,j;
	
	char * aux[cnt];
	
	for(i=0;i<cnt;i++){
		aux[i]=s[i];		//���ַ�ָ�����飬����һ������ 
	}
	

	
	for(i=0;i<cnt;i++){
		a[i]=0;				//��ͳ�Ƶ��ʳ��ִ��������� a ��ʼ��Ϊ 0  
		if(strcmp(aux[i],"-1")!=0){		//���жϸõ����Ƿ��Ѿ�ͳ�ƹ������Ϊ NULL ��Ϊͳ�ƹ��ĵ��� 
			a[i]++;
			for (j=i+1;j<cnt;j++){
				if(strcmp(aux[i],aux[j])==0){				// "segmentation fault"   "strcmp () ����Ĳ�������ΪNULL"
					a[i]++;
					strcpy(aux[j],"-1"); 
				}
			}	
		}
		
	}
//������� 
} 

 
