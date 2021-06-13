#include "HashTable.hpp"

HashTable::HashTable()
{
  maxsize=10000;
  size=0;
  hash=new pairs*[maxsize];
  for(int i=0;i<maxsize;i++)
    hash[i]=nullptr;
}

HashTable::~HashTable()
{
  for(int i=0;i<size;i++)
    delete hash[i];
   delete[] hash;
   maxsize=0;
   size=0;
}

unsigned long long int HashTable::stringkey(string a)
{
   unsigned long long int sum=0;
   for (int i=0;i<a.length();i++)
        sum+=((a[i]-96)*1013)*i;
      return sum;
}

bool HashTable::insert(string word,unsigned long long int key)
{
  
   if(search(word,key))
  {
    int index=hashfunc(key);
    while(hash[index]->word!=word)
        index=hashco(index);
    hash[index]->counter++;
    return false;
  }

  if(size>=maxsize/2)
  {
    pairs **temp;
    maxsize=maxsize*2;
    temp=new pairs*[maxsize];
    for(int i=0;i<maxsize;i++)
       temp[i]=nullptr;
    for(int i=0;i<maxsize/2;i++)
    {
      if(hash[i]!=nullptr)
      {
        int index=hashfunc(hash[i]->key);
        while(temp[index]!=nullptr)
          index=hashco(index);
        temp[index]=hash[i];
        hash[i]=nullptr;
      }
    }
    delete [] hash;
    hash=temp;
  }
  int index=hashfunc(key);
  while(hash[index]!=nullptr)
    index=hashco(index);
  hash[index]=new pairs(word,key);
  size++;
  //cout<<hash[index]->word<<"  "<<size<<endl;
  return true;
}

void HashTable::insert(string a)
{
    (insert(a,stringkey(a)));
}

pairs* HashTable::search(string word,unsigned long long int key)
{
   int index=hashfunc(key);
   while(hash[index]!=nullptr  && hash[index]->word!=word)
      index=hashco(index);
    return hash[index];
}

bool HashTable::search(string word)
{
  pairs* temp=search(word,stringkey(word));
  if(temp==nullptr)
    return false;
  // cout<<"The word "<<"\""<<word<<"\""<<" was found "<<temp->counter<<" times"<<endl;
   return true;
}

int HashTable::hashfunc(unsigned long long int key)
{
  return key%maxsize;
}

int HashTable::hashco(int index)
{
  return (index+1)%maxsize;
}

