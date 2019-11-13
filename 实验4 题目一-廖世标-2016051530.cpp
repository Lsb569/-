#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int TElemType;
typedef int Status;
typedef struct BiTNode{//定义树节点结构
  TElemType date;
  struct BiTNode *lChild, *rChild;
}BiTNode, *BiTree;
Status CreateBiTree(BiTree &T){//创建树
TElemType ch;
scanf("%d", &ch);
if (ch == -1)
T = NULL;
else
{
T = (BiTree)malloc(sizeof(BiTNode));
if (!(T))
exit(-1);
T->date = ch;
printf("输入%d的左子节点：", ch);
CreateBiTree(T->lChild);
printf("输入%d的右子节点：", ch);
CreateBiTree(T->rChild);
}
return 1;
}
Status exchange(BiTree &T){//交换子树方法
BiTree p;
p=T->lChild;
T->lChild=T->rChild;
T->rChild=p;
return 1;
}
Status PreOrderTraverse(BiTree &T,Status(&Visit)(BiTree &T)){//先序遍历树调用Visit()方法。
if (T == NULL)
return 0;
Visit(T);
PreOrderTraverse(T->lChild,Visit);
PreOrderTraverse(T->rChild,Visit);
return 1;
}
Status Print(BiTree &T){//输出节点值。
    printf("%d ",(*T).date);
    return 0;
}
int main(){
BiTree T;
printf("输入根节点值，输入-1表示空树或没有子叶\n");
CreateBiTree(T);
printf("先序遍历输出:");
PreOrderTraverse(T,Print);
printf("\n交换子树后先序遍历输出\n");
PreOrderTraverse(T,exchange);
PreOrderTraverse(T,Print);
printf("\n");
return 0;
}
