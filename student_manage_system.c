//此程序由网安B211黄咏祥编写
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{	char num[20];char name[20];
	float chinese;float math;float english;	
	struct student *next;	
}stu[100];	//结构体来 
int n=0;	//全局变量来让各函数知道现在有多少个学生 
void write()//写学生信息 
{	int i,j;	//我称之为循环用变量
	int m;	//这个是要添加的人数 
	printf("输入添加学生数量:\n");
	scanf("%d",&m);
	if(n==0)	//一开始应该是没人的 
	{	for(i=0;i<n+m;i++)	//所以i先等于0 
label1:	{	printf("输入学号:\n");	//第一个标签 
			scanf("%s",&stu[i].num);
			for(j=0;j<i;j++)
			{
				if(strcmp(stu[i].num,stu[j].num)==0)	//如果找到相同的学号就执行下面 
				{	printf("不能有两个相同的学号哦\n");
					goto label1;	//用goto语句去到标签1 
				}
			}	
			printf("输入姓名:\n"); 
			scanf("%s",&stu[i].name); 
			printf("输入 语文 数学 英语 成绩(中间带空格)\n");
			scanf("%f %f %f",&stu[i].chinese,&stu[i].math,&stu[i].english);
		}
	}
	if(n!=0)	//有人了往下 
	{
		for(i=n;i<n+m;i++)	//就让i等于已有的人数 
label2:	{	printf("输入学号:\n"); 	//第二个标签 
			scanf("%s",&stu[i].num);	//下面同上啦 
			for(j=0;j<i;j++)
			{
				if(strcmp(stu[i].num,stu[j].num)==0)
				{	printf("不能有两个相同的学号哦\n");
					goto label2;
				}
			}	
			printf("输入姓名:\n"); 
			scanf("%s",&stu[i].name); 
			printf("输入 语文 数学 英语 成绩(中间带空格)\n");
			scanf("%f %f %f",&stu[i].chinese,&stu[i].math,&stu[i].english);
		}
	}
	n+=m;//让原人数加上增加的人数 
}
void load()	//普通打印就完事 
{	if(n==0)
		printf("没有学生信息喔，请先增加学生信息吧\n");
	if(n>0)
	{	printf("现在共有%d名学生：\n",n);
		printf("学号\t姓名\t语文\t高数\t英语\n");
		int i;
		for(i=0;i<n;i++)
			printf("%s\t%s\t%.2f\t%.2f\t%.2f\n",stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english);	 
	}
}
void search()
{	if(n==0)
		printf("没有学生信息，请先增加学生信息吧\n");
	else
	{	printf("请输入学号:\n");
		char num1[20];int i,j;
		scanf("%s",num1);
		int flag=0;
		for(i=0;i<n;i++)
		{	if(strcmp(num1,stu[i].num)==0)
			{	flag=1;
				j=i; 
			}
		}
		if(flag==0)
			printf("没找到啊\n");
		if(flag==1)
			printf("%s\t%s\t%.2f\t%.2f\t%.2f\n",stu[j].num,stu[j].name,stu[j].chinese,stu[j].math,stu[j].english);
	}	
}
void change()
{	if(n==0)
		printf("没有学生信息，请先增加学生信息吧\n");
	if(n>0)
	{	printf("请输入学号:\n");
		char num2[20];	//需要修改信息的学生的学号 
		int i,tem;	// tem是一个暂存器，用于存目标学生的数组下标 
		scanf("%s",num2);
		int flag=0;		// 标签 
		for(i=0;i<n;i++)
		{
			if(strcmp(num2,stu[i].num)==0)	// 从结构体里存的学生学号里找 
			{		
				flag=1;
				tem=i;
			}
		}
		if(flag==0)
			printf("还是没找到啊\n");
		if(flag==1)
		{	printf("能找到哦，重新输一下信息吧\n");
			printf("请输入新的学号:\n");
			char num3[20];		//学号赋值机
			scanf("%s",num3);
			strcpy(stu[tem].num,num3);
			printf("请输入姓名:\n");
			char name1[20];		//姓名赋值姬 
			scanf("%s",name1);
			strcpy(stu[tem].name,name1);
			printf("请输入 语文 数学 英语 成绩:\n");
			scanf("%f %f %f",&stu[tem].chinese,&stu[tem].math,&stu[tem].english);
			printf("好啦来看看吧\n");
			printf("%s\t%s\t%.2f\t%.2f\t%.2f\n",stu[tem].num,stu[tem].name,stu[tem].chinese,stu[tem].math,stu[tem].english);	//打出来检查 
		}
	}
}
void average()	//普通求平均值的函数 
{
	if(n==0)
		printf("没有学生信息喔，请先增加学生信息吧\n");
	else if(n>0)
	{
		int i;
		for(i=0;i<n;i++)
			printf("学号为\t%s\t的\t%s\t同学三科平均分是:\t%.2f\n",stu[i].num,stu[i].name,(stu[i].chinese+stu[i].math+stu[i].english)/3.0);
	}
}
void print80()
{	int i;
	for(i=0;i<n;i++)
		if((stu[i].chinese+stu[i].math+stu[i].english)/3.0>80)
			printf("%s\t%s\t%.2f\t%.2f\t%.2f\t平均分:%.2f\n",stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english,(stu[i].chinese+stu[i].math+stu[i].english)/3.0);

} 
void top()
{	if(n==0)
		printf("没有学生信息喔，请先增加学生信息吧\n");
	else if(n>0)
	{	int i,j;float array[100];
			for(i=0,j=0;i<n;i++,j++)
				array[i]=(stu[i].chinese+stu[i].math+stu[i].english)/3.0;
		for(i=0;i<n+1;i++)
		{	for(j=0;j<n-1-i;j++)
			{	if(array[j]<array[j+1])
				{	float temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
				}	 
			}
		}
		for(i=0;i<n;i++)
			printf("学号为\t%s\t的\t%s\t同学科平均分是:\t%.2f\n",stu[i].num,stu[i].name,array[i]);
	}
}
void main()
{
	int a;
	while(1)	
	{	printf("0.退出程序\n");
		printf("1.录入或添加学生信息\n");
		printf("2.读取学生信息\n");
		printf("3.输入学号查找学生信息\n");
		printf("4.输入学号修改学生信息\n");
		printf("5.输出每个同学的平均分\n");
		printf("6.输出平均分大于80分的同学\n");
		printf("7.按平均分来排名\n");
		printf("请输入数字来选择运行喔，按enter进入下一步\n");
		scanf("%d",&a);
		switch(a)	//提供的选项 
		{	case 0:exit(886);
			case 1:write();break;
			case 2:load();break;
			case 3:search();break;
			case 4:change();break;
			case 5:average();break;
			case 6:print80();break;
			case 7:top();break;
			
			default:printf("error,Re:in\n");
		}
	}
}
