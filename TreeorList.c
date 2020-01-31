#include<stdio.h>
#include<stdlib.h>
struct Btree {
    int num;
    struct Btree *left,*right;
};

typedef struct Btree Btree;
typedef Btree *BtreePtr;

int ListorTree (BtreePtr root);
BtreePtr insert (BtreePtr root, int value);
void printTree (BtreePtr root);

int main ()
{
    BtreePtr root=NULL;
    int value, res;

    printf("enter: ");
    while (scanf("%d",&value)==1 && value !=-1)
    {
        root=insert(root,value);
        printTree(root);
        printf("\n");
        printf("enter: ");
    }

    res=ListorTree(root);

    if (res==1)
    {
        printf("is a List.\n");
    }
    else
    {
        printf("is a Tree.\n");
    }
}
void printTree (BtreePtr root)
{
    if (root==NULL)
    {
        return;
    }
    printTree(root->left);
    printf("%d ",root->num);
    printTree(root->right);
}


BtreePtr insert (BtreePtr root, int value)
{
        if (root==NULL)
        {
            root=(BtreePtr)malloc(sizeof(BtreePtr));
            root->num=value;
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        if (value < root->num)
        {
            root->left=insert(root->left,value);
        }
        else if (value > root->num)
        {
            root->right=insert(root->right,value);
        }
        else
        {
            return root;
        }

}
/*List return 1, not List return 0*/
int ListorTree (BtreePtr root)
{
    int left=0, right=0;

        if (root->left!=NULL)
        {
            left=1;
        }
        if (root->right!=NULL)
        {
            right=1;
        }
        if (left==0 && right==0)
        {
            return 1;
        }
        if (left>right)
        {
            ListorTree (root->left);
        }
        else if (left<right)
        {
            ListorTree (root->right);
        }
        else
        {
            return 0;
        }
}
