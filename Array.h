class Array
{
  private:
    string *words
    int *wordcounter
    int size;
  public:
    Array();

    void insert(string);
    void remove(string);
    int  search(string);
};