#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include "Array.hpp"
#include "Sorted.hpp"
#include "BinaryTree.hpp"
#include "AVLTree.hpp"
#include "HashTable.hpp"
#include <chrono>
#include <cstdlib>
#include <unistd.h>

using namespace std;
using namespace std::chrono;

bool removeSpecialChars(string& a) //συνάρτηση που δέχεται με αναφορά ως όρισμα τις λέξεις του αρχείου και αφαιρεί τους ειδικούς χαρακτήρες
{
  for(int i=0;i<a.size();i++) //ελέγχουμε ποιοι χαρακτήρες βρίσκονται στο εύρος των κεφαλαίων λατινικών και προσθέτοντας 32 τους μετατρέπουμε σε πεζούς
    {
      if(a[i]>=65 && a[i]<=92) //ισοδύναμο με a[i]>= 'A' && a[i]<= 'Z'
      {
         a[i] += 32;
      }
      
      if(a[i]>122 || a[i]<97) //ελέγχουμε ποιοι χαρακτήρες βρίσκονται εκτός εύρους πεζών λατινικών και τους αφαιρούμε
       {
        
         a.erase(a.begin()+i); //η συνάρτηση erase ανήκει στην <cstring> και αφαιρεί έναν χαρακτήρα μιας συμβολοσειράς
         --i;                  //η συνάρτηση begin μας δίνει τον αρχικό χαρακτήρα της συμβολοσειράς (προσθέτοντας i                            μεταβαίνουμε στον χαρακτήρα που μελετάμε εκείνη την στιγμή)
       }                       //σε περίπτωση αφαίρεσης ενός χαρακτήρα μεταβάλλουμε κατάλληλα το i για να λάβουμε υπόψην                         την μείωση του μεγέθους
    }
    if(a.size()==0)            //αν η λέξη που εισάγαμε με αναφορά αποτελείται μόνο από ειδικούς χαρακτήρες - και συνεπώς
      return false;           //έχει διαγραφεί ολόκληρη, επιστρέφουμε false καθώς δεν υπάρχει συμβολοσειρά προς
    return true;              //αποθήκευση. Ειδάλλως επιστρέφουμε true.
}

bool readFile(string filename,string* &words,int &i)//συνάρτηση που δέχεται ως όρισμα μια συμβολοσειρά που ειναι το ονομα του αρχειου που θα ανοίξουμε εναν δυναμικο πινακα με αναφορα στον οποιο αποθηκευουμε το αρχειο καθως και εναν ακεραιο με αναφορα στον οποιο αποθηκευουμε το μεγεθος του πινακα
{
   string a;
   int size=0;
   ifstream ifs;
    
   ifs.open(filename);
    while(ifs>>a)
        size++;
    ifs.close();
    //cout<<size<<endl;
   i=0;//αρχικοποιει το μεγεθος του πινακα
   words=new string[size];
   ifs.open(filename);
   if(ifs.is_open())//τσεκαρει αν μπορεσε να ανοιξει σωστα το αρχειο
   {
      while(ifs>>a)
      {
        if(removeSpecialChars(a))//διαγραφει ολους του ειδικους χαρακτηρες απο καθε λεξη και μετα την αποθηκευει στον πινακα
        {
          size+=sizeof(a);
          words[i]=a;
          i++;//αυξανουμε τον counter που μας λεει ποσα στοιχεια εχει ο πινακας
        }
      }
      ifs.close();
      return true;
   }
   else
   {
    cout<<"File Error!"<<endl;
    return false;
   }
}

int main()
{
  string* words;
  int size;
  readFile("gutenberg.txt",words,size);
    
  Array unsorted;
  Sorted sor;
  BinaryTree bt;
  AVLTree avl;
  HashTable hash;
    
    auto start = high_resolution_clock::now();
   for(int i=0;i<size;i++)
       hash.insert(words[i]);
 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout <<"Insert lasted: "<<duration.count()<<" milliseconds"<<endl;
      
    auto start2 = high_resolution_clock::now();
   for(int i=0;i<10000;i++)
     hash.search(words[i]);
    
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout <<"Search lasted: "<<duration2.count()<<" milliseconds"<<endl;

}
