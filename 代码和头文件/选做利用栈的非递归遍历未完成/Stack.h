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

void Init_Stack(stack *p);//初始化栈


Status Is_empty(stack *p);//判断是否为空栈 


Status Is_Full(stack *p);//判断栈是否为满栈


int GetLength(stack *p);//获取栈内元素个数


Status push(stack *p, ElemType value);//入栈


ElemType top(stack *p);//弹出栈顶元素


ElemType pop(stack *p);//出栈


void show_stack(stack *p);//展示栈内元素


#endif
