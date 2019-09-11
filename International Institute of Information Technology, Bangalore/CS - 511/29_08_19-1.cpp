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
using namespace std;

/*
  Each node has a pointer to the parent, left and right element count and
  a variable which stores height of the node too.
 */

typedef struct node{

  int value,height,left_count,right_count;
  struct node* left;
  struct node* right;
  struct node* parent;

}node;

void print(node *);

////////////////////KEY POINTS//////////////////////////
// 1. The parent of root is NULL                      //
// 2. Each zig* operation takes an argument for the   //
//    parent's location to be inserted.               //
//                                                    //
//                                                    //
////////////////////////////////////////////////////////

//Creates a new node. Sets all the parameters to zero and null.

node* newnode(int n){
  node* temp = (node*)malloc(sizeof(node));
  temp->left = NULL;
  temp->right = NULL;
  temp->parent = NULL;
  temp->value = n;
  temp->height = 0;
  temp->left_count = 0;
  temp->right_count = 0;
  return temp;
}

/////////////// ZIGZAG AND ZIGZIG REPRESENTATIONS ///////

//Method to update height, left_count and right_count after rotation.
void updateParam(node* tmp){
  int lhs = -1, rhs = -1;
  int lhc = -1, rhc = -1;
  if(tmp->left!=NULL){
    lhs = tmp->left->height;
    lhc = tmp->left->left_count+tmp->left->right_count;
  }
  if(tmp->right!=NULL){
    rhs = tmp->right->height;
    rhc = tmp->right->left_count+tmp->right->right_count;
  }
  tmp->height = max(lhs,rhs)+1;
  tmp->left_count = lhc+1;
  tmp->right_count = rhc+1;
}

//For left representation
node* zigzagL(node* tmp, char p){
  //Giving names to the nodes
  node* pt = tmp->parent;
  node* one = tmp;
  node* three = tmp->left;
  node* two = three->right;
  node* tree1 = one->right;
  node* tree2 = two->right;
  node* tree3 = two->left;
  node* tree4 = three->left;
  //Pointer changes
  one->left = tree2;
  if(tree2!=NULL) tree2->parent = one;
  three->right = tree3;
  if(tree3!=NULL) tree3->parent = three;
  two->right = one;
  one->parent = two;
  two->left = three;
  three->parent = two;
  two->parent = pt;
  if(p == 'L')
    pt->left = two;
  else if(p == 'R')
    pt->right = two;
  //Updating information in node one, two and three
  updateParam(one);
  updateParam(three);
  updateParam(two);
  return two;
}

//For left representation
node* zigzigL(node* tmp, char p){
  //Giving names to the nodes
  node* pt = tmp->parent;
  node* one = tmp;
  node* two = tmp->left;
  node* three = two->left;
  node* tree1 = one->right;
  node* tree2 = two->right;
  node* tree3 = three->right;
  node* tree4 = three->left;
  //Pointer changes
  one->left = tree2;
  if(tree2!=NULL) tree2->parent = one;
  two->right = one;
  one->parent = two;
  two->parent = pt;
  if(p == 'L')
    pt->left = two;
  else if(p == 'R')
    pt->right = two;
  //Updating information in node one, two and three
  updateParam(one);
  updateParam(three);
  updateParam(two);
  return two;
}

//For right representation
node* zigzagR(node* tmp, char p){
  //Giving names to the nodes
  node* pt = tmp->parent;
  node* one = tmp;
  node* three = one->right;
  node* two = three->left;
  node* tree1 = one->left;
  node* tree2 = two->left;
  node* tree3 = two->right;
  node* tree4 = three->right;
  //Pointer changes
  one->right = tree2;
  if(tree2!=NULL) tree2->parent = one;
  two->left = one;
  one->parent = two;
  three->left = tree3;
  if(tree3!=NULL) tree3->parent = three;
  two->right = three;
  three->parent = two;
  two->parent = pt;
  if(p == 'L')
    pt->left = two;
  else if(p == 'R')
    pt->right = two;
  //Updating information in node one, two and three
  updateParam(one);
  updateParam(three);
  updateParam(two);
  return two;
}

//For right representation
node* zigzigR(node* tmp, char p){
  //Giving names to the nodes
  node* pt = tmp->parent;
  node* one = tmp;
  node* two = tmp->right;
  node* three = tmp->right->right;
  node* tree1 = one->left;
  node* tree2 = two->left;
  //They are not in use. Just for a clear picture
  node* tree3 = three->left;
  node* tree4 = three->right;
  //Pointer changes
  one->right = tree2;
  if(tree2!=NULL) tree2->parent = one;
  two->left = one;
  one->parent = two;
  two->parent = pt;
  if(p == 'L')
    pt->left = two;
  else if(p == 'R')
    pt->right = two;
  //Updating information in node one, two and three
  updateParam(one);
  updateParam(three);
  updateParam(two);
  return two;
}

/////////////// ZIGZAG AND ZIGZIG REPRESENTATIONS ///////

/////////////// INSERTION BEGINS HERE ///////////////////

node* AVL_rotation(node* root){
  if(root->left == NULL && root->right == NULL) return root;
  int lhs = -1, rhs = -1;
  int lhc = -1, rhc = -1;
  if(root->left!=NULL){
    lhs = root->left->height;
    lhc = root->left->left_count+root->left->right_count;
  }
  if(root->right!=NULL){
    rhs = root->right->height;
    rhc = root->right->left_count+root->right->right_count;
  }
  //Enter AVL Height Balancing
  if(abs(rhs-lhs) == 2){
    if(root->left == NULL || (root->left!=NULL && root->right!=NULL && root->left->height < root->right->height)){
      //Zig-Zag on the right
      if(root->right->left!=NULL && (root->right->right == NULL || root->right->left->height > root->right->right->height)){
        if(root->parent == NULL){
          return zigzagR(root,' ');
        }
        else{
          node* tmp = root->parent;
          if(tmp->left == root)
            return zigzagR(root,'L');
          else
            return zigzagR(root,'R');
        }
      }
      //Zig-Zig on the right
      else{
        if(root->parent == NULL)
          return zigzigR(root,' ');
        else{
          node* tmp = root->parent;
          if(tmp->left == root)
            return zigzigR(root,'L');
          else
            return zigzigR(root,'R');
        }
      }
    }
    else{
      //Zig-Zag on the left
      if(root->left->right!=NULL && (root->left->left == NULL || root->left->right->height > root->left->left->height)){
        if(root->parent == NULL)
          return zigzagL(root,' ');
        else{
          node* tmp = root->parent;
          if(tmp->left == root)
            return zigzagL(root,'L');
          else
            return zigzagL(root,'R');
        }
      }
      //Zig-Zig on the left
      else{
        if(root->parent == NULL)
          return zigzigL(root,' ');
        else{
          node* tmp = root->parent;
          if(tmp->left == root)
            return zigzigL(root,'L');
          else
            return zigzigL(root,'R');
        }
      }
    }
  }
  else{
    root->height = max(rhs,lhs)+1;
    root->left_count = lhc+1;
    root->right_count = rhc+1;
  }
}

void settle_node(node* root,node* tmp){
  if(root->value >= tmp->value){
    if(root->left == NULL){
      root->left = tmp;
      tmp->parent = root;
      AVL_rotation(root);
    }
    else{
      settle_node(root->left,tmp);
      AVL_rotation(root);
    }
  }
  else if(root->value < tmp->value){
    if(root->right == NULL){
      root->right = tmp;
      tmp->parent = root;
      AVL_rotation(root);
    }
    else{
      settle_node(root->right,tmp);
      AVL_rotation(root);
    }
  }
}

//Remember to change the root in case another node forms a root

node* Insert(node* root,int n){
  node* tmp = newnode(n);
  if(root == NULL)  return tmp;
  else{
    settle_node(root,tmp);
    while(root->parent!=NULL){
      root = root->parent;
    }
    return root;
  }
}

/////////////// INSERTION ENDS HERE //////////////////////
/////////////// DELETION BEGINS HERE /////////////////////

node* inorderSuccessor(node* temp){
  while(temp->left!=NULL)
    temp = temp->left;
  return temp;
}

node* Delete(node* root,int key){
  if(root == NULL)
    return root;
  if(key < root->value)
    root->left = Delete(root->left, key);
  else if(key > root->value)
    root->right = Delete(root->right,key);
  else{
    if(root->left == NULL || root->right == NULL){
      node* temp = NULL;
      if(root->left!=NULL)
        temp = root->left;
      else if(root->right!=NULL)
        temp = root->right;
      if(temp == NULL){
        temp = root;
        root = NULL;
        if(temp->parent!=NULL)
          if(temp->parent->left == temp)
            temp->parent->left = NULL;
          else
            temp->parent->right = NULL;
      }
      else{
        node* pt = root->parent;
        *root = *temp;
        root->parent = pt;
      }
      free(temp);
    }
    else{
      node* temp = inorderSuccessor(root->right);
      root->value = temp->value;
      root->right = Delete(root->right,temp->value);
    }
  }
  if(root == NULL)  return root;
  root = AVL_rotation(root);
  print(root);
  return root;
}
/////////////// DELETION ENDS HERE ///////////////////////
/////////////// TRAVERSAL BEGINS HERE ////////////////////

void print(node* root){
  cout << "(("<<root<<")val:"<<root->value<<",height:"<<root->height<<",LC:"<<root->left_count<<",RC:"<<root->right_count<<", Lptr: "<<root->left<<", Rptr: "<<root->right<<", P: "<<root->parent<<") ";
}

void Preorder(node* root){
  if(root == NULL){
    return;
  }
  else{
    print(root);
    Preorder(root->left);
    Preorder(root->right);
  }
}

void Postorder(node* root){
  if(root == NULL)  return;
  else{
    Postorder(root->left);
    Postorder(root->right);
    print(root);
  }
}

void Inorder(node* root){
  if(root == NULL)  return;
  else{
    Inorder(root->left);
    print(root);
    Inorder(root->right);
  }
}

/////////////// TRAVERSAL ENDS HERE //////////////////////
/////////////// SEARCH BEGINS HERE ///////////////////////

bool Search(node* root, int key){
  if(root!=NULL && root->value == key)  return true;
  else if(root->value > key && root->left!=NULL) return Search(root->left,key);
  else if(root->value < key && root->right!=NULL) return Search(root->right,key);
  else  return false;
}

/////////////// SEARCH ENDS HERE /////////////////////////


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
          while(root->parent!=NULL) root = root->parent;
        break;
        case 3:
          bool present = Search(root,n);
        break;
      }
    }
    else if(ch == 4){
      cout << "Press:\n1 for Preorder Traversal\n2 for Inorder Traversal\n3 for Postorder Traversal\n\n";
      cin >> ch;
      if(ch == 1) Preorder(root);
      else if(ch == 2)  Inorder(root);
      else if(ch == 3)  Postorder(root);
      cout << endl;
    }
    else{
      break;
    }
  }
  return 0;
}
