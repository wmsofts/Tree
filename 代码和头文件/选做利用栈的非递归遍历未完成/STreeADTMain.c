#include "STreeADT.c"

int main(){
	int i;
	BiTree T;
	InitBiTree(&T);			//����ն�����T 
	printf("***�ǵݹ�    �ǵݹ�***\n"); 
	printf("***����ն��������***\n"); 
	
	char string[100];
	printf("�����빹���������ȷ������������ȷ��\n") ;
	printf("��1 ��ABD##E##C##\n"); 
	printf("��2 ��ABDH#K###E##CFI###G#J## \n") ;
	printf("\n���룺"); 
	scanf("%s",&string);
	StrAssign(str,&string);
	CreateBiTree(&T);			//���������T 
	printf("***������������***\n");
	
	printf("\n***��ʼ����ջ�ķǵݹ����***");
	printf("\nǰ�������������");	
	PastOrder(T);	
	printf("\n���������������");
	InOrder(T);
	printf("\n���������������");
	PerOrder(T);
	
	printf("\n\n***���Խ���***\n"); 
	getch();
	return 0;
	}
