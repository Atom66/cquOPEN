# include <stdio.h>

//99�����ɶ���������Ӷ��� 

int main (){
	
	
	int cnt=0;
	int i;
	
	
	for(i=1;i<(99.0/2);i++){
		printf("%d+%d=99\n",i,99-i);
		cnt++;
	} 
	
	printf("%d",cnt);
	return 0;
} 
