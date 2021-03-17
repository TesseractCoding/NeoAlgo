/*Given a binary tree as input, output it as the linkedlist in-place.
for example:
If given input tree is:-
              6
             / \
            4   8
           /   / \
          2   5   9
output flattened tree should be like a linkedlist in-place as shown below :-      
                               6
                              /
                             8   
                            /
                           9
                          /
                         5
                        /
                       4
                      /
                     2
*/


#include<iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
 };

 TreeNode* node(int val)
 {
     TreeNode* c=new TreeNode;
     c->val=val;
     c->left=c->right=NULL;
     return c;
 }
 
/*flatten is defined as the function to convert binary tree to linkedlist by altering the left node and making the right node point to null.*/

TreeNode* flatten(TreeNode* A) {
    if(A==NULL) //if the tree is empty
    {
        return A;
    }
    if(A->left==NULL && A->right==NULL) //for the case of leaf node
    { 
        return A;
    }
    if(A->right==NULL && A->left!=NULL)
    {
         A->left=flatten(A->left);
         return A;
    }
    else{
    TreeNode* j=A;
    TreeNode* p=j->left;
    TreeNode* q=j->right;    
    while(q->left!=NULL)
    {
        q=q->left;
    }
     q->left=p;
    j->left=flatten(j->right);
    j->right=NULL;
    return j;}
    
}

void inorder_output(TreeNode* root)  //function for output.
{if(root==NULL)
{
    return;
}
inorder_output(root->left);
cout<<root->val<<" ";
inorder_output(root->right);
}


TreeNode* insert_value(TreeNode* root,int val,queue<TreeNode*> &t)
{   TreeNode* temp=node(val);
if(val==-1)
{
temp=NULL;
}
    if(root==NULL)
    {
        root=temp;
    }
    else if(t.front()->left==NULL)
    t.front()->left=temp;
    else
    {
        t.front()->right=temp;
        t.pop();
    }
    t.push(temp);
    return root;
}
TreeNode* form_tree(vector<int>v)  //code for creating tree
{
TreeNode* root=NULL;
queue<TreeNode*>t;
for(int i=0;i<v.size();i++)
{
root=insert_value(root,v[i],t);
}
return root;
}

int main()
{int n;
cin>>n;
vector<int>v;
while(n--)
{int u;
cin>>u;
    v.push_back(u);
}
TreeNode* A=form_tree(v);
inorder_output(flatten(A));
}

/*
sample input:
13 
6 4 8 2 -1 5 9 -1 -1 -1 -1 -1 -1

sample output:
2 4 5 9 8 6
*/
