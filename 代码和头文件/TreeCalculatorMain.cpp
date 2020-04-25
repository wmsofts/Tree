#include "LinkBiTree.cpp"
#include <bits/stdc++.h>
using namespace std;

int main(){
	double Tree(BiTree T);
	printf("***利用二叉树求前缀表达式的值***\n");
	printf("输入在一行内给出不超过30个字符的前缀表达式，只包含+、-、*、/以及运算数，不同对象（运算数、运算符号）之间以空格分隔。\n");
	printf("例如：计算 2+3*(7-4)+8/4 \n");
	printf("输入以空格分隔：+ + 2 * 3 - 7 4 / 8 4\n");
	printf("输出保留两位小数：13.00\n");	
	BiTree T;
	printf("\n请输入："); 
	getline(cin,s);
    double sum = ValueTree(T);
    if(f==1)cout<<"错误：输入错误或计算异常。\n"<<endl;
    else printf("上式 = %.2lf\n",sum);
    getchar();

} 



