
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
	//菜单选择 
	while(1)
	{
		int choice;
		printf("\n	欢迎使用西北师范大学学生每日疫情上报系统\n");
		printf("---------------------------------------------------------\n");
		printf("1.添加基本信息	      2.显示基本信息\n");
		printf("3.修改基本信息	      4.删除基本信息\n");
		printf("5.查找基本信息	      6.显示统计情况\n");
		printf("7.按学号排序	      8.保存至文件\n");
		printf("9.从文件读入          0.退出程序\n");
	
		printf("----------------------------------------------------------\n");
		printf("请选择功能模块，输入数字0-9");
		
		while(1)		{
			scanf("%d",&choice);
			if(choice>=1 && choice<=12)
				break;
			else
				printf("输入数字不正确，请重输入0-9：");
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
 
//增加学生信息 
void add()
{
	int i=stu_num;
	printf("说明：依次输入学生信息，当输入的学号为0时表示输入结束\n");
	while(1)
	{
		printf("请输入第%d个学生的信息\n",i+1);
		printf("请输入学号：");
		scanf("%s",stu[i].num);
		if(strcmp(stu[i].num,"0") == 0)
			break;
		printf("请输入姓名：");
		scanf("%s",&stu[i].name);
		printf("请输入所在班级：");
		scanf("%s",&stu[i].class);
		printf("请输入所在学院：");
		scanf("%s",&stu[i].academy);
		printf("请输入当前所在省份：");
		scanf("%s",&stu[i].province);
		printf("请输入是否正常：");
		scanf("%s",&stu[i].ifnormal);
		printf("请输入时间：");
		scanf("%d",&stu[i].datetime) ;
		stu[i].sum = stu[i].ifnormal+1;
		i++;
	 } 
	 stu_num = i;
	 printf("总共已输入%d个学生的信息\n",stu_num);
 }
 
//统计信息 
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
	printf("统计结果如下：\n");
	printf("有异常总人数\t正常总人数\n");
	printf("	%d	\t	%d\n",n,m); 
 }

//删除学生信息 
void del()
{
	char str[15], m;
	int i, j;
	printf("请输入要删除学生的学号：");
	scanf("%s",str);
	i = display(str);
	if(i!=-1)
	{
		printf("确认要删除该学生的信息吗？（y/n）");
		m = getche();
		if(m=='y' || m=='Y')
		{
			stu_num--;
			for(j=i; j<stu_num; j++)
				stu[j] = stu[j+1];
			printf("\n记录删除成功！\n");
		}
	}
 }
 
//显示信息 
int display(char str[])
{
	int i, k=-1;
	if(strlen(str) == 0)
	{
		if(stu_num>0)
		{
			printf("学生学号\t姓名\t班级\t学院\t省份\t是否正常\t时间\n");
			for(i=0; i<stu_num; i++)
				printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\t%5.1f\n",stu[i].num,stu[i].name,
				stu[i].class, stu[i].academy, stu[i].province, stu[i].ifnormal,stu[i].datetime);
		 } 
		 else
		 	printf("学生信息为空！");
	 }
	 else
	 {
	 	for(i=0; i<stu_num; i++)
	 	{
	 		if(strcmp(str,stu[i].num) == 0)
	 		{
	 			printf("学生学号\t姓名\t班级\t学院\t省份\t是否正常\t时间\n");
	 			printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\t%5.1f\n",stu[i].num,stu[i].name,
				stu[i].class, stu[i].academy, stu[i].province, stu[i].ifnormal, stu[i].datetime);
				k = i;
			 }
		}
			 if(k==-1)
			 	printf("没有找到符合条件的学生\n"); 
	}
	return k;
}
 
//查找某学生信息 
void find()
{
	char str[15];
	printf("请输入要查找的学生学号：");
	scanf("%s",str);
	
	display(str);
 }

//从文件中读取信息 
void load_txt()
{
	FILE * fp;
	char fname[20];
	int i=0, flag;
	printf("请输入文件名:");
	scanf("%s",fname);
	if((fp=fopen(fname,"r"))==NULL)
	{
		printf("不能打开文件，文件读取失败！\n");
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
	printf("从文件中成功读取%d条记录!\n",i);
	fclose(fp); 
 }

//修改学生信息
void modify() 
{
	char str[15], m;
	int i;
	printf("请输入要修改的学生学号：");
	scanf("%s",str);
	i = display(str);
	if(i!=-1)
	{
		printf("\n确认修改该学生的信息吗？（y/n）\n");
		m = getche();
		if(m=='y' || m=='Y')
		{
			printf("\n请重新输入该学生的信息\n");
			printf("\n请输入学号：");
			scanf("%s",stu[i].num);
			printf("请输入姓名：");
			scanf("%s",stu[i].name);
			printf("请输入班级：");
			scanf("%d",&stu[i].class);
			printf("请输入学院：");
			scanf("%d",&stu[i].academy);
			printf("请输入省份：");
			scanf("%d",&stu[i].province);
			printf("请输入是否正常：");
			scanf("%d",&stu[i].ifnormal);
			printf("请输入时间：");
		    scanf("%d",&stu[i].datetime) ;	
			
		}
		
	 } 
}

//信息保存至文件中 
void save_txt()
{
	FILE * fp;
	char fname[20];
	int i;
	printf("请输入文件名（eg：.txt）:");
	scanf("%s",fname);
	if((fp=fopen(fname,"w"))==NULL)
	{
		printf("不能打开文件，文件保存失败！\n");
		return;
	}
	for(i=0; i<stu_num; i++)
		fprintf(fp, "%s %s %s %s %s %s %s %d %5.2f\n",stu[i].num, stu[i].name,
		stu[i].class, stu[i].academy, stu[i].province, stu[i].ifnormal, stu[i].datetime);
	printf("文件保存成功！\n");
	fclose(fp); 
 }
 
//按学号排序 
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
	printf("排序结果如下：\n");
	printf("名次\t学生学号\t姓名\班级\t学院\t省份\t是否正常\t时间\n");
	for(i=0; i<stu_num; i++)
		printf("%d\t%-16s%s\t%s\t%s\t%s\t%s\t%d\t%5.1f\n",i+1,stu[i].num,stu[i].name, stu[i].class, 
		stu[i].academy, stu[i].province, stu[i].ifnormal,stu[i].datetime); 
}
 

