#include <stdio.h>
#include <stdlib.h>
//链式结构实现
typedef char ElemType;

//树结点
typedef struct TreeNode {
    ElemType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

//用树结点指针表示二叉树
typedef TreeNode* BiTree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

//创建二叉树
// T是二级指针(BiTree**)
//  *T就是对二叉树的结点进行操作
void createTree(BiTree *T)
{
	ElemType ch;
	ch = str[idx++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		createTree(& ( (*T)->lchild ) );
		createTree(& ( (*T)->rchild ) );
	}
}

/*二叉树的遍历*/

//前序遍历
void preOrder(BiTree T){
    if(T == NULL) return;
    printf("%c ", T->data);
    //递归子树
    preOrder(T->lchild);
    preOrder(T->rchild);
}

//中序遍历
void inOrder(BiTree T){
    if(T == NULL) return;
    inOrder(T->lchild);
    printf("%c ", T->data);
    inOrder(T->rchild);
}

//后序遍历
void postOrder(BiTree T){
    if(T == NULL) return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c ", T->data);
}


int main(){
    BiTree T;
    createTree(&T);
    printf("前序遍历：");
    preOrder(T);
    printf("\n");
    printf("中序遍历：");
    inOrder(T);
    printf("\n");
    printf("后序遍历：");
    postOrder(T);
    printf("\n");
    return 0;
}

