#include <cstring>
#include <iostream>
using namespace std;
class Array
{
  private:
    string *words;
    int *wordcounter;
    int size;
    bool moremem(int);
  public:
    Array();

    void insert(string);
    void remove(string);
    int  search(string);
};
