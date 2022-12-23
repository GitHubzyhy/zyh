#include<stdio.h>
#include<malloc.h>
typedef struct Lnode
{
int a;//������ 
struct Lnode *next;//ָ���� 
}Lnode,*LinkList;//LinkList�൱��Lnode* 

Lnode* create1(LinkList L,int n)//ͷ�巨 
{
	Lnode *next=NULL;
L=(LinkList)malloc(sizeof(Lnode));
L->next=NULL;//�Ƚ���һ����ͷ�ڵ�Ŀ�����
int i;
for(i=0;i<n;i++)//ѭ��n�� 
{
	next=(Lnode *)malloc(sizeof(Lnode));
	if(!next){printf("�����ڴ����\n");exit(0);}
	printf("���������������ֵ\n");
	scanf("%d",&next->a);
	next->next=L->next;L->next=next;//�����ڲ��� (������ͷ�ڵ�֮�� 
}
return L; 
}

Lnode* create2(LinkList L,int n)//β���뷨 
{
	int i;
	Lnode *next=NULL,*current=NULL;
	L=(Lnode *)malloc(sizeof(Lnode));if(!L){printf("�����ڴ����\n");exit(0);}
	L->next=NULL;//�Ƚ���һ����ͷ�ڵ�Ŀ�����
		current=L;//βָ��ָ��ͷ�ڵ�
	for(i=0;i<n;i++)
	{
		next=(LinkList)malloc(sizeof(Lnode));
		printf("���������������ֵ\n");
		scanf("%d",&next->a);
		next->next=NULL;
		current->next=next;//�������� 
		current=next;//βָ���ƶ� 
	}
	return L;
}
void display(LinkList L)
{
	Lnode *p=L->next;//ָ�����Ԫ�ڵ� 
	while(p)//p��Ϊ�յ���������ѭ�� 
	{
		printf("a��ֵ:%d ",p->a);
		p=p->next;
	}
	putchar('\n');
}
//ȡֵ���� 
int GetElem(LinkList L,int i,int e)//��i��λ��ȡֵ
{
	Lnode *p=L->next;//ָ����Ԫ�ڵ�
	int j=1;
	while(p&&(j<i))//p��Ϊ�յ�������j<i����������ѭ��ֱ���ҵ��ĸ��ڵ� 
	{p=p->next;	++j;} 
	if(!p||(j>i)){printf("i���Ϸ�\n");return false;}
	e=p->a;//�Ѿ��ҵ����ĸ��ڵ�ֱ�Ӹ�ֵ 
	return e;
} 
//��ֵ���� 
Lnode* LocateElem(LinkList L,int e)//�ҵ��󷵻ص��ǵ�ַ
{
	Lnode *p=NULL;
	p=L->next;//ָ����Ԫ�ڵ�
	while(p&&p->a!=e)
	p=p->next;
	return p;//�ɹ����ص�ַ��ʧ�ܷ���NULL 
} 
bool  insert(LinkList &L,int i,int e)//��i��λ�ò���e��ֵ(��ǰ��) 
{
	Lnode *p=L;//ָ��ͷ�ڵ� 
	int j=0;
	while(p&&(j<i-1))//�ҵ���ǰ��
	{p=p->next;++j;}
	if(!p||j>i-1){printf("�����λ�ò�����\n");return false;}
	Lnode *s=(Lnode *)malloc(sizeof(Lnode));
	if(!s){printf("�ڴ����ʧ�ܣ�\n");exit(0);}
	s->a=e;
	s->next=p->next;
	p->next=s;
	return true;
}
bool Delete(LinkList &L,int i)//�ڵ�i��λ����ɾ��
{
	int j=0;
	Lnode *p=L,*temp=NULL;
	while((p->next)&&(j<i-1))//Ҳ���ҵ�ǰ��������ǰ�����������һ��
	{p=p->next;++j;}
	if(!(p->next)||(j>i-1)){printf("ɾ����λ�ò�����\n");return false;}
	temp=p->next;//tempָ�뱣����Ҫɾ��ָ���λ��
	p->next=temp->next;//�ı���ָ����
	free(temp);
	temp=NULL;
	return true; 
} 
void clear(LinkList &L)
{
	Lnode *p=NULL,*q=NULL;
	p=L->next;
	while(p)
	{
		q=p->next;
		free(p);//q��pɾ����ͷ�ڵ� 
		p=q;
	}
} 
void destory(LinkList &L)//���ٲ���
{
	Lnode *p=NULL;
	while(L)
	{
		p=L;
		L=L->next;
		 free(p);
	}
	L=NULL;
} 
int main()
{
	LinkList L=NULL,p=NULL;
	L=create1(L,4);
	display(L);
	printf("\n");
	clear(L);
	int e;
	L=create2(L,4);
	display(L);
e=GetElem(L,1,e); 
printf("���ҵ�һ��λ�õ�ֵ�ǣ�%d",e);
	p=LocateElem(L,1);
	if(!p){printf("����ʧ�ܣ�\n");}
	else printf("p->a:%d\n ",p->a);
	if(!insert(L,5,4)){printf("����ʧ�ܣ�\n");}
	display(L);
	if(!Delete(L,5)){printf("ɾ��ʧ�ܣ�\n");}
		display(L);
		destory(L);//�������� 
	
	return 0;
}
