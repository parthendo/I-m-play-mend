/*
 * Problem statement: Create a binary search tree and add the fucntionality to:
 *                    > Add a node
 *                    > Search a node
 *                    > Delete a node in that tree
 * Data structure used: Binary Search Tree
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
  struct node* left;
  struct node* right;
}node;

void AddNode(node* root, int n){
  if(n<=root->val){
    if(root->left == NULL){
      node* temp = (node*)malloc(sizeof(node));
      temp->val = n;
      temp->left = NULL;
      temp->right = NULL;
      root->left = temp;
    }
    else
      AddNode(root->left,n);
  }
  else{
    if(root->right == NULL){
      node* temp = (node*)malloc(sizeof(node));
      temp->val = n;
      temp->left = NULL;
      temp->right = NULL;
      root->right = temp;
    }
    else
      AddNode(root->right,n);
  }
}

bool search(node* root, int n){
  
}

int main(){
  node* root = NULL;
  while(1){
    int ch;
    cout << "Press \n1. to add a node\n2. to delete a node\n3. to search the node\n4. Exit";
    cin >> ch;
    if(ch == 1){
      int n;  cin >> n;
      if(root == NULL){
        node* temp = (node*)malloc(sizeof(node));
        temp->val = n;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
      }
      else
        AddNode(root,n);
    }
    else if(ch == 2){

    }
    else if(ch == 3){
      int n; cin >> n;
      if(search(root,n))
        cout << n << " exists in the tree\n";
      else
        cout << n << " does not exist in the tree\n";
    }
    else
      break;
  }
}
