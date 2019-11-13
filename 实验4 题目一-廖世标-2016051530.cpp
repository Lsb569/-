#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int TElemType;
typedef int Status;
typedef struct BiTNode{//�������ڵ�ṹ
  TElemType date;
  struct BiTNode *lChild, *rChild;
}BiTNode, *BiTree;
Status CreateBiTree(BiTree &T){//������
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
printf("����%d�����ӽڵ㣺", ch);
CreateBiTree(T->lChild);
printf("����%d�����ӽڵ㣺", ch);
CreateBiTree(T->rChild);
}
return 1;
}
Status exchange(BiTree &T){//������������
BiTree p;
p=T->lChild;
T->lChild=T->rChild;
T->rChild=p;
return 1;
}
Status PreOrderTraverse(BiTree &T,Status(&Visit)(BiTree &T)){//�������������Visit()������
if (T == NULL)
return 0;
Visit(T);
PreOrderTraverse(T->lChild,Visit);
PreOrderTraverse(T->rChild,Visit);
return 1;
}
Status Print(BiTree &T){//����ڵ�ֵ��
    printf("%d ",(*T).date);
    return 0;
}
int main(){
BiTree T;
printf("������ڵ�ֵ������-1��ʾ������û����Ҷ\n");
CreateBiTree(T);
printf("����������:");
PreOrderTraverse(T,Print);
printf("\n��������������������\n");
PreOrderTraverse(T,exchange);
PreOrderTraverse(T,Print);
printf("\n");
return 0;
}
