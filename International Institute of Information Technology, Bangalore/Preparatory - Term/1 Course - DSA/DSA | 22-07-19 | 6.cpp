/*
 * Problem statement: Find the level order traversal in a binary tree.
 * Data structure used: Queue
 * Worst Case:    O
 * Sample Input:
 *
 * Sample Output:
 */
#include <iostream>
#include <cstdlib>
#include <queue>
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

void levelOrderTraversal(node* root){
  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    node* temp = q.front();
    q.pop();
    cout << temp->val << " ";
    if(temp->left!=NULL)  q.push(temp->left);
    if(temp->right!=NULL) q.push(temp->right);
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
  cout << "Level order traversal of the tree is: ";
  levelOrderTraversal(root);
  cout << endl;
  return 0;
}
