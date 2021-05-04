#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include "Array.h"
using namespace std;

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
    if(size(a)==0)            //αν η λέξη που εισάγαμε με αναφορά αποτελείται μόνο από ειδικούς χαρακτήρες - και συνεπώς
      return false;           //έχει διαγραφεί ολόκληρη, επιστρέφουμε false καθώς δεν υπάρχει συμβολοσειρά προς 
    return true;              //αποθήκευση. Ειδάλλως επιστρέφουμε true.
}

bool readFile(string filename,string* &words,int &i)
{
   string a;
   int size=0;
   i=0;
   words=nullptr;
   ifstream ifs;
   ifs.open(filename);
   if(ifs.is_open())
   {
      while(ifs>>a)
      {
        if(removeSpecialChars(a))
        {
          size+=sizeof(a);
          words=(string *)realloc(words,size);
          words[i]=a;
          i++; 
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
  readFile("Project.txt",words,size);

  Array unsorted;
  for(int i=0;i<size;i++)
    unsorted.insert(words[i]);
  for(int i=0;i<50;i++)
    cout<<"The word "<<words[i]<<" was found "<<unsorted.search(words[i])<<" times"<<endl;
}  


