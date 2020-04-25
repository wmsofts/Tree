#include "LinkBiTree.h"
#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

/* ���ڹ�������� */
int index=1;
typedef char String[100]; /* 0�ŵ�Ԫ��Ŵ��ĳ��� */
String str;

Status StrAssign(String T,char *chars){
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
	T[0]=strlen(chars);
	for(i=1;i<=T[0];i++)
		T[i]=*(chars+i-1);
	return SUCCESS;
	}
}

TElemType Nil=' '; /* �ַ����Կո��Ϊ�� */

Status visit(TElemType e){
printf("%c ",e);
return SUCCESS;
}

// ����ն�����T
Status InitBiTree(BiTree *T){
	*T=NULL;
	return SUCCESS;
} 

//�ݻٶ�����T
Status DestroyBiTree(BiTree *T){
	if(*T){
		if((*T)->lchild) /* ������ */
		DestroyBiTree(&(*T)->lchild); /* ������������ */
		if((*T)->rchild) /* ���Һ��� */
		DestroyBiTree(&(*T)->rchild); /* �����Һ������� */
		free(*T); /* �ͷŸ���� */
		*T=NULL; /* ��ָ�븳0 */
	}
	return SUCCESS;
}

//���������T
Status CreateBiTree(BiTree *T){
	TElemType ch;
//	scanf("%c",&ch);  ����Ҫ�ڴ�����ʱ 
	ch = str[index++];

	if(ch=='#')
		*T=NULL;
	else
	{
	*T=(BiTree)malloc(sizeof(BiTNode));
	if(!*T)
		return ERROR;
	(*T)->data=ch; /* ���ɸ���� */
	CreateBiTree(&(*T)->lchild); /* ���������� */
	CreateBiTree(&(*T)->rchild); /* ���������� */
	}		
	return SUCCESS;
}

//ǰ��ݹ����
Status PreOrderTraverse(BiTree T){
	if(T==NULL)
		return ERROR;
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	PreOrderTraverse(T->lchild); /* ��������������� */
	PreOrderTraverse(T->rchild); /* ���������������� */
	return SUCCESS;
}

//���� 
Status InOrderTraverse(BiTree T){
	if(T==NULL)
		return ERROR;
	InOrderTraverse(T->lchild); /* ������������� */
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	InOrderTraverse(T->rchild); /* ���������������� */
		return SUCCESS;
}

//����
Status PostOrderTraverse(BiTree T){
	if(T==NULL)
		return ERROR;
	PostOrderTraverse(T->lchild); /* �Ⱥ������������ */
	PostOrderTraverse(T->rchild); /* �ٺ������������ */
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	return SUCCESS;
}

//���� 
/*
1������һ��ָ�����飬����������ṹ��ָ�룬
2��������������ڵ㣬��������� in��out ���������飬�ڱ��������У�ʼ�����ҵ��ڵ�͸ýڵ��ǰһ���ڵ㣬
3��ѭ�����Ϲ��̡�
*/
Status LevelOrderTraverse(BiTree T) { 
    BiTree temp[100];   /*����ָ�����͵�ָ������*/
    int in = 0;
    int out = 0;
    temp[in++] = T;  /*�ȱ�����������ڵ� */
    while (in > out)
    {
        if (temp[out])
        {
            printf("%c",temp[out]->data);
            temp[in++] = temp[out]->lchild;
            temp[in++] = temp[out]->rchild;
        }
        out++;
    }
    return SUCCESS; 
}

//ǰ׺������
	int f=0,k=0;
	string s; 
double ValueTree(BiTree T){
    T=(BiTree)malloc(sizeof(BiTree));
    char c;
    if(k>=s.length()){
        f=1;
        return 0;
    }
    c=s[k++];
    if(c-'0'>=0&&c-'0'<=9){
        double sum;
        sum=c-'0';
        int isdecimals=0,cnt=10;
        while(1){
            c=s[k++];
            if(c=='.'){
                isdecimals=1;
                continue;
            }
            if(c<'0')break;
            if(!isdecimals)sum=sum*10+c-'0';
            else {
                sum=sum+(c-'0')*1.0/cnt;
                cnt*=10;
            }
        }
        return sum;
    }
    else if(c<'0'&&s[k]-'0'>=0&&s[k]-'0'<=9){
        double sum=0;
        char q=c;
        int isdecimals=0,cnt=10;
        while(1){
            c=s[k++];
            if(c=='.'){
                isdecimals=1;
                continue;
            }
            if(c<'0')break;
            if(!isdecimals)sum=sum*10+c-'0';
            else {
                sum=sum+(c-'0')*1.0/cnt;
                cnt*=10;
            }
        }
        if(q=='-')return -sum;
        else return sum;
    }
    k++;
    double a=ValueTree(T->lchild);
    double b=ValueTree(T->rchild);
    if(c=='+'){
        T->data=a+b;
    }
    else if(c=='-'){
        T->data=a-b;
    }
    else if(c=='*'){
        T->data=a*b;
    }
    else if(c=='/'){
        if(b==0){
            f=1;
            return 0;
        }
        T->data=a/b;
    }
    return T->data;
    
}
