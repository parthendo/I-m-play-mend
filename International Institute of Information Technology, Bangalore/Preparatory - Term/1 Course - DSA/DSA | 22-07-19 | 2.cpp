/*
 * Problem statement: Implement inorder traversal in a binary tree using user stack.
 * Data structure used: Stack
 * Worst Case:    O
 * Sample Input:
 *
 * Sample Output:
 */
#include <iostream>
#include <cstdlib>
#include <stack>
#include <utility>
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

void inorder(node* root){
  stack<pair<node*,int> > stk;
  stk.push({root,0});
  while(!stk.empty()){

    pair<node *,int > temp = stk.top();
    stk.pop();
    if(temp.second == 1){
      cout << (temp.first)->val << " ";
    }
    else{
      if((temp.first)->right!=NULL)
        stk.push({(temp.first)->right,0});
        temp.second = 1;
        stk.push(temp);
      if((temp.first)->left!=NULL)
        stk.push({(temp.first)->left,0});
    }
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
  cout << "Inorder traversal: ";
  inorder(root);
  cout << endl;
  return 0;
}
