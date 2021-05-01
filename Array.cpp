#include "Array.h"

Array::Array()
{
   words=new string[245000];
   wordcounter=nullptr;
   size=0;
}

void Array::insert(string a)
{
  if(uniqueString(a))
  {
   words[size]=a;
   size++;
   cout<<size<<"."<<words[size-1]<<endl;
  }
}

void Array::remove(string a)
{
   
}

int Array::search(string a)
{
  int i,count=0;
  for(i=0;i<size;i++)
  {
    if(words[i]==a)
    {
      count++;
    }
  }
  return count;
}

bool Array::moremem(int mem)
{
  string *temp;
  temp=new string[mem];
  if(temp==NULL)
    return false;
  for(int i=0;i<size;i++)
  {
    temp[i]=words[i];
  }
  delete [] words;
  words=temp;
  return true;
}

bool Array::uniqueString(string a)
{
  for(int i=0;i<size;i++)
    if(a==words[i])
      return false;
  return true;
}
