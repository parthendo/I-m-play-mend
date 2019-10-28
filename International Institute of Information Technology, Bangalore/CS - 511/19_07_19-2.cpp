/*
 * Problem statement: Input a tree and print all possible traversals of the tree
 * Data structure used: Stack
 * Worst Case:    O
 * Sample Input:
 *
 * Sample Output:
 */
 #include <iostream>
 #include <cstdlib>
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
  if(root == NULL)  return;
  else{
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(node* root){
  if(root == NULL)  return;
  else{
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
  }
}

void postorder(node* root){
  if(root == NULL)  return;
  else{
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
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
  cout << "\nInorder traversal: ";
  inorder(root);
  cout << "\nPostorder traversal: ";
  postorder(root);
  cout << endl;
  return 0;
}
