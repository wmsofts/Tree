#ifndef STREEADT_H_INCLUDED
#define STREEADT_H_INCLUDED

typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct BiTNode {
    TElemType  data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode, *BiTree;   // ��������

Status InitBiTree(BiTree *T);
Status CreateBiTree(BiTree *T);
Status visit(TElemType e);
void PerOrder ( BiTNode  *ptr );
void InOrder ( BiTNode  *ptr );
void PastOrder ( BiTNode  *ptr );

#endif 
