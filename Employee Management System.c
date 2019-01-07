#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct EmployeeInformation //员工数据类 
{
int wage; //工资 
char name[12]; //姓名 
char gender[4]; //性别 
char department[12]; //部门 
char position[12]; //职位 
char number[8]; //职工号 
}em[100];

struct string //职位数据类 
{
	char str[10]; //职位 
}posi[10];

void menu();
void input();
void save(int m,int f);
void display();
void del();
void search();
void modify();
int cmp_u(const void *a,const void *b);
int cmp_d(const void *a,const void *b);
int cmp(const void *a,const void *b);
void array();
void sort();


void main(void) 
{
	int n,flag;
	while(1)
	{
	 
		do
		{
			menu();
			printf("请选择您需要操作的步骤(1--6):\n");
			scanf("%d",&n);
			if(n>=1&&n<=6)
			{
				flag=1;
				break;
			}
			else
			{
				flag=0;
				printf("您输入有误，请按任意键重试!");
				getch() ;
				system("cls");
			}
		}while(flag==0);
			
		switch(n)
		{
			case 1:
			printf(" 输入职工信息\n");
			printf("\n");
			system("cls");
			input();
			break;
			case 2:
			printf(" 浏览职工信息\n");
			printf("\n");
			system("cls");
			display();
			break;
			case 3:
			printf(" 按职姓名查询职工信息\n");
			printf("\n");
			system("cls");
			search();
			break; 
			case 4:
			printf(" 删除职工信息\n");
			printf("\n");
			system("cls");
			del();
			break;
			case 5:
			printf(" 修改职工信息\n");
			printf("\n");
			system("cls");
			modify();
			break;
			case 6:
			goto la;
			default :break;
		}
	
	}
	
	la:
		system("cls"); 
		printf("\n\n====================谢谢使用！====================\n\n");
		printf("\n==============作者：软件(三)班 郭晋儒===============\n\n");
		printf("按任意键推出...\n"); 
		getch();
	

}

void menu() //菜单
{
	printf("\n");
	printf("\t\t\t\t ==================职工信息管理==================\n");
	printf("\t\t\t\t *\t\t"); 
	printf(" 1.录入职工信息");
	printf("\t\t\t*\n");
	printf("\t\t\t\t *\t\t");
	printf(" 2.浏览职工信息");
	printf("\t\t\t*\n");
	printf("\t\t\t\t *\t\t");
	printf(" 3.查询职工信息");
	printf("\t\t\t*\n");
	printf("\t\t\t\t *\t\t");
	printf(" 4.删除职工信息");
	printf("\t\t\t*\n");
	printf("\t\t\t\t *\t\t");
	printf(" 5.修改职工信息");
	printf("\t\t\t*\n");
	printf("\t\t\t\t *\t\t");
	printf(" 6.退        出");
	printf("\t\t\t*\n");
	printf("\t\t\t\t ====================欢迎使用====================\n");
	printf("\n");
	printf("\n");
}

void input() //录入职工信息
{
	int i,m,k=0;
	char s;
	char st[10]="";
	printf("请输入需要创建信息的职工人数(1--100):\n");
	scanf("%d",&m);
	system("cls");
	for(i=0;i<m;i++)
	{
		k=0;
		st[0]='\0';
		printf("请输入职工号： ");
		
		do
		{
		
			s=getch();

			if(s>47 && s<58)
			{
				printf("%c",s);
				st[k]=s;
				k++;
			}
			else if(s==13 && s==0)
			{
				continue;
			}
			else if(s==13)
			{
				break;
			}
			else
			{
				continue;
			}
			
			
		}while(k<6);
		strcpy(em[i].number,st);
		
		printf("\n");
		printf("请输入姓名: ");
		scanf("%s",em[i].name);
		getchar();
		printf("请输入性别： ");
		scanf("%s",&em[i].gender);
		getchar();
		printf("请输入部门: ");
		scanf("%s",&em[i].department);
		getchar();
		printf("请输入职位: ");
		scanf("%s",&em[i].position);
		printf("请输入基本工资: ");
		scanf("%d",&em[i].wage);
		
		printf("\n");
	
	}
	printf("\n创建完毕!\n");
	system("cls");
	save(m,0);
}

void save(int m,int f) //保存数据  f: 0代表已有文件 1 代表无文件 
{
	int i;
	FILE *fp;
	if(f==1)
	{
		fp=fopen("employee_db","wb");
	}
	else
	{
		fp=fopen("employee_db","ab");
	}

	if (fp==NULL) 
	{
		printf("无法打开文件\n");
		printf("按任意键继续...\n"); 
		getch();
		exit(0);
	}
	for (i=0;i<m;i++)
	if (fwrite(&em[i],sizeof(struct EmployeeInformation),1,fp)!=1)
	printf("file write error\n");
	fclose(fp);
}

int read() //读取数据 
{
	FILE *fp;
	int i=0;
	fp=fopen("employee_db","rb");
	if(fp==NULL)
	{
		printf ("无法打开文件\n");
		printf("按任意键继续...\n"); 
		getch();
		exit(0);
	}
	else 
	{
		do 
		{
			fread(&em[i],sizeof(struct EmployeeInformation),1,fp);
			i++;
		}
		while(feof(fp)==0);
	}
	fclose(fp);
	return(i-1);
}

void display() //浏览数据 
{
	int i,t;
	int m=read();
	
	printf("请选择您的浏览方式：正常浏览按 1 ；排序浏览按 2 ; 分类浏览按 3 \n");
	do
	{
		scanf("%d",&t);
		system("cls");
		if(t<1 && t> 3)
		{
			printf("选择错误，请重试\n");
			system("cls");
			
		}
		else if(t==1)
		{
			break;
		}
		else if(t==2)
		{
			array();
			break;
		}
		else if(t==3)
		{
			sort();
			return;
		}
		
		 
	}while(1);
	
	printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %s\t\t \n","职工号","姓 名","性 别","部 门","职 位","基本工资");
	for(i=0;i<m;i++)
	{ 
		printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %d\n",em[i].number,em[i].name,em[i].gender,em[i].department,em[i].position,em[i].wage); 
		
	} 
	printf("按任意键继续\n");
	getch();
	system("cls");
}

void del() //删除数据 
{

	int m=read();
	int i,j,n,t,flag;
	char number[8];
	printf("\n 原来的职工信息:\n");
	display(); 
	printf("\n");
	printf("请输入要删除的职工的职工号:\n");
	scanf("%s",number);
	for(flag=1,i=0;flag&&i<m;i++)
	{
		if(strcmp(em[i].number,number)==0)
		{
			printf("\n已找到此人，原始记录为：\n");
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %s\t\t \n","职工号","姓 名","性 别","部 门","职 位","基本工资");
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %d\n",em[i].number,em[i].name,em[i].gender,em[i].department,em[i].position,em[i].wage); 
			printf("\n确实要删除此人信息请按1,不删除请按0\n");
			scanf("%d",&n);
			if(n==1) 
			{
				for(j=i;j<m-1;j++)
				{
					em[j]=em[j+1];
				
				}
				flag=0;
			}
		}
	}
	if(!flag)
	{
		m=m-1;
	}
	else
	{
	
		printf("\n对不起，查无此人!\n");
	}
	if(flag==0)
	{
		printf("\n 浏览删除后的所有职工信息:\n");
		save(m,1); 
		display(); 
	} 
	
	printf("\n继续删除请按1，退出请按0\n");
	scanf("%d",&t);
	switch(t)
	{
		case 1:del();break;
		case 0:break;
		default :break;
	}
	system("cls");
}

void search() //查询数据 
{
	char name[8];
	int i,t,flag=0;
	int m=read();
	printf("请输入要查找的姓名:\n");
	scanf("%s",name);
	system("cls");
	for(i=0;i<m;i++)
	{
	
		if(strcmp(name,em[i].name)==0)
		{
			flag=1;
					
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %s\t\t \n","职工号","姓 名","性 别","部 门","职 位","基本工资");
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %d\n",em[i].number,em[i].name,em[i].gender,em[i].department,em[i].position,em[i].wage);
			//break;
		} 
	}
	if(flag==0) 
	{
		printf("\n对不起，查无此人\n");
	}
	printf("\n");
	printf("重新选择查询请按1,退出请安0\n");
	scanf("%d",&t);
	system("cls");
	switch(t)
	{ 
		case 1:search();break;
		case 0: break;
		default:break;
	}
}
	

void modify() //修改数据 
{
	char number[8]; 
	char name[10];
	char gender[4];
	char department[10];
	char position[10];
	int wage;
	int b,c,i,n,t,flag,k=0; 
	int m=read(); 
	char s;
	char st[10];
	printf("\n 原职工信息:\n");
	display();
	printf("\n");
	printf("请输入要修改的职工的职工号:\n");
	scanf("%s",number);
	getchar();
	for(flag=1,i=0;flag&&i<m;i++)
	{
		if(strcmp(em[i].number,number)==0)
		{
			printf("\n已找到此人，原始记录为：\n");
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %s\t\t \n","职工号","姓 名","性 别","部 门","职 位","基本工资");
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %d\n",em[i].number,em[i].name,em[i].gender,em[i].department,em[i].position,em[i].wage);
			printf("\n确实要修改此人信息请按1 ; 不修改请按0\n");
			scanf("%d",&n);
			if(n==1)
			{
				do
				{
					
					printf("\n需要进行修改的选项\n 1.职工号 2.姓名 3.性别 4.部门 5.职位 6.基本工资\n"); 
					printf("请输入你想修改的那一项序号:\n"); 
					scanf("%d",&c); 
					if(c>6||c<1)
					{ 
						printf("\n选择错误，请按任意键重新选择!\n"); 
						system("cls") ;
					} 
				}while(c>6||c<1);
				
			}
			flag=0;
		
		}
	
	}
	
	if(flag==1)
	{ 
		printf("\n对不起，查无此人!\n"); 
	} 
	else
	{
		do 
		{
			switch(c) 
			{ 
				case 1:printf("职工号改为: ");
				do
				{
				
					s=getch();
		
					if(s>47 && s<58)
					{
						printf("%c",s);
						st[k]=s;
						k++;
					}
					else if(s==13 && s==0)
					{
						continue;
					}
					else if(s==13)
					{
						break;
					}
					else
					{
						continue;
					}
					
					
				}while(k<8);
				strcpy(em[i-1].number,st);
				
				break; 
				case 2:printf("姓名改为: ");
				scanf("%s",&name);
				strcpy(em[i-1].name,name); 
				break; 
				case 3:printf("性别改为: ");
				getchar();
				scanf("%s",&gender);
				strcpy(em[i-1].gender,gender);
				break; 
				case 4:printf("部门改为: ");
				scanf("%s",&department);
				strcpy(em[i-1].department,department);
				break; 
				case 5:printf("职位改为: ");
				scanf("%s",&position); 
				strcpy(em[i-1].position,position); 
				break; 
				case 6:printf("基本工资改为: ");
				scanf("%d",&wage);
				em[i-1].wage=wage; 
				break; 
				
			} 
			printf("\n");
			printf("\n是否确定所修改的信息?\n 是 请按1 ; 不,重新输入 请按0: \n"); 
			scanf("%d",&b);
		
		}while(b==0);
	}
	printf("\n浏览修改后的所有职工信息:\n");
	printf("\n");
	save(m,1);
	display();
	printf("\n继续修改请按1，不再修改请按0\n");
	scanf("%d",&t);
	switch(t)
	{
		case 1:modify();break;
		case 0:break;
		default :break;
	}
	system("cls");

}

void array() //数据排序 
{
	int t;
	int m=read();
	printf("请选择您的排序方式：升序请按 1 ；降序请按 2 \n");
	scanf("%d",&t);
	if(t==1)
	{
		qsort(em,m,sizeof(struct EmployeeInformation),cmp_u);
	}
	else
	{
		qsort(em,m,sizeof(struct EmployeeInformation),cmp_d);
	}
		
}

int cmp_u(const void *a,const void *b) //升序规则 
{
	
	return *(int *)a-*(int *)b; //升序 
	
}

int cmp_d(const void *a,const void *b) //降序规则 
{
	
	
	return *(int *)b-*(int *)a; //降序 
}


void sort() //数据分类 
{
	int m=read();

	char tp[10];
	int i,j=0;
	int c[10]={0};
	int h,k=0;
	qsort(em,m,sizeof(struct EmployeeInformation),cmp);

	strcpy(tp,em[j].position);
	
	for(i=0;i<m;i++)
	{
		if(strcmp(em[i].position,tp)==0)
		{			
			strcpy(posi[j].str,tp); 
			c[j]+=1;
		}
		else
		{
			strcpy(tp,em[i].position);
			j++;
			i--;
		}
	}
	
	
	for(i=0;i<j+1;i++)
	{
		printf("职位：%s\n",posi[i].str);
		printf("\n \t% -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %s\t\t \n","职工号","姓 名","性 别","部 门","职 位","基本工资");
			
		for(h=0;h<c[i];h++)
		{
			printf("\n \t% -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %d\n",em[k].number,em[k].name,em[k].gender,em[k].department,em[k].position,em[k].wage);
			k++;
		}
	}
	printf("按任意键继续\n");
	getch();
	system("cls");
}

int cmp(const void *a,const void *b) //职位排序规则 
{
	printf( "%d",strcmp( (*(struct EmployeeInformation *)a).position , (*(struct EmployeeInformation *)b).position ));
	return strcmp( (*(struct EmployeeInformation *)a).position , (*(struct EmployeeInformation *)b).position ); 
	
}
