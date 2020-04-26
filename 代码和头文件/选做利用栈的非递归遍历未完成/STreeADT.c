#include "Stack.c"
#include "Stack.h"
#include "STreeADT.h"
#define MAXSIZE 100
//ǰ�� 
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

//���� 
void InOrder ( BiTNode  *ptr ){
	if ( NULL == ptr )   return ;
	stack  st;
	Init_Stack ( &st ) ;
	while ( ptr !=NULL || ! Is_empty ( &st ) ){
		while ( ptr !=NULL ){
			push ( & st , ptr -> data ) ;
			ptr = ptr -> lchild ;
			}
		ptr = top ( &st ) ;    pop( &st ) ;  // ������ֱ�ӳ�ջ 
		printf ( " %c ", ptr -> data ) ;  
		ptr = ptr -> rchild ;
	}
}

//���� 
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
		pop( &st ) ;  // ������ֱ�ӳ�ջ 
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

