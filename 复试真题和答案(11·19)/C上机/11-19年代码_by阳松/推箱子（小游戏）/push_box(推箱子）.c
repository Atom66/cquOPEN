# include <stdio.h>
#include <conio.h>
#include <windows.h>

typedef struct {	
	char name [20];				//�û��� 
	char password[20];			//���� 
	int gate;					//������¼ 
}user;

void Register ();
int  Login ();
void play ();
void ReadMap(char map[14][16], int n);
void get_person(int *x,int *y,char map[14][16]);
void presskey(char map[14][16],int *end); 
void chose_gate (int key,int *ret);
void save_counts();
void open_counts(); 

void printmap(char map[14][16]);


user players[20];			//�ṹ�����飬�洢�û����� 
int cnt;					//�����û��� 

int main (){
	
	char judge;
	int key;
	open_counts();
	
	printf("��ӭ������������Ϸ"); 
	while(1){
		printf("\n****************\n"); 
		printf("1. ע�����û�\n");
		printf("2. ��¼\n");
		printf("3. ������Ϣ\n");
		printf("4. �˳�����\n");
		
		judge=getch();
		switch(judge){
			case '1' :
				Register();				//ע�����û�ģ�� 
				break;
				
			case '2' :
				key=Login ();				//��¼��������Ϸ 
//				��ʼѡ�ز����� 
				play (key);
				break;
				
			case '3' :
				printf("\n****************\n"); 
				printf("����\n");
				printf("\n");
				printf("@��Ц��");
				printf("\n****************\n"); 
				break;
				
			case '4' :
				save_counts();
				return 0;
				
			default :
				printf("������������������"); 
				break;			
		}
		
		
	} 
	
}



void Register (){

	char temp [20],confirmpassword[20];
	user nuser; 				//���û� 
	
	int i,flag=1;				//flag =1  �����û�������û���û���ظ��������û����ظ� 

	
	
	
	while (1){
		flag=1;//Ĭ���û������ظ���flag==1, 
		printf("�������û���");
		scanf("%s",temp);
		 
		for(i=0;i<cnt;i++){
			if(strcmp(players[i].name,temp)==0 ){
				printf("�û����Ѵ���\n");
				flag=0; 
				break;
			}
		}
		
		if(flag==1){
			strcpy(nuser.name,temp);
			break;
		}
		
	}
	
	while (1){
		printf("����������:");
		scanf("%s",temp);
		printf("ȷ�����������:");
		scanf("%s",confirmpassword);
		
		if(strcmp(temp,confirmpassword)==0) {
			strcpy(nuser.password ,temp);
			nuser.gate =1;		//Ĭ���½��û��ĵ�ǰ����ؿ�Ϊ 1����û�п�ʼ���� , 
			players[cnt++]=nuser;					//���½����û�������洢�û����ݵ������� 
			break; 
		}
		printf("������������벻ƥ��\n");
	}
	

} 

void open_counts()
{
	FILE *fin;
	cnt=0;		//�û����ʼΪ 0�� 
	fin=fopen("user.txt","r");
	
	if(fin==NULL){
		printf("��ȡ�û�����ʧ��");
		exit(1); 
	}
	
	while (!feof(fin)){	
		if(fread(&players[cnt],sizeof(user),1,fin)==1)
		{
			cnt++;		//ͳ���˺Ÿ���; 
		}
	}
	fclose(fin);
}

void save_counts()		//���û��˻����� user .txt 
{
	FILE *fout;
		//���û���������д�� user.txt   ��
	 
	fout=fopen("user.txt","w");
	if(fout==NULL){
		printf("д���û�����ʧ��");
		exit(1); 
	}
	fwrite(players,sizeof(user),cnt,fout);
	fclose(fout);
}


int  Login ()
{
	char temp [20],password[20];
	int i,key=-1;				//key  �����û��������û������е��±� 
	
//	user players[20];			//�ṹ�����飬�洢�û����� 

//	int cnt=0;					//�����û��� 
	
//	FILE *fin; 
//	fin=fopen("user.txt","r");
//	
//	if(fin==NULL){
//		printf("��ȡ�û�����ʧ��");
//		exit(1); 
//	}
	
//	while (!feof(fin)){
//		if(fread(&players[cnt],sizeof(user),1,fin)==1) 
//		{
//			cnt++;
//		}	
//	}
//	fclose(fin);
//	
	while (1){
		printf("�������û�����");
		scanf("%s",temp);
		 
		for(i=0;i<cnt;i++){
			if(strcmp(players[i].name,temp)==0 ){
				//�ҵ�Ŀ���û� 
				key=i; 
				goto breakHere;
			}
		}
		
		printf("��������û���������\n");
		
	}
	
breakHere :
	
	while (1){
		printf("���������룺");
		scanf("%s",password);
		
		if(strcmp(players[key].password,password)==0 ){
				//�ҵ�Ŀ���û� 
				printf("��¼�ɹ�\n");
				return key;			//���ص�¼�ɹ����˺� key Ϊplayer ���±� 
			}else{
				printf("�����������\n");
			}
	}
	
	
}

void chose_gate (int key,int *ret)
{
	int n;
	printf("\n1.���ϴ���Ĺؿ���ʼ\n");
	printf("\n2.����ѡ��ؿ�\n");
	scanf("%d",&n);
	switch (n){
		case 1:
			n= players[key].gate ;
			break;
		case 2:
			while (1){
				printf("\n��ѡ��ؿ�\n");
				scanf("%d",&n);
				if(n>=1&&n<=43){
					break;
				}else{
					printf("�ؿ���ΧΪ1-43\n");
				}
			}
	}

	*ret=n;
}


void play (int key){
	int n;
	int end =0;		//end ==1 �Ǵ����û�����������Ϸ 
	chose_gate (key,&n);
	char map[14][16];
	ReadMap(map,n);
	
	//��ʼ play 
	while (1){
		system("cls");
		printmap(map);			//��ӡ��ͼ 
		presskey(map,&end);
		if(end==1)
		{
			//������Ϸ 
			system("cls");
			printf("\n****************\n"); 
			printf("\n������Ϸ ,��ӭ�´�����\n");
			printf("\n��������ص����˵�\n");
			players[key].gate =n;
			system("pause");
			break; 
		}else
		{
			if(countbox(map)==0){
				system("cls");
				printmap(map);	
				printf("��ϲͨ�أ�����������һ��\n");
				n++;
				
				if(n<=43){
					ReadMap(map,n);
				} else{
					printf("ȫ���ؿ��������滵��\n");
				}
			}			
		}
	}
	
	
	
	
} 



void ReadMap(char map[14][16], int n)  //����ͼ
{
	FILE *fp;
	int i, j;
	int step;

	fp = fopen("map.txt", "r");

	if (fp == NULL) {
		printf("�򿪵�ͼ�ļ�����!\n");
		exit(1);
	}

	if (n < 10)
		step = 257 * (n - 1) + 5;
	else
		step = 257 * 9 + 258 * (n - 10) + 6;

	fseek(fp, step, 0);	//�ض�λ�ļ��ڲ�λ��ָ�룬0Ϊ��㣬stepΪƫ���� 
	for (i = 0; i < 14; i++) {
		for (j = 0; j < 16; j++) {
			map[i][j] = fgetc(fp);
		}
		fgetc(fp);				//���з�����ȡ 
	}
	fclose(fp);
}

void printmap(char map[14][16]){
/*0:		//�յ�
1:		//ǽ
2:		//�ڲ��յ�
3:		//Ŀ�ĵ�
4:		//����
5:		//�����Ƶ�Ŀ�ĵغ���ʾ
6:		//С��
7:      //����Ŀ�ĵ�
*/
	int i, j;
	char t;
	
	for (i = 0; i < 14; i++) {
		for (j = 0; j < 16; j++) {
			t=map[i][j];
			switch(t){
				case '0':
					printf("  ");
					break;
				case '1':
					printf("��");
					break;
				case '2':
					printf("  ");
					break;
				case '3':
					printf("��");
					break;
				case '4':
					printf("��");
					break;
				case '5':
					printf("��");
					break;
				case '6':
				case '7':
					printf("��");
					break;
	
			}
			
			
			
		}
		
		printf("\n");
	}
	
	
	
}

void presskey(char map[14][16],int *end){
	int x,y;
	get_person(&x,&y,map);
	char opt;
	opt=getch();
	switch(opt){
		case 'w': 
		case 'W':
		case 38:
			if(map[x-1][y]=='2'){			//��ǰ���ǿյ� 
				if (map[x][y] == '7')//����Ŀ�ĵ�
					{
						map[x][y] = '3';//Ŀ�ĵ� 
						map[x - 1][y] = '6';//�� 
					}
					else //���ڿյ�
					{
						map[x - 1][y] = '6';//�� 
						map[x][y] = '2';//�ڲ��յ� 
					}
			}else if(map[x-1][y]=='3'){		// ��ǰ����Ŀ�ĵ� 
				if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
					map[x][y]='2';
					map[x-1][y]='7'; 
				}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
					map[x][y]='3';
					map[x-1][y]='7'; 
				}
			}else if(map[x-1][y]=='4'){		//��ǰ�������� 
				if(map[x-2][y]=='2'){		//����ǰ���ǿյ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
					
						map[x][y]='2';
						map[x-1][y]='6';
						map[x-2][y]='4';
						 
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x-1][y]='6';
						map[x-2][y]='4';
					}
				}else if(map[x-2][y]=='3'){		//����ǰ����Ŀ�ĵ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x-1][y]='6';
						map[x-2][y]='5';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x-1][y]='6';
						map[x-2][y]='5';
					}
				}
			}else if(map[x-1][y]=='5'){		//��ǰ����������Ŀ�ĵ� 
				if(map[x-2][y]=='2'){		//����ǰ���ǿյ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x-1][y]='7';
						map[x-2][y]='4';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x-1][y]='7';
						map[x-2][y]='4';
					}
				}else if(map[x-2][y]=='3'){		//����ǰ����Ŀ�ĵ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x-1][y]='7';
						map[x-2][y]='5';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x-1][y]='7';
						map[x-2][y]='5';
					}
				}
			}
		break;
		
		case 'a':
		case 'A':
		case 37:
			if(map[x][y-1]=='2'){			//��ǰ���ǿյ� 
				if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
					
					map[x][y]='2';
					map[x][y-1]='6'; 
					
				}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
					
					map[x][y]='3';
					map[x][y-1]='6'; 
				}	
			}else if(map[x][y-1]=='3'){		// ��ǰ����Ŀ�ĵ� 
				if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
				
					map[x][y]='2';
					map[x][y-1]='7'; 
					
				}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
				
					map[x][y]='3';
					map[x][y-1]='7'; 
				}
			}else if(map[x][y-1]=='4'){		//��ǰ�������� 
				if(map[x][y-2]=='2'){		//����ǰ���ǿյ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
					
						map[x][y]='2';
						map[x][y-1]='6';
						map[x][y-2]='4';
						 
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x][y-1]='6';
						map[x][y-2]='4';
					}
				}else if(map[x][y-2]=='3'){		//����ǰ����Ŀ�ĵ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x][y-1]='6';
						map[x][y-2]='5';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x][y-1]='6';
						map[x][y-2]='5';
					}
				}
			}else if(map[x][y-1]=='5'){		//��ǰ����������Ŀ�ĵ� 
				if(map[x][y-2]=='2'){		//����ǰ���ǿյ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x][y-1]='7';
						map[x][y-2]='4';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x][y-1]='7';
						map[x][y-2]='4';
					}
				}else if(map[x][y-2]=='3'){		//����ǰ����Ŀ�ĵ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x][y-1]='7';
						map[x][y-2]='5';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x][y-1]='7';
						map[x][y-2]='5';
					}
				}
			}
		break;
		
		case 'd':
		case 'D':
		case 39:
			if(map[x][y+1]=='2'){			//��ǰ���ǿյ� 
				if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
					
					map[x][y]='2';
					map[x][y+1]='6'; 
					
				}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
					
					map[x][y]='3';
					map[x][y+1]='6'; 
				}	
			}else if(map[x][y+1]=='3'){		// ��ǰ����Ŀ�ĵ� 
				if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
				
					map[x][y]='2';
					map[x][y+1]='7'; 
					
				}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
				
					map[x][y]='3';
					map[x][y+1]='7'; 
				}
			}else if(map[x][y+1]=='4'){		//��ǰ�������� 
				if(map[x][y+2]=='2'){		//����ǰ���ǿյ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
					
						map[x][y]='2';
						map[x][y+1]='6';
						map[x][y+2]='4';
						 
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x][y+1]='6';
						map[x][y+2]='4';
					}
				}else if(map[x][y+2]=='3'){		//����ǰ����Ŀ�ĵ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x][y+1]='6';
						map[x][y+2]='5';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x][y+1]='6';
						map[x][y+2]='5';
					}
				}
			}else if(map[x][y+1]=='5'){		//��ǰ����������Ŀ�ĵ� 
				if(map[x][y+2]=='2'){		//����ǰ���ǿյ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x][y+1]='7';
						map[x][y+2]='4';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x][y+1]='7';
						map[x][y+2]='4';
					}
				}else if(map[x][y+2]=='3'){		//����ǰ����Ŀ�ĵ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x][y+1]='7';
						map[x][y+2]='5';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x][y+1]='7';
						map[x][y+2]='5';
					}
				}
			}	
		break;
		
		case 's':
		case 'S':
		case 40:
			if(map[x+1][y]=='2'){			//��ǰ���ǿյ� 
				if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
					map[x][y]='2';
					map[x+1][y]='6'; 
				}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
					map[x][y]='3';
					map[x+1][y]='6'; 
				}	
			}else if(map[x+1][y]=='3'){		// ��ǰ����Ŀ�ĵ� 
				if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
					map[x][y]='2';
					map[x+1][y]='7'; 
				}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
					map[x][y]='3';
					map[x+1][y]='7'; 
				}
			}else if(map[x+1][y]=='4'){		//��ǰ�������� 
				if(map[x+2][y]=='2'){		//����ǰ���ǿյ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
					
						map[x][y]='2';
						map[x+1][y]='6';
						map[x+2][y]='4';
						 
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x+1][y]='6';
						map[x+2][y]='4';
					}
				}else if(map[x+2][y]=='3'){		//����ǰ����Ŀ�ĵ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x+1][y]='6';
						map[x+2][y]='5';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x+1][y]='6';
						map[x+2][y]='5';
					}
				}
			}else if(map[x+1][y]=='5'){		//��ǰ����������Ŀ�ĵ� 
				if(map[x+2][y]=='2'){		//����ǰ���ǿյ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x+1][y]='7';
						map[x+2][y]='4';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x+1][y]='7';
						map[x+2][y]='4';
					}
				}else if(map[x+2][y]=='3'){		//����ǰ����Ŀ�ĵ� 
					if(map[x][y]=='6'){//�˵�ǰ�������ǿյ� 
						
						map[x][y]='2';
						map[x+1][y]='7';
						map[x+2][y]='5';
						
					}else if(map[x][y]=='7'){//�˵�ǰ��������Ŀ�ĵ� 
						
						map[x][y]='3';
						map[x+1][y]='7';
						map[x+2][y]='5';
					}
				}
			}
		break;
		case 'e': 
		case 'E':
			*end=1;		//���������Ϸ�� 
		break;	
	}
	
} 

void get_person(int *x,int *y,char map[14][16]){
	int i, j;
	
	
	for (i = 0; i < 14; i++) {
		for (j = 0; j < 16; j++){
			if(map[i][j]=='6'||map[i][j]=='7'){
				*x=i;
				*y=j;
			}
		}
	}
}

int countbox(char map[14][16]){
	int i, j;
	char t;
	int cnt_box=0;
	
	for (i = 0; i < 14; i++) {
		for (j = 0; j < 16; j++){
			if(map[i][j]=='4'){
				cnt_box++;
			}
		}
	}
	
	return cnt_box;	
}


 

