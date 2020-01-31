#include<stdio.h>
#include<stdlib.h>

struct Btree
{
    int pres;
    struct Btree *left,*right;
};

typedef struct Btree Btree;
typedef Btree* BtreePtr;

BtreePtr insert (BtreePtr root,int pres);
int collect_pres(BtreePtr root);
void printTree (BtreePtr root);

int main ()
{
    BtreePtr root=NULL;
    int sumpres, value;
    printf("enter: ");
    while (scanf("%d",&value)==1 && value !=-1)
    {
        root=insert(root,value);
        printTree(root);
        printf("\n");
        printf("enter: ");
    }

    sumpres= collect_pres(root);
    printf("collect: %d\n",sumpres);
    printTree(root);
    return 0;

}

BtreePtr insert (BtreePtr root, int pres)
{
    if (root==NULL)
    {
        root=(BtreePtr)malloc(sizeof(Btree));
        root->pres=pres;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if (pres<root->pres)
    {
        root->left=insert(root->left,pres);
    }
    else if (pres>root->pres)
    {
        root->right=insert(root->right,pres);
    }
    else
    {
        return root;
    }
}
void printTree (BtreePtr root)
{
    if (root==NULL)
    {
        return;
    }
    printTree(root->left);
    printTree(root->right);
    printf("%d ",root->pres);
}
int collect_pres(BtreePtr root)
{
    int presLeft, presRight, sum;
    if (root==NULL)
    {
        return 0;
    }
    presLeft=collect_pres(root->left);
    presRight=collect_pres(root->right);
    sum=presLeft+presRight+root->pres;
    root->pres=0;
    return sum;
}
