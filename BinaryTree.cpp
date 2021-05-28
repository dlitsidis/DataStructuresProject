#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  root->leftchild=nullptr;
  root->rightchild=nullptr;
  root=nullptr;
}

void BinaryTree::insert(string a)
{
  if(root==nullptr)
    root=new node(a);
  
  insertNode(root,a);
}

bool BinaryTree::insertNode(node* root,string value)
{
    if(value==root->data.value)
    {
      root->data.counter++;
      return false;
    }
    if(value>root->data.value)
    {
       if(root->rightchild==nullptr)
       {
         root->rightchild=new node(value);
         return true;
       }
       insertNode(root->rightchild,value);
    }
    else
    {
      if(root->leftchild==nullptr)
       {
         root->leftchild=new node(value);
         return true;
       }
       insertNode(root->leftchild,value);
    }
    return true;
}
    
struct node* search(struct node* root, string key)
{
    if (root == nullptr || root->data.value == key)
       return root;
    
    if (root->data.value< key)
    {
      return search(root->rightchild, key);
    }
    else
    {
      return search(root->leftchild, key);
    }
}

void BinaryTree::printPostOrder()
{
    printPostOrder(root);
}

void BinaryTree::printPostOrder(node *r)
{
    if (r==nullptr)
        return;
 
    printPostOrder(r->leftchild);
 
    printPostOrder(r->rightchild);
 
    cout <<r->data.value <<endl;
}

void BinaryTree::printPreOrder()
{
  printPreOrder(root);
}

void BinaryTree::printInOrder()
{
  printInOrder(root);
}

void BinaryTree::printPreOrder(node * r)
{
  if (r==nullptr)
        return;

  cout <<r->data.value<<": "<<r->data.counter <<endl;

  printPreOrder(r->leftchild);
 
  printPreOrder(r->rightchild);
}

void BinaryTree::printInOrder(node * r)
{
  if (r==nullptr)
        return;

  printInOrder(r->leftchild);

  cout <<r->data.value <<endl;
 
  printInOrder(r->rightchild);
}

