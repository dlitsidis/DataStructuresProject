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
  {
    root=new node(a);
    return ;
  }
  
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
    
node* BinaryTree::search(node* root, string key)
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

bool BinaryTree::search(string key)
{
  node *n=new node();
  n=search(root,key);
  if(n==nullptr)
   return false;
  int c=n->data.counter;
  cout<<"\""<<n->data.value<<"\""<<" was found: "<<c<<" times"<<endl;
  return true;
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

  cout <<r->data.value <<": "<<r->data.counter <<endl;
 
  printInOrder(r->rightchild);
}

node* BinaryTree::min(node *r)
{
  if(r==nullptr)
    return nullptr;
  node *min;
  min=r;
  while(min->leftchild!=nullptr)
    min=min->leftchild;
  return min;
}

node* BinaryTree::remove(node *root,string a)
{
    if (root==nullptr)
        return root;
 
    if (a< root->data.value)
        root->leftchild = remove(root->leftchild, a);
    else if (a > root->data.value)
        root->rightchild = remove(root->rightchild, a);
    else 
    {
        if (root->leftchild==nullptr and root->rightchild==nullptr)
        {
            //free(root);
            return nullptr;
        }
        else if (root->leftchild==nullptr)
        {
            node* temp=root->rightchild;
            free(root);
            return temp;
        }
        else if (root->rightchild==nullptr) {
            node* temp = root->leftchild;
            free(root);
            return temp;
        }
 
        node* temp = min(root->rightchild);
        root->data.value = temp->data.value;
        root->rightchild= remove(root->rightchild, temp->data.value);
    }
    return root;
}

bool BinaryTree::remove(string a)
{
  if(search(root,a)!=nullptr)
  {
    remove(root,a);
    return true;
  }
  else
  {
    return false;
  }
}

