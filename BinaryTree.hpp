#include <cstring>
#include <iostream>
using namespace std;

#ifndef bst
#define bst
struct word//struct που αποθηκευει μια λεξη και εναν μετρητη που μας λεει ποσες φορες εμφανιστηκε η λεξη
{
  string value;
  int counter;
};

class node//κλαση που αναπαριστα εναν κομβο
{
  public:
    word data;//τα δεδομενα του κομβου
    node *leftchild=nullptr;//δεικτης στο αριστερο παιδι του κομβου
    node *rightchild=nullptr;//δεικτης στο δεξι παιδι του κομβου

    node()//κατασκευαστης που αρχικοποιει τις τιμες του κομβου
    {
      leftchild=nullptr;
      rightchild=nullptr;
      data.value="";
      data.counter=1;
    }

    node(string a)//κατασκευαστης που δεχεται ως ορισμα μια συμβολοσειρα αρα βαζει μια τιμη στην λεξη μας
    {
      data.counter=1;
      data.value=a;
      leftchild=nullptr;
      rightchild=nullptr;
    }
};

class BinaryTree//κλαση του δυαδικου δεντρου αναζητησης
{
   protected:
     bool insertNode(node*,string);//συναρτηση insert που καλειται απο την public insert με σκοπο την εισαγωγη του κομβου στο δεντρο
     node* root=new node();//η ριζα του δενδρου

     void printPostOrder(node *);//η private συναρτηση της postorder που καλειται απο την public postorder
     void printInOrder(node *);//η private συναρτηση της inorder που καλειται απο την public postorder
     void printPreOrder(node *);//η private συναρτηση της preorder που καλειται απο την public postorder
     node* search(node*,string);//η private συναρτηση της search που καλειται απο την public
     node* remove(node*,string);//η private συναρτηση της remove που καλειται απο την public
     node* min(node*);//συναρτηση που βρισκει το μικροτερο στοιχειο στο δεντρο
     node* max(node*);//συναρτηση που βρισκει το μεγαλυτερο στοιχειο στο δεντρο
   public:
     BinaryTree();

     void insert(string);//συναρτηση που υλοποιει την εισαγωγη ενος κομβου στο δεντρο
     bool remove(string);//συναρτηση που διαφραφει εναν κομβο απο το δεντρο
     bool search(string);//συναρτηση που βρισκει εαν υπαρχει ενα στοιχειο στο δεντρο η οχι

     void printPostOrder();//διασχιση των στοιχειων με postorder διαπεραση
     void printInOrder();//διασχιση των στοιχειων με inorder διαπεραση
     void printPreOrder();//διασχιση των στοιχειων με preorder διαπεραση
};
#endif

