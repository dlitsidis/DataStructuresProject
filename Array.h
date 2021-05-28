#include <cstring>
#include <iostream>
using namespace std;
class Array
{
  private:
    string *words; //δείκτης που αποθηκεύει τις λέξεις που εισάγονται 
    int *wordcounter; //δείκτης που μετράει το πλήθος τον λέξεων που έχουν εισαχθεί
    int size; //μεταβλητή που αποθηκεύει το μεγεθος του πίνακα των λέξεων
    bool moremem(int);
    bool uniqueString(string);
    int linearsearch(string);
  public:
    Array(); //κατασκευαστής της κλάσης (αρχικοποιεί τους δείκτες σε nullptr και το μέγεθος σε 0)

    void insert(string); //συνάρτηση που υλοποιεί εισαγωγή στοιχείου στον πίνακα 
    void remove(); //συνάρτηση που υλοποιεί διαγραφή στοιχείου του πίνακα
    int  search(string); //συνάρτηση που υλοποιεί αναζήτηση στοιχείου στον πίνακα και επιστρέφει τον αριθμό εμφανίσεων  

    string &operator[](int );
    
    int getwc(int);
    int getSize();
};
