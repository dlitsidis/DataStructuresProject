#include "BinaryTree.hpp"

BinaryTree::BinaryTree()
{
  //αρχικοποίηση της ρίζας του δέντρου και των παιδιών του σε δείκτη nullptr
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
    if(value==root->data.value) //αν το στοιχείο που προσπαθούμε να εισάγουμε υπάρχει ήδη, τότε αυξάνουμε το
    {                           //πλήθος εμφανίσεων στο struct data
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
    
//αναδρομική συνάρτηση για αναζήτηση στοιχείου σε δυαδικό δέντρο
node* BinaryTree::search(node* root, string key)
{
    if (root == nullptr || root->data.value == key)
       return root;
    
    if (root->data.value< key) //λόγω της σύμβασης πως το δεξί παιδί έχει μεγαλύτερη τιμή από την ρίζα όταν το στοιχείο που αναζητάμε είναι μεγαλύτερο της ρίζας πραγματοποιούμε την αναζήτηση στο δεξί υποδέντρο
    {
      return search(root->rightchild, key);
    }
    else //αντίστοιχα όταν είναι μικρότερο, πραγματοποιούμε την αναζήτηση στο αριστερό υποδέντρο
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

void BinaryTree::printPostOrder(node *r) //υλοποίηση της μεταδιατεταγμένης διάσχισης δέντρου
{                                        //ακολουθούμε την σειρά: αριστερό υποδέντρο - δεξί υποδέντρο - ρίζα
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

void BinaryTree::printPreOrder(node * r) //υλοποίηση της προδιατεταγμένης διάσχισης δέντρου
{                                       //ακολουθούμε την σειρά: ρίζα - αριστερό υποδέντρο - δεξί υποδέντρο
  if (r==nullptr)
        return;

  cout <<r->data.value<<": "<<r->data.counter <<endl;

  printPreOrder(r->leftchild);
 
  printPreOrder(r->rightchild);
}

void BinaryTree::printInOrder(node * r) //υλοποίηση της ενδοδιατεταγμένης διάσχισης δέντρου
{                                       //ακολουθούμε την σειρά: αριστερό υποδέντρο - ρίζα - δεξί υποδέντρο
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

node* BinaryTree::max(node *r)
{
  if(r==nullptr)
    return nullptr;
  node *max;
  max=r;
  while(max->rightchild!=nullptr)
    max=max->rightchild;
  return max;
}


