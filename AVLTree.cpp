#include "AVLTree.hpp"

AVLTree::AVLTree():BinaryTree()
{
  ;
}

int AVLTree::height(node *root)
{
  if(root==nullptr)
    return 0;
   int left,right;
   left=1+height(root->leftchild);
   right=1+height(root->rightchild);
   if(left>right)
    return left;
   else
    return right;
}

int AVLTree::height()
{
  return height(root);
}

int AVLTree::isBalanced(node *r)
{
  if(r==nullptr)
    return true;
  int b=height(r->leftchild)-height(r->rightchild);
  return b;
}

int AVLTree::isBalanced()
{
  return isBalanced(root);
}

void AVLTree::rightrotate(node *r)
{
   
    node *p;
    node *tp;
    p = r;
    tp = p->rightchild;

    p->rightchild = tp->leftchild;
    tp->leftchild= p;
    root=tp;
   // return tp;
}

void AVLTree::leftrotate(node *r)
{
      node *temp;
      node *tp;
      temp = r;
      tp = temp->leftchild;

      temp->leftchild = tp->rightchild;
      tp->rightchild = temp;
      root=tp;
     // return tp;
}

void AVLTree::rlrotate(node *r)
{
     node *p;
     node *tp;
     node *tp2;
    p = r;
    tp = r->rightchild;
    tp2 =p->rightchild->leftchild;

    p -> rightchild = tp2->leftchild;
    tp ->leftchild = tp2->rightchild;
    tp2 ->leftchild = p;
    tp2->rightchild = tp;
    root=tp2;
   // return tp2;
}

void AVLTree::lrrotate(node *r)
{
   node *p;
     node *tp;
     node *tp2;
    p = r;
    tp = r->leftchild;
    tp2 =p->leftchild->rightchild;

    p -> leftchild = tp2->rightchild;
    tp ->rightchild = tp2->leftchild;
    tp2 ->rightchild = p;
    tp2->leftchild = tp;
    root=tp2;
   // return tp2;
}

void AVLTree::insert(node* r,string a)
{
   BinaryTree::insert(a);
    
        //cout<<isBalanced(r)<<isBalanced(r->rightchild)<<endl;
        if(isBalanced(r)==2 && isBalanced(r->leftchild)>=1)
        {
            leftrotate(r);
        }
        else if(isBalanced(r)==-2 && isBalanced(r->rightchild)<=-1)
        {
            rightrotate(r);
        }
        else if(isBalanced(r)==-2 && isBalanced(r->rightchild)>=1)
        {
            rlrotate(r);
        }
        else if(isBalanced(r)==2 && isBalanced(r->leftchild)<=-1)
        {
            lrrotate(r);
        }
}

void AVLTree::insert(string a)
{
  if(root==nullptr)
  {
    root=new node(a);
    return ;
  }
  AVLTree::insert(root,a);
}

void AVLTree::remove(string a)
{
   AVLTree::remove(root,a);
}

void AVLTree::remove(node *r,string a)
{
   BinaryTree::remove(a);

   if(isBalanced(r)==2 && isBalanced(r->leftchild)>=1)
        {
            leftrotate(r);
        }
        else if(isBalanced(r)==-2 && isBalanced(r->rightchild)<=-1)
        {
            rightrotate(r);
        }
        else if(isBalanced(r)==-2 && isBalanced(r->rightchild)>=1)
        {
            rlrotate(r);
        }
        else if(isBalanced(r)==2 && isBalanced(r->leftchild)<=-1)
        {
            lrrotate(r);
        }
}


