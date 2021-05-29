#include <cstring>
#include <iostream>
using namespace std;

struct word
{
  string value;
  int counter;
};

class node
{
  public:
    word data;
    node *leftchild;
    node *rightchild;

    node()
    {
      leftchild=nullptr;
      rightchild=nullptr;
      data.value="";
      data.counter=1;
    }

    node(string a)
    {
      data.counter=1;
      data.value=a;
      leftchild=nullptr;
      rightchild=nullptr;
    }
};

class BinaryTree
{
   private:
     bool insertNode(node*,string);
     node* root=new node();

     void printPostOrder(node *);
     void printInOrder(node *);
     void printPreOrder(node *);
     node* search(node*,string);
     node* remove(node*,string);
     node* min(node*);
   public:
     BinaryTree();

     void insert(string);
     bool remove(string);
     bool search(string);

     void printPostOrder();
     void printInOrder();
     void printPreOrder();
};
