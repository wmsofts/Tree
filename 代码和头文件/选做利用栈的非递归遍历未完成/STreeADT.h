#ifndef STREEADT_H_INCLUDED
#define STREEADT_H_INCLUDED

typedef char TElemType;     // 假设二叉树结点的元素类型为字符

typedef struct BiTNode {
    TElemType  data;     // 数据域
    struct BiTNode  *lchild,*rchild;  // 左、右孩子指针
} BiTNode, *BiTree;   // 二叉链表

Status InitBiTree(BiTree *T);
Status CreateBiTree(BiTree *T);
Status visit(TElemType e);
void PerOrder ( BiTNode  *ptr );
void InOrder ( BiTNode  *ptr );
void PastOrder ( BiTNode  *ptr );

#endif 
