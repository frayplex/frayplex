//�˳���������B211��ӽ���д
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{	char num[20];char name[20];
	float chinese;float math;float english;	
	struct student *next;	
}stu[100];	//�ṹ���� 
int n=0;	//ȫ�ֱ������ø�����֪�������ж��ٸ�ѧ�� 
void write()//дѧ����Ϣ 
{	int i,j;	//�ҳ�֮Ϊѭ���ñ���
	int m;	//�����Ҫ��ӵ����� 
	printf("�������ѧ������:\n");
	scanf("%d",&m);
	if(n==0)	//һ��ʼӦ����û�˵� 
	{	for(i=0;i<n+m;i++)	//����i�ȵ���0 
label1:	{	printf("����ѧ��:\n");	//��һ����ǩ 
			scanf("%s",&stu[i].num);
			for(j=0;j<i;j++)
			{
				if(strcmp(stu[i].num,stu[j].num)==0)	//����ҵ���ͬ��ѧ�ž�ִ������ 
				{	printf("������������ͬ��ѧ��Ŷ\n");
					goto label1;	//��goto���ȥ����ǩ1 
				}
			}	
			printf("��������:\n"); 
			scanf("%s",&stu[i].name); 
			printf("���� ���� ��ѧ Ӣ�� �ɼ�(�м���ո�)\n");
			scanf("%f %f %f",&stu[i].chinese,&stu[i].math,&stu[i].english);
		}
	}
	if(n!=0)	//���������� 
	{
		for(i=n;i<n+m;i++)	//����i�������е����� 
label2:	{	printf("����ѧ��:\n"); 	//�ڶ�����ǩ 
			scanf("%s",&stu[i].num);	//����ͬ���� 
			for(j=0;j<i;j++)
			{
				if(strcmp(stu[i].num,stu[j].num)==0)
				{	printf("������������ͬ��ѧ��Ŷ\n");
					goto label2;
				}
			}	
			printf("��������:\n"); 
			scanf("%s",&stu[i].name); 
			printf("���� ���� ��ѧ Ӣ�� �ɼ�(�м���ո�)\n");
			scanf("%f %f %f",&stu[i].chinese,&stu[i].math,&stu[i].english);
		}
	}
	n+=m;//��ԭ�����������ӵ����� 
}
void load()	//��ͨ��ӡ������ 
{	if(n==0)
		printf("û��ѧ����Ϣร���������ѧ����Ϣ��\n");
	if(n>0)
	{	printf("���ڹ���%d��ѧ����\n",n);
		printf("ѧ��\t����\t����\t����\tӢ��\n");
		int i;
		for(i=0;i<n;i++)
			printf("%s\t%s\t%.2f\t%.2f\t%.2f\n",stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english);	 
	}
}
void search()
{	if(n==0)
		printf("û��ѧ����Ϣ����������ѧ����Ϣ��\n");
	else
	{	printf("������ѧ��:\n");
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
			printf("û�ҵ���\n");
		if(flag==1)
			printf("%s\t%s\t%.2f\t%.2f\t%.2f\n",stu[j].num,stu[j].name,stu[j].chinese,stu[j].math,stu[j].english);
	}	
}
void change()
{	if(n==0)
		printf("û��ѧ����Ϣ����������ѧ����Ϣ��\n");
	if(n>0)
	{	printf("������ѧ��:\n");
		char num2[20];	//��Ҫ�޸���Ϣ��ѧ����ѧ�� 
		int i,tem;	// tem��һ���ݴ��������ڴ�Ŀ��ѧ���������±� 
		scanf("%s",num2);
		int flag=0;		// ��ǩ 
		for(i=0;i<n;i++)
		{
			if(strcmp(num2,stu[i].num)==0)	// �ӽṹ������ѧ��ѧ������ 
			{		
				flag=1;
				tem=i;
			}
		}
		if(flag==0)
			printf("����û�ҵ���\n");
		if(flag==1)
		{	printf("���ҵ�Ŷ��������һ����Ϣ��\n");
			printf("�������µ�ѧ��:\n");
			char num3[20];		//ѧ�Ÿ�ֵ��
			scanf("%s",num3);
			strcpy(stu[tem].num,num3);
			printf("����������:\n");
			char name1[20];		//������ֵ�� 
			scanf("%s",name1);
			strcpy(stu[tem].name,name1);
			printf("������ ���� ��ѧ Ӣ�� �ɼ�:\n");
			scanf("%f %f %f",&stu[tem].chinese,&stu[tem].math,&stu[tem].english);
			printf("������������\n");
			printf("%s\t%s\t%.2f\t%.2f\t%.2f\n",stu[tem].num,stu[tem].name,stu[tem].chinese,stu[tem].math,stu[tem].english);	//�������� 
		}
	}
}
void average()	//��ͨ��ƽ��ֵ�ĺ��� 
{
	if(n==0)
		printf("û��ѧ����Ϣร���������ѧ����Ϣ��\n");
	else if(n>0)
	{
		int i;
		for(i=0;i<n;i++)
			printf("ѧ��Ϊ\t%s\t��\t%s\tͬѧ����ƽ������:\t%.2f\n",stu[i].num,stu[i].name,(stu[i].chinese+stu[i].math+stu[i].english)/3.0);
	}
}
void print80()
{	int i;
	for(i=0;i<n;i++)
		if((stu[i].chinese+stu[i].math+stu[i].english)/3.0>80)
			printf("%s\t%s\t%.2f\t%.2f\t%.2f\tƽ����:%.2f\n",stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english,(stu[i].chinese+stu[i].math+stu[i].english)/3.0);

} 
void top()
{	if(n==0)
		printf("û��ѧ����Ϣร���������ѧ����Ϣ��\n");
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
			printf("ѧ��Ϊ\t%s\t��\t%s\tͬѧ��ƽ������:\t%.2f\n",stu[i].num,stu[i].name,array[i]);
	}
}
void main()
{
	int a;
	while(1)	
	{	printf("0.�˳�����\n");
		printf("1.¼������ѧ����Ϣ\n");
		printf("2.��ȡѧ����Ϣ\n");
		printf("3.����ѧ�Ų���ѧ����Ϣ\n");
		printf("4.����ѧ���޸�ѧ����Ϣ\n");
		printf("5.���ÿ��ͬѧ��ƽ����\n");
		printf("6.���ƽ���ִ���80�ֵ�ͬѧ\n");
		printf("7.��ƽ����������\n");
		printf("������������ѡ������ร���enter������һ��\n");
		scanf("%d",&a);
		switch(a)	//�ṩ��ѡ�� 
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
