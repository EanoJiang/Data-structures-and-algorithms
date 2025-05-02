#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode;

typedef ThreadNode *ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0;

ThreadTree prev;

//创建二叉树
void createTree(ThreadTree *T){
    ElemType ch;
	ch = str[idx++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (ThreadTree)malloc(sizeof(ThreadNode));
		(*T)->data = ch;

		createTree(& ( (*T)->lchild ) );
        //lchild有左孩子，则ltag=0
        if( (*T)->lchild != NULL){
            (*T)->ltag = 0;
        }

        createTree(& ( (*T)->rchild ) );
        if( (*T)->rchild != NULL){
            (*T)->rtag = 0;
        }
	}
}

//线索化——加前驱后继的逻辑
void threading(ThreadTree T){
    if(T != NULL){
        //一直往左边遍历
        threading(T->lchild);
        //当前结点的左孩子为空，当前结点的左孩子设定为指向前驱
        if(T->lchild == NULL){
            T->ltag = 1;
            T->lchild = prev;
        }
        //前驱结点的右孩子为空，前驱结点的右孩子设定为指向当前结点(当前结点就是前驱节点的后继)
        if(prev->rchild == NULL){
            prev->rtag = 1;
            prev->rchild = T;
        }
        //更新prev到根节点，往右边遍历
        prev = T;
        threading(T->rchild);
    }
}

//中序遍历线索化
void inOrderThreading(ThreadTree *head ,ThreadTree T){
    *head = (ThreadTree)malloc(sizeof(ThreadNode));
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->rchild = (*head);
    if(T == NULL){
        (*head)->lchild = (*head);
    }
    else{
        //头节点的左孩子指向树的根节点
        (*head)->lchild = T;

        //prev：上一个访问的节点是头节点
        prev = (*head);

        //加前驱后继的逻辑
        threading(T);

        //最后一个节点的右孩子指向头节点
        prev->rtag = 1;
        prev->rchild = (*head);

        //头节点的右孩子指向遍历的最后一个节点
        (*head)->rchild = prev;

    }
}

//基于线索的中序遍历
void inOrder(ThreadTree T){
    ThreadTree current = T->lchild;
    while(current != T){
        //如果当前节点有左孩子，则一直往左边遍历
        //没有左孩子，则退出当前循环 输出当前节点
        while(current->ltag == 0){
            current = current->lchild;
        }
        printf("%c",current->data);
        //往右边遍历, 直到右孩子不为空且当前的右孩子是头节点
        while(current->rtag == 1 && current->rchild != T){
            current = current->rchild;
            printf("%c",current->data);
        }
        current = current->rchild;
    }
    printf("\n");
}

int main(){
    ThreadTree head;
    ThreadTree T;
    createTree(&T);
    inOrderThreading(&head,T);
    inOrder(head);
    return 0;
}