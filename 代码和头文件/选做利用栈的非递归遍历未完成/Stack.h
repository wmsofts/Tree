#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  char ElemType;
#define STACKSIZE 20

typedef struct Stack 
{
ElemType *Sdata;
int top;
int MaxSize;
}stack;

typedef enum Status {
    ERROR = 0, 
	SUCCESS = 1
} Status;

void Init_Stack(stack *p);//��ʼ��ջ


Status Is_empty(stack *p);//�ж��Ƿ�Ϊ��ջ 


Status Is_Full(stack *p);//�ж�ջ�Ƿ�Ϊ��ջ


int GetLength(stack *p);//��ȡջ��Ԫ�ظ���


Status push(stack *p, ElemType value);//��ջ


ElemType top(stack *p);//����ջ��Ԫ��


ElemType pop(stack *p);//��ջ


void show_stack(stack *p);//չʾջ��Ԫ��


#endif
