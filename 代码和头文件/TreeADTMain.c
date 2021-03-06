#include "LinkBiTree.c"

int main(){
	int i;
	BiTree T;
	InitBiTree(&T);			//构造空二叉树T 
	printf("***构造空二叉树完成***\n"); 
	
	char string[100];
	printf("请输入构造二叉树，确保您的输入正确。\n") ;
	printf("例1 ：ABD##E##C##\n"); 
	printf("例2 ：ABDH#K###E##CFI###G#J## \n") ;
	printf("\n输入："); 
	scanf("%s",&string);
	StrAssign(str,&string);
	CreateBiTree(&T);			//构造二叉树T 
	printf("***构造二叉树完成***\n");
	
	printf("\n***开始递归遍历***");
	printf("\n前序遍历二叉树：");	
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树：");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树：");
	PostOrderTraverse(T);
	printf("\n层次遍历二叉树：");
	LevelOrderTraverse(T); 
	
	printf("\n\n***测试结束***\n"); 
	getch();
	return 0;
	}
