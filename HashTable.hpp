#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

class pairs//κλαση που αναπαριστα την εννοια του ζευγαριου
{
  public:
    string word;
    int counter;
    unsigned long long int key;
    pairs(string a,unsigned long long int b)
    {
      word=a;
      key=b;
      counter=1;
    }
};

class HashTable
{
  private:
    int maxsize;//μεταταβλητη που μας δειχνει το παρον μεγιστο μεγεθος του πινακα
    int size;//μεταβλητη που ως τιμη εχεις τα στοιχεια του πινακα
    pairs **hash;//δυναμικος πινακας που αποθηκευει δεικτες που δειχνουν σε pair
    int hashfunc(unsigned long long int);//συναρητση κατακερματισμου
    int hashco(int);//συναρτηση κατακερματισμου σε περιπτωση συγκρουσης
    bool insert(string,unsigned long long int);//συναρτηση που καλειται απο την public insert
    pairs* search(string,unsigned long long int);//συναρτηση που καλειται απο την public search
    unsigned long long int stringkey(string);//συναρτηση που μετατρεπει ενα string σε αριθμο και το χρησιμοποιουμε ως κλειδι για ολες τις εισαγωγες και αναζητησεις
  public:
    HashTable();//κατασκευαστης της κλασης οπου αρχικοποιουμε ολες τις μεταβλητες
    ~HashTable();//καταστροφες που διαγραφει απο την μνημη τους πινακες
    void insert(string);//συναρτηση που υλοποιει την εισαγωγη ενος στοιχειου στον πινακα κατακερματισμου
    bool search(string);//συναρτηση που υλοποιει την αναζητηση ενος στοιχειου
};

