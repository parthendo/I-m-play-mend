/*
 * Problem statement: Find the maximum height of a tree
 * Data structure used: Queue
 * Worst Case:    O
 * Sample Input:
 *
 * Sample Output:
 *
 * Note: Unlike the other implementation, the leaves are
 * considered to be at the height 0.
 */
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

typedef struct node{
  int val; int level;
  struct node *left, *right;
}node;

node* AddNode(int n){
  node* temp = (node*)malloc(sizeof(node));
  temp->val = n;
  temp->level = 0;
  temp->left = temp->right = NULL;
  return temp;
}

void setLevel(node* root){
  queue<node*> q;
  root->level = 0;
  q.push(root);
  while(!q.empty()){
    node* temp = q.front();
    q.pop();
    if(temp->left!=NULL){
      temp->left->level = temp->level+1;
      q.push(temp->left);
    }
    if(temp->right!=NULL){
      temp->right->level = temp->level+1;
      q.push(temp->right);
    }
  }
}

void inorder(node* root){
  if(root == NULL)
    return;
  else{
    inorder(root->left);
    cout << "(" << root->val << "," << root->level << ") ";
    inorder(root->right);
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
  setLevel(root);
  cout << "The inorder traversal of the tree is: ";
  inorder(root);
  return 0;
}
