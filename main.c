#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct EmployeeInformation //Ա�������� 
{
int wage; //���� 
char name[12]; //���� 
char gender[4]; //�Ա� 
char department[12]; //���� 
char position[12]; //ְλ 
char number[8]; //ְ���� 
}em[100];

struct string //ְλ������ 
{
	char str[10]; //ְλ 
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
			printf("��ѡ������Ҫ�����Ĳ���(1--6):\n");
			scanf("%d",&n);
			if(n>=1&&n<=6)
			{
				flag=1;
				break;
			}
			else
			{
				flag=0;
				printf("�����������밴���������!");
				getch() ;
				system("cls");
			}
		}while(flag==0);
			
		switch(n)
		{
			case 1:
			printf(" ����ְ����Ϣ\n");
			printf("\n");
			system("cls");
			input();
			break;
			case 2:
			printf(" ���ְ����Ϣ\n");
			printf("\n");
			system("cls");
			display();
			break;
			case 3:
			printf(" ��ְ������ѯְ����Ϣ\n");
			printf("\n");
			system("cls");
			search();
			break; 
			case 4:
			printf(" ɾ��ְ����Ϣ\n");
			printf("\n");
			system("cls");
			del();
			break;
			case 5:
			printf(" �޸�ְ����Ϣ\n");
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
		printf("\n\n====================ллʹ�ã�====================\n\n");
		printf("\n==============���ߣ����1803 ����ϼ===============\n\n");
		printf("��������Ƴ�...\n"); 
		getch();
	

}

void menu() //�˵�
{
	printf("\n");
	printf("\t\t\t\t ==================ְ����Ϣ����==================\n");
	printf("\t\t\t\t *\t\t"); 
	printf(" 1.¼��ְ����Ϣ");
	printf("\t\t\t*\n");
	printf("\t\t\t\t *\t\t");
	printf(" 2.���ְ����Ϣ");
	printf("\t\t\t*\n");
	printf("\t\t\t\t *\t\t");
	printf(" 3.��ѯְ����Ϣ");
	printf("\t\t\t*\n");
	printf("\t\t\t\t *\t\t");
	printf(" 4.ɾ��ְ����Ϣ");
	printf("\t\t\t*\n");
	printf("\t\t\t\t *\t\t");
	printf(" 5.�޸�ְ����Ϣ");
	printf("\t\t\t*\n");
	printf("\t\t\t\t *\t\t");
	printf(" 6.��        ��");
	printf("\t\t\t*\n");
	printf("\t\t\t\t ====================��ӭʹ��====================\n");
	printf("\n");
	printf("\n");
}

void input() //¼��ְ����Ϣ
{
	int i,m,k=0;
	char s;
	char st[10]="";
	printf("��������Ҫ������Ϣ��ְ������(1--100):\n");
	scanf("%d",&m);
	system("cls");
	for(i=0;i<m;i++)
	{
		printf("������ְ���ţ� ");
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
		printf("����������: ");
		scanf("%s",em[i].name);
		getchar();
		printf("�������Ա� ");
		scanf("%s",&em[i].gender);
		getchar();
		printf("�����벿��: ");
		scanf("%s",&em[i].department);
		getchar();
		printf("������ְλ: ");
		scanf("%s",&em[i].position);
		printf("�������������: ");
		scanf("%d",&em[i].wage);
		
		printf("\n");
	
	}
	printf("\n�������!\n");
	system("cls");
	save(m,0);
}

void save(int m,int f) //��������  f: 0���������ļ� 1 �������ļ� 
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
		printf("�޷����ļ�\n");
		printf("�����������...\n"); 
		getch();
		exit(0);
	}
	for (i=0;i<m;i++)
	if (fwrite(&em[i],sizeof(struct EmployeeInformation),1,fp)!=1)
	printf("file write error\n");
	fclose(fp);
}

int read() //��ȡ���� 
{
	FILE *fp;
	int i=0;
	fp=fopen("employee_db","rb");
	if(fp==NULL)
	{
		printf ("�޷����ļ�\n");
		printf("�����������...\n"); 
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

void display() //������� 
{
	int i,t;
	int m=read();
	
	printf("��ѡ�����������ʽ����������� 1 ����������� 2 ; ��������� 3 \n");
	do
	{
		scanf("%d",&t);
		system("cls");
		if(t<1 && t> 3)
		{
			printf("ѡ�����������\n");
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
	
	printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %s\t\t \n","ְ����","�� ��","�� ��","�� ��","ְ λ","��������");
	for(i=0;i<m;i++)
	{ 
		printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %d\n",em[i].number,em[i].name,em[i].gender,em[i].department,em[i].position,em[i].wage); 
		
	} 
	printf("�����������\n");
	getch();
	system("cls");
}

void del() //ɾ������ 
{

	int m=read();
	int i,j,n,t,flag;
	char number[8];
	printf("\n ԭ����ְ����Ϣ:\n");
	display(); 
	printf("\n");
	printf("������Ҫɾ����ְ����ְ����:\n");
	scanf("%s",number);
	for(flag=1,i=0;flag&&i<m;i++)
	{
		if(strcmp(em[i].number,number)==0)
		{
			printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %s\t\t \n","ְ����","�� ��","�� ��","�� ��","ְ λ","��������");
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %d\n",em[i].number,em[i].name,em[i].gender,em[i].department,em[i].position,em[i].wage); 
			printf("\nȷʵҪɾ��������Ϣ�밴1,��ɾ���밴0\n");
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
	
		printf("\n�Բ��𣬲��޴���!\n");
	} 
	printf("\n ���ɾ���������ְ����Ϣ:\n");
	save(m,1); 
	display(); 
	printf("\n����ɾ���밴1���Ƴ��밴0\n");
	scanf("%d",&t);
	switch(t)
	{
		case 1:del();break;
		case 0:break;
		default :break;
	}
	system("cls");
}

void search() //��ѯ���� 
{
	char number[8];
	int i,t,flag=0;
	int m=read();
	printf("������Ҫ���ҵ�ְ����:\n");
	scanf("%s",number);
	system("cls");
	for(i=0;i<m;i++)
	{
	
		if(strcmp(number,em[i].number)==0)
		{
			flag=1;
					
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %s\t\t \n","ְ����","�� ��","�� ��","�� ��","ְ λ","��������");
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %d\n",em[i].number,em[i].name,em[i].gender,em[i].department,em[i].position,em[i].wage);
			//break;
		} 
	}
	if(flag==0) 
	{
		printf("\n�Բ��𣬲��޴���\n");
	}
	printf("\n");
	printf("����ѡ���ѯ�밴1,�˳��밲0\n");
	scanf("%d",&t);
	system("cls");
	switch(t)
	{ 
		case 1:search();break;
		case 0: break;
		default:break;
	}
}
	

void modify() //�޸����� 
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
	printf("\n ԭְ����Ϣ:\n");
	display();
	printf("\n");
	printf("������Ҫ�޸ĵ�ְ����ְ����:\n");
	scanf("%s",number);
	getchar();
	for(flag=1,i=0;flag&&i<m;i++)
	{
		if(strcmp(em[i].number,number)==0)
		{
			printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %s\t\t \n","ְ����","�� ��","�� ��","�� ��","ְ λ","��������");
			printf("\n % -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %d\n",em[i].number,em[i].name,em[i].gender,em[i].department,em[i].position,em[i].wage);
			printf("\nȷʵҪ�޸Ĵ�����Ϣ�밴1 ; ���޸��밴0\n");
			scanf("%d",&n);
			if(n==1)
			{
				do
				{
					
					printf("\n��Ҫ�����޸ĵ�ѡ��\n 1.ְ���� 2.���� 3.�Ա� 4.���� 5.ְλ 6.��������\n"); 
					printf("�����������޸ĵ���һ�����:\n"); 
					scanf("%d",&c); 
					if(c>6||c<1)
					{ 
						printf("\nѡ������밴���������ѡ��!\n"); 
						system("cls") ;
					} 
				}while(c>6||c<1);
				
			}
			flag=0;
		
		}
	
	}
	
	if(flag==1)
	{ 
		printf("\n�Բ��𣬲��޴���!\n"); 
	} 
	else
	{
		do 
		{
			switch(c) 
			{ 
				case 1:printf("ְ���Ÿ�Ϊ: ");
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
				case 2:printf("������Ϊ: ");
				scanf("%s",&name);
				strcpy(em[i-1].name,name); 
				break; 
				case 3:printf("�Ա��Ϊ: ");
				getchar();
				scanf("%s",&gender);
				strcpy(em[i-1].gender,gender);
				break; 
				case 4:printf("���Ÿ�Ϊ: ");
				scanf("%s",&department);
				strcpy(em[i-1].department,department);
				break; 
				case 5:printf("ְλ��Ϊ: ");
				scanf("%s",&position); 
				strcpy(em[i-1].position,position); 
				break; 
				case 6:printf("�������ʸ�Ϊ: ");
				scanf("%d",&wage);
				em[i-1].wage=wage; 
				break; 
				
			} 
			printf("\n");
			printf("\n�Ƿ�ȷ�����޸ĵ���Ϣ?\n �� �밴1 ; ��,�����޸� �밴0: \n"); 
			scanf("%d",&b);
		
		}while(b==0);
	}
	printf("\n����޸ĺ������ְ����Ϣ:\n");
	printf("\n");
	save(m,1);
	display();
	printf("\n�����޸��밴1�������޸��밴0\n");
	scanf("%d",&t);
	switch(t)
	{
		case 1:modify();break;
		case 0:break;
		default :break;
	}
	system("cls");

}

void array() //�������� 
{
	int t;
	int m=read();
	printf("��ѡ����������ʽ�������밴 1 �������밴 2 \n");
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

int cmp_u(const void *a,const void *b) //������� 
{
	
	return *(int *)a-*(int *)b; //���� 
	
}

int cmp_d(const void *a,const void *b) //������� 
{
	
	
	return *(int *)b-*(int *)a; //���� 
}


void sort() //���ݷ��� 
{
	int m=read();
	char s[10]; 
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
		printf("ְλ��%s\n",posi[i].str);
		printf("\n \t% -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %s\t\t \n","ְ����","�� ��","�� ��","�� ��","ְ λ","��������");
			
		for(h=0;h<c[i];h++)
		{
			printf("\n \t% -6s\t\t % -8s\t\t % -2s\t\t % -8s\t\t % -8s\t\t %d\n",em[i].number,em[i].name,em[i].gender,em[i].department,em[i].position,em[i].wage);
			k++;
		}
	}
	printf("�����������\n");
	getch();
	system("cls");
}

int cmp(const void *a,const void *b) //ְλ������� 
{
	
	return strcmp( (*(struct EmployeeInformation *)a).position , (*(struct EmployeeInformation *)b).position ); 
	
}

