#include "Stack.h"

void Init_Stack(stack *p){
	if (p == NULL)
		return;
	p->top = -1;
	p->MaxSize = STACKSIZE;
	p->Sdata = (ElemType *)malloc(sizeof(ElemType)*p->MaxSize);
	memset(p->Sdata, 0, sizeof(ElemType)*p->MaxSize);
}


Status Is_empty(stack *p){
	if (p->top = -1 || p == NULL)
		return SUCCESS;
	return ERROR;
}


Status Is_Full(stack *p){
	if (p->top + 1 == p->MaxSize || p == NULL)
		return SUCCESS;
	return ERROR;
}


int GetLength(stack *p){
	return p->top+1;
}


Status push(stack *p, ElemType value){
	Status res = ERROR;
	if (!Is_Full(p)){
		p->Sdata[++p->top] = value;
		res = SUCCESS;
	} 
	return res;
}

//出栈操作分为两步，是为了保证出栈精确
ElemType top(stack *p){
	if ( p != NULL )
	{
		return p->Sdata[p->top];
	}
}


ElemType pop(stack *p){
	if (p->top >= 0 && p != NULL)	
		p->top--;	
}


void show_stack(stack *p){
	int count = p->top;
	while (count != -1){
		printf("%c ", p->Sdata[count]);
		count--;
	}
}
