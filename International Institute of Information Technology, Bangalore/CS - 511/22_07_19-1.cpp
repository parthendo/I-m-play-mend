/*
 * Problem statement: Implement preorder traversal in a binary tree using user stack.
 * Data structure used: Stack
 * Worst Case:    O
 * Sample Input:
 *
 * Sample Output:
 */
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

typedef struct node{
  int val;
  struct node *left, *right;
}node;

node* AddNode(int n){
  node* temp = (node*)malloc(sizeof(node));
  temp->val = n;
  temp->left = temp->right = NULL;
  return temp;
}

void preorder(node* root){
  stack<node*> stk;
  stk.push(root);
  while(!stk.empty()){

    node *temp = stk.top();
    stk.pop();
    cout << temp->val << " ";
    if(temp->right!=NULL)
      stk.push(temp->right);
    if(temp->left!=NULL)
      stk.push(temp->left);
  }
}

int main(){
  node* root;
  root = AddNode(10);
  root->left = AddNode(9);
  root->left->left = AddNode(7);
  root->left->right = AddNode(3);
  root->left->right->left = AddNode(17);
  root->right = AddNode(8);
  root->right->left = AddNode(5);
  cout << "Preorder traversal: ";
  preorder(root);
  cout << endl;
  return 0;
}
