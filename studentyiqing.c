
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
 

 
struct stu_type{
	char num[3000];
	char name[20];
	char class;
	char academy;
    char province;
	char ifnormal;
	int datetime;
	int sum;
	float ave;
}; 
 
struct stu_type stu[100];
int stu_num=0;
void add();
int display(char str[]);
void modify();
void del();
void find();
void compute();
void sort();
void save_txt();
void load_txt();
void save_bin();
void load_bin();
void main()
{
	//�˵�ѡ�� 
	while(1)
	{
		int choice;
		printf("\n	��ӭʹ������ʦ����ѧѧ��ÿ�������ϱ�ϵͳ\n");
		printf("---------------------------------------------------------\n");
		printf("1.��ӻ�����Ϣ	      2.��ʾ������Ϣ\n");
		printf("3.�޸Ļ�����Ϣ	      4.ɾ��������Ϣ\n");
		printf("5.���һ�����Ϣ	      6.��ʾͳ�����\n");
		printf("7.��ѧ������	      8.�������ļ�\n");
		printf("9.���ļ�����          0.�˳�����\n");
	
		printf("----------------------------------------------------------\n");
		printf("��ѡ����ģ�飬��������0-9");
		
		while(1)		{
			scanf("%d",&choice);
			if(choice>=1 && choice<=12)
				break;
			else
				printf("�������ֲ���ȷ����������0-9��");
		}
		
		switch(choice)
		{
			case 1:	add();	break;
			case 2:	display("");	break;
			case 3: modify();	break;
			case 4: del();	break;
			case 5: find();	break;
			case 6:	compute();	break;
			case 7:	sort();	break;
			case 8:	save_txt();	break;
			case 9:	load_txt();	break;
			case 0:exit(0);
		}
	}
 }
 
//����ѧ����Ϣ 
void add()
{
	int i=stu_num;
	printf("˵������������ѧ����Ϣ���������ѧ��Ϊ0ʱ��ʾ�������\n");
	while(1)
	{
		printf("�������%d��ѧ������Ϣ\n",i+1);
		printf("������ѧ�ţ�");
		scanf("%s",stu[i].num);
		if(strcmp(stu[i].num,"0") == 0)
			break;
		printf("������������");
		scanf("%s",&stu[i].name);
		printf("���������ڰ༶��");
		scanf("%s",&stu[i].class);
		printf("����������ѧԺ��");
		scanf("%s",&stu[i].academy);
		printf("�����뵱ǰ����ʡ�ݣ�");
		scanf("%s",&stu[i].province);
		printf("�������Ƿ�������");
		scanf("%s",&stu[i].ifnormal);
		printf("������ʱ�䣺");
		scanf("%d",&stu[i].datetime) ;
		stu[i].sum = stu[i].ifnormal+1;
		i++;
	 } 
	 stu_num = i;
	 printf("�ܹ�������%d��ѧ������Ϣ\n",stu_num);
 }
 
//ͳ����Ϣ 
void compute()
{
	int i;
	char n, m;
	for(i=0; i<stu_num; i++)
	{
		if(stu[i].ifnormal==0)
			n++;
		if(stu[i].ifnormal==1)
			m++; 
	}
	printf("ͳ�ƽ�����£�\n");
	printf("���쳣������\t����������\n");
	printf("	%d	\t	%d\n",n,m); 
 }

//ɾ��ѧ����Ϣ 
void del()
{
	char str[15], m;
	int i, j;
	printf("������Ҫɾ��ѧ����ѧ�ţ�");
	scanf("%s",str);
	i = display(str);
	if(i!=-1)
	{
		printf("ȷ��Ҫɾ����ѧ������Ϣ�𣿣�y/n��");
		m = getche();
		if(m=='y' || m=='Y')
		{
			stu_num--;
			for(j=i; j<stu_num; j++)
				stu[j] = stu[j+1];
			printf("\n��¼ɾ���ɹ���\n");
		}
	}
 }
 
//��ʾ��Ϣ 
int display(char str[])
{
	int i, k=-1;
	if(strlen(str) == 0)
	{
		if(stu_num>0)
		{
			printf("ѧ��ѧ��\t����\t�༶\tѧԺ\tʡ��\t�Ƿ�����\tʱ��\n");
			for(i=0; i<stu_num; i++)
				printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\t%5.1f\n",stu[i].num,stu[i].name,
				stu[i].class, stu[i].academy, stu[i].province, stu[i].ifnormal,stu[i].datetime);
		 } 
		 else
		 	printf("ѧ����ϢΪ�գ�");
	 }
	 else
	 {
	 	for(i=0; i<stu_num; i++)
	 	{
	 		if(strcmp(str,stu[i].num) == 0)
	 		{
	 			printf("ѧ��ѧ��\t����\t�༶\tѧԺ\tʡ��\t�Ƿ�����\tʱ��\n");
	 			printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\t%5.1f\n",stu[i].num,stu[i].name,
				stu[i].class, stu[i].academy, stu[i].province, stu[i].ifnormal, stu[i].datetime);
				k = i;
			 }
		}
			 if(k==-1)
			 	printf("û���ҵ�����������ѧ��\n"); 
	}
	return k;
}
 
//����ĳѧ����Ϣ 
void find()
{
	char str[15];
	printf("������Ҫ���ҵ�ѧ��ѧ�ţ�");
	scanf("%s",str);
	
	display(str);
 }

//���ļ��ж�ȡ��Ϣ 
void load_txt()
{
	FILE * fp;
	char fname[20];
	int i=0, flag;
	printf("�������ļ���:");
	scanf("%s",fname);
	if((fp=fopen(fname,"r"))==NULL)
	{
		printf("���ܴ��ļ����ļ���ȡʧ�ܣ�\n");
		return;
	}
	while(1)
	{
		flag=fscanf(fp, "%d %s %s %s %s %s %d %d %f",stu[i].num,
		stu[i].name, &stu[i].class, &stu[i].academy, &stu[i].province, &stu[i].ifnormal,stu[i].datetime,
		&stu[i].sum, &stu[i].ave);
		
		if(flag == EOF)
			break;
		i++; 
	}
	stu_num = i;
	printf("���ļ��гɹ���ȡ%d����¼!\n",i);
	fclose(fp); 
 }

//�޸�ѧ����Ϣ
void modify() 
{
	char str[15], m;
	int i;
	printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf("%s",str);
	i = display(str);
	if(i!=-1)
	{
		printf("\nȷ���޸ĸ�ѧ������Ϣ�𣿣�y/n��\n");
		m = getche();
		if(m=='y' || m=='Y')
		{
			printf("\n�����������ѧ������Ϣ\n");
			printf("\n������ѧ�ţ�");
			scanf("%s",stu[i].num);
			printf("������������");
			scanf("%s",stu[i].name);
			printf("������༶��");
			scanf("%d",&stu[i].class);
			printf("������ѧԺ��");
			scanf("%d",&stu[i].academy);
			printf("������ʡ�ݣ�");
			scanf("%d",&stu[i].province);
			printf("�������Ƿ�������");
			scanf("%d",&stu[i].ifnormal);
			printf("������ʱ�䣺");
		    scanf("%d",&stu[i].datetime) ;	
			
		}
		
	 } 
}

//��Ϣ�������ļ��� 
void save_txt()
{
	FILE * fp;
	char fname[20];
	int i;
	printf("�������ļ�����eg��.txt��:");
	scanf("%s",fname);
	if((fp=fopen(fname,"w"))==NULL)
	{
		printf("���ܴ��ļ����ļ�����ʧ�ܣ�\n");
		return;
	}
	for(i=0; i<stu_num; i++)
		fprintf(fp, "%s %s %s %s %s %s %s %d %5.2f\n",stu[i].num, stu[i].name,
		stu[i].class, stu[i].academy, stu[i].province, stu[i].ifnormal, stu[i].datetime);
	printf("�ļ�����ɹ���\n");
	fclose(fp); 
 }
 
//��ѧ������ 
void sort()
{
	int i,j;
	struct stu_type temp;
	for(i=1; i<=stu_num; i++)
		for(j=0; j<stu_num; j++)
			if(stu[j].sum<stu[j+1].sum)
			{
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
			}
	printf("���������£�\n");
	printf("����\tѧ��ѧ��\t����\�༶\tѧԺ\tʡ��\t�Ƿ�����\tʱ��\n");
	for(i=0; i<stu_num; i++)
		printf("%d\t%-16s%s\t%s\t%s\t%s\t%s\t%d\t%5.1f\n",i+1,stu[i].num,stu[i].name, stu[i].class, 
		stu[i].academy, stu[i].province, stu[i].ifnormal,stu[i].datetime); 
}
 

