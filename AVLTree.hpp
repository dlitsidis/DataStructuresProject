#include <cstring>
#include <iostream>
#include <cmath>
#include "BinaryTree.hpp"
using namespace std;

class AVLTree: public BinaryTree //η συνάρτηση κληρονομεί από το δυαδικό δέντρο αναζήτησης
{
   private:
    int isBalanced(node*);//συναρτηση η οποια καλειται απο την public isBalanced
    int height(node*);//συναρτηση η οποια καλειται απο την puplic height
    void rightrotate(node*);//συναρτηση η οποια υλοποιει την δεξιοστροφη περιστροφη
    void leftrotate(node*);//συναρτηση η οποια υλοποιει την αριστεροστροφη περιστροφη
    void insert(node*,string);//συναρτηση η οποια καλειται απο την public insert
    void remove(node*,string);//συναρτηση η οποια καλειται απο την public remove
    void rlrotate(node*);//συναρτηση η οποια υλοποει την rl περιστροφη
    void lrrotate(node*);//συναρτηση η οποια υλοποιει την lr περιστροφη
   public:
     AVLTree();//κατασκευαστης της κλασης που αρχικοποιει τις τιμες
     //~AVLTree();
     int height();//συναρτηση που υπολογιζει το υψος του δενδρου
     int isBalanced();
     void insert(string);//συναρτηση εισαγωγης ενος κομβου στο avl δενδρο
     void remove(string);//συναρτηση διαγραφης ενος κομβου απο το avl δενδρο
};

