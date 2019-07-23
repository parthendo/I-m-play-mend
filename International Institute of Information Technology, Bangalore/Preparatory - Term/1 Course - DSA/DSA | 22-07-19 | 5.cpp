/*
 * Problem statement: Find the maximum height of a tree
 * Data structure used: Stack
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
  int val;
  struct node *left, *right;
}node;

node* AddNode(int n){
  node* temp = (node*)malloc(sizeof(node));
  temp->val = n;
  temp->left = temp->right = NULL;
  return temp;
}
int maxHeight(node* root){
  if(root == NULL)
    return -1;
  else{
    int p,q;
    p = maxHeight(root->left);
    q = maxHeight(root->right);
    return max(p,q)+1;
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
  cout << "The maximum height of a tree is " << maxHeight(root) << endl;
  return 0;
}
