#include "LinkBiTree.h"
#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

/* 用于构造二叉树 */
int index=1;
typedef char String[100]; /* 0号单元存放串的长度 */
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

TElemType Nil=' '; /* 字符型以空格符为空 */

Status visit(TElemType e){
printf("%c ",e);
return SUCCESS;
}

// 构造空二叉树T
Status InitBiTree(BiTree *T){
	*T=NULL;
	return SUCCESS;
} 

//摧毁二叉树T
Status DestroyBiTree(BiTree *T){
	if(*T){
		if((*T)->lchild) /* 有左孩子 */
		DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
		if((*T)->rchild) /* 有右孩子 */
		DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
		free(*T); /* 释放根结点 */
		*T=NULL; /* 空指针赋0 */
	}
	return SUCCESS;
}

//构造二叉树T
Status CreateBiTree(BiTree *T){
	TElemType ch;
//	scanf("%c",&ch);  不需要在此输入时 
	ch = str[index++];

	if(ch=='#')
		*T=NULL;
	else
	{
	*T=(BiTree)malloc(sizeof(BiTNode));
	if(!*T)
		return ERROR;
	(*T)->data=ch; /* 生成根结点 */
	CreateBiTree(&(*T)->lchild); /* 构造左子树 */
	CreateBiTree(&(*T)->rchild); /* 构造右子树 */
	}		
	return SUCCESS;
}

//前序递归遍历
Status PreOrderTraverse(BiTree T){
	if(T==NULL)
		return ERROR;
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
	return SUCCESS;
}

//中序 
Status InOrderTraverse(BiTree T){
	if(T==NULL)
		return ERROR;
	InOrderTraverse(T->lchild); /* 中序遍历左子树 */
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
		return SUCCESS;
}

//后序
Status PostOrderTraverse(BiTree T){
	if(T==NULL)
		return ERROR;
	PostOrderTraverse(T->lchild); /* 先后序遍历左子树 */
	PostOrderTraverse(T->rchild); /* 再后序遍历右子树 */
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	return SUCCESS;
}

//层序 
/*
1、创建一个指针数组，保存二叉树结构体指针，
2、保存二叉树根节点，再申请变量 in、out ，控制数组，在遍历过程中，始终能找到节点和该节点的前一个节点，
3、循环以上过程。
*/
Status LevelOrderTraverse(BiTree T) { 
    BiTree temp[100];   /*创建指针类型的指针数组*/
    int in = 0;
    int out = 0;
    temp[in++] = T;  /*先保存二叉树根节点 */
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

//前缀计算器
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
