/*
 * AVL TREE
 * Height Balanced Binary Search Tree
 * This program supports:
 * 1. Insertion O(logn)
 * 2. Deletion  O(logn)
 * 3. Search    O(logn)
 * Each node of the tree contains:
 * i.  Pointers to parent,left child and right child
 * ii. Number of children on the left and right
 * iii.Height of the current node
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef struct node{

  int value,height,left_count,right_count;
  struct node* left, right, parent;

}node;

node* newnode(int n){
  node* temp = (node*)malloc(sizeof(node));
  temp->left = NULL;
  temp->right = NULL;
  temp->parent = NULL;
  temp->value = 0;
  temp->height = 0;
  temp->left_count = 0;
  temp->right_count = 0;
  return temp;
}

void settle_node(node* root,node* tmp){
  if(root->value >= tmp->value){
    if(root->left == NULL){
      root->left = tmp;
      tmp->parent = root;
    }
    else
      settle_node(root->left,tmp);
  }
  else if(root->value < tmp->value){
    if(root->right == NULL){
      root->right = tmp;
      tmp->parent = root;
    }
    else
      settle_node(root->right,tmp);
  }
}

void make_AVL(node* root){
  if(root->left == NULL && root->right == NULL){
      tmp->height = 0;
      tmp->
  }
}

node* Insert(node* root,int n){
  node* tmp = newnode(n);
  if(root == NULL)  return tmp;
  else{
    settle_node(root,tmp);
    make_AVL(root);
  }
}

int main(){
  node *root = NULL;
  while(1){
    cout << "\tMenu\nPress:\n1 for Insertion\n2 for Deletion\n3 for Search\n4 for Traversal\nAnything else to quit\n\n";
    int ch; cin >> ch;
    if(ch>=1 && ch<=3){
      cout << "Enter the number\n";
      int n;  cin >> n;
      switch(ch){
        case 1:
          root = Insert(root,n);
        break;
        case 2:
          root = Delete(root,n);
        break;
        case 3:
          bool present = Search(root,n);
        break;
      }
    }
    else if(ch == 4){
      cout << "";
    }
    else{
      break;
    }
  }
  return 0;
}
