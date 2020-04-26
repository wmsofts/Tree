#include "Stack.c"
#include "Stack.h"
#include "STreeADT.h"
#define MAXSIZE 100
//前序 
void PerOrder ( BiTNode  *ptr ){
	if ( ptr == NULL )  return ;
	stack st ;
	Init_Stack ( &st ) ;
	while ( ptr !=NULL || ! Is_empty ( &st ) ){ 
		if ( ptr ){
			push ( &st , ptr ) ;
			ptr = top ( &st ) ;
			pop ( &st ) ;
			printf ( "%c " , ptr -> data ) ;
			push ( &st , ptr -> rchild ) ;
			ptr = ptr -> lchild ;
			}
			else{
			ptr = top ( &st ) ;   pop ( &st ) ;
			}
	}
}

//中序 
void InOrder ( BiTNode  *ptr ){
	if ( NULL == ptr )   return ;
	stack  st;
	Init_Stack ( &st ) ;
	while ( ptr !=NULL || ! Is_empty ( &st ) ){
		while ( ptr !=NULL ){
			push ( & st , ptr -> data ) ;
			ptr = ptr -> lchild ;
			}
		ptr = top ( &st ) ;    pop( &st ) ;  // 遇到空直接出栈 
		printf ( " %c ", ptr -> data ) ;  
		ptr = ptr -> rchild ;
	}
}

//后序 
void PastOrder ( BiTNode  *ptr ){
	if ( NULL == ptr )   return ;
	stack  st;
	Init_Stack ( &st ) ;
	BiTNode  *tag=NULL;
	while ( ptr !=NULL || ! Is_empty ( &st ) ){
		while ( ptr !=NULL ){
			push ( & st , ptr -> data ) ;
			ptr = ptr -> lchild ;
		}
		ptr = top ( &st ) ;    
		pop( &st ) ;  // 遇到空直接出栈 
		if ( ptr -> rchild == NULL || ptr -> rchild == tag ){
			printf ( "%c", ptr -> data ) ;
			tag = ptr ;
			ptr = NULL ;
		}
		else{
			push ( &st, ptr ) ;
			ptr = ptr -> rchild ;
			}
		}
}

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

