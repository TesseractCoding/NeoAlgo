// Post Order Traversal

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct node
{
int data;
struct node *left;
struct node *right;
}node;
int count=1;
node *insert(node *tree,int digit)
{
if(tree == NULL)
{
tree = (node *)malloc(sizeof(node));
tree->left = tree->right=NULL;
tree->data = digit;
count++;
}
else if(count%2 == 0)
tree->left = insert(tree->left, digit);
else
tree->right = insert(tree->right, digit);
return tree;
}
void postorder(node *t)
{
if(t != NULL)
{
postorder(t->left);
postorder(t->right);
printf(" %d", t->data);
}
}
main()
{
node *root = NULL;
int digit;
puts("Enter integer:To quit enter 0");
scanf("%d", &digit);
while(digit != 0)
{
root=insert(root,digit);
scanf("%d",&digit);
}
printf("\nThe postorder traversal of tree is:\n");
postorder(root);
getchar();
}

/*

Sample Output

Enter integer:To quit enter 0                                                                                                   
12 4 6 9 14 17 3 19 0  

The postorder traversal of tree is:                                                                                           
19 17 9 4 3 14 6 12 

*/
