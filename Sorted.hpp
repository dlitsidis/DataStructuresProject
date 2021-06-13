#include <cstring>
#include <iostream>
using namespace std;

class Sorted
{
  private:
    string *words; //δείκτης που αποθηκεύει τις λέξεις που εισάγονται
    int *wordcounter; //δείκτης που μετράει το πλήθος τον λέξεων που έχουν εισαχθεί
    int size; //μεταβλητή που αποθηκεύει το μεγεθος του πίνακα των λέξεων
    bool moremem(int);//συναρτηση που αυξανει τον χωρο του πινακα
    int binarysearch(int,int,string); //συνάρτηση που υλοποιεί την δυαδική αναζήτηση σε πίνακα συμβολοσειρών (χρησιμοποιείται για να μειώσουμε τον χρόνο αναζήτησης στον ταξινομημένο πίνακα)
    bool uniqueString(string);//συναρτηση που βρισκει αν μια συμβολοσειρα υπαρχει ηδη στον πινακα
  public:
    Sorted();//κατασκευαστής της κλάσης (αρχικοποιεί τους δείκτες σε nullptr και το μέγεθος σε 0)
    ~Sorted();
    void insert(string);
    void insertS(string); //συνάρτηση που υλοποιεί εισαγωγή στοιχείου στον πίνακα φροντίζοντας να διατηρεί την διάταξη των στοιχείων
    void remove(); //συνάρτηση που υλοποιεί διαγραφή στοιχείου του πίνακα
    int search(string);  //συνάρτηση που υλοποιεί αναζήτηση στοιχείου στον πίνακα και επιστρέφει τον αριθμό εμφανίσεων

    void setwordcounter(int,int);
    string &operator[](int);//υπερφορτωση τελεστη[] ωστε να μπορουμε να παιρνουμε πιο ευκολα τα στοιχεια του πινακα στην main συναρτηση
    int getSize();

    string* getWords();
    int* getWordcounter();
};

