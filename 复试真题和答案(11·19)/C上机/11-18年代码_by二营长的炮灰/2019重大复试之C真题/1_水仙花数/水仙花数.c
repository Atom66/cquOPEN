#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isNarci(int num);
int main()
{
	int num;
	FILE* in,*out;
	in  = fopen("number.in","r");
	out = fopen("number.out","w");
	if(!in || !out)
	{
		printf("failture to open file!");
		exit(1);
	}
	//ѭ����д�ļ�+�ж�
	while(1)
	{
		fscanf(in,"%d",&num);
		if(num == 0)  //�����0�жϽ�����Ҳ��while(!feof(in)) 
			break;
		if(isNarci(num))
			fprintf(out,"%s","T\n"); //�ٴ�0:\n��%s������%c
		else
			fprintf(out,"%s","F\n");	    
	}
	fclose(in);  //�ٴ�1�����ر��ļ���������ļ�������ʾ
	fclose(out);
    return 0;
}

//nλˮ�ɻ�����n��=3�������� = ��λ��^n + ʮλ��^n + ��λ��^n + ...
int isNarci(int num)
{
	int n = 0;  //�жϼ�λ����ʹ��ǰҪ��0��
	int temp = num;
	int sum = 0; //����ˮ�ɻ���
	while(temp != 0) //�����жϼ�λ��������
	{
		n++;
		temp = temp / 10;
	}
	if(n <3 )
		return 0;  //����
	temp = num;     //�ٴ�2������ı�num������tempҲ������num�����¸�ֵ
	while(temp != 0)
	{
		//temp = temp % 10; //�ٴ�3:tempֻ��ı�ȥ��λ��temp/10��
		sum += pow(temp%10,n);
		temp = temp / 10;
	}
	return num == sum;
}










/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void readFile(FILE* in);             //�״�0�����ܷ�������
void outPutFile(FILE* out);          //�״�1��int[] num����FILE���д
int isNarcissisticNumber(int num);
#define MAXSIZE 100
int nums[MAXSIZE];       //����ֵ���������飬���巵��ָ�벻����ɴ�ȫ������

void main()
{
	FILE* in,* out;                 //�״�2��ֻ���ڿ�ͷ�����ļ�FILE����ָ�룬���ֱܷ���
	//���ļ�number.in��ע�⡰r��
    in = fopen("number.in","r"); 
	if(!in)
	{
		printf("Failturn to open file!");
	}
	//int nums[] = readFile(in);       //�״�3����������ָ�볣��������ȫ������
    readFile(in);
	fclose(in);

	//���ļ�number.out��ע�⡰w��
	out = fopen("number.out","w"); 
	if(!out)
	{
		printf("Failturn to open file!");
	}
    outPutFile(out);
	fclose(out);
}


//nλˮ�ɻ�����n��=3�������� = ��λ��^n + ʮλ��^n + ��λ��^n + ...
int isNarcissisticNumber(int num)
{
  int count = 0;//�ж��Ǽ�λ��
  int sum   = 0;//�ƺ�
  int temp  = num; //��������count��ʱ����
  while(temp != 0)
  {
	  temp = temp / 10; //ÿ�ζ�ȥ�����λ��ֱ��Ϊ0:153 - 15  15- 1 1-0
	  count++;
  }
  if(count < 3) //ˮ�ɻ���λ�������3
  {
	  return 0;
  }
  temp = num;      //�״�4���ٴδ洢numֵ����������num���м��㣬�������num=0�����ܺ�sum�Ƚ�
  while(temp != 0)
  {
	  sum += pow(temp % 10 ,count); //��ȡ���λ��n�η�
	  temp = temp/10;//ȥ�����λ����nλ-->n-1λ����
  }
  if(sum == num){ return 1; }
  else          { return 0; }
}


//�����ļ�number.in:���ļ�����д������
void readFile(FILE* in)
{
	int i = 0; 
	while(!feof(in))   //�״�5:����forѭ��
	{
      fscanf(in,"%d",nums+i); //�״�6: %s -->%d
	  i++;
	}

}

//�����ļ�number.out:�ж��Ƿ���ˮ�ɻ�����д��
void outPutFile(FILE* out)
{
	int i ;
	for(i = 0; nums[i] != 0;i++)       //�״�7��c����forѭ�����������涨�� int i=0
	{
		if(isNarcissisticNumber(nums[i]))//��ˮ�ɻ���
		{
         fprintf(out,"%s","T\n");
		}
		else
		{
         fprintf(out,"%s","F\n");
		}
	}
}
*/