#include "Array.hpp"

Array::Array()
{
   words=new string[1000];
   wordcounter=new int[1000];
   size=0;
}

void Array::insert(string a)
{
  if(uniqueString(a))
  {
    if(size%1000==0)
      moremem(sizeof(string)*(size+1000));
   words[size]=a;
   wordcounter[size]++;
   size++;
   //cout<<size<<"."<<words[size-1]<<endl;
  }
}

void Array::remove()
{
   words[size-1] = "";
   wordcounter[size-1] = 0;
   size--;
   moremem(size*sizeof(string));
}

int Array::search(string a)
{
  int i;
  i=linearsearch(a);
  return wordcounter[i];
}

bool Array::moremem(int mem)
{
  string *temp;
  int *temp2;

  temp=new string[mem];
  temp2 = new int[mem];
  
  if(temp==NULL || temp2==NULL)
    return false;

  for(int i=0;i<size;i++)
  {
    temp[i]=words[i];
    temp2[i] = wordcounter[i];
  }
  delete [] words;
  delete [] wordcounter;

  words=temp;
  wordcounter = temp2;
  return true;
}

bool Array::uniqueString(string a)
{
  for(int i=0;i<size;i++)
    if(a==words[i])
    {
      wordcounter[i]++;
      return false;
    }
  return true;
}

int Array::linearsearch(string a)
{
  int i=0;
  for(i=0;i<size;i++)
    if(words[i]==a)
      return i;
    return -1;
}

int Array::getSize()
{
  return size;
}

string& Array::operator[](int pos)
{
  return words[pos];
}

int Array::getwc(int i)
{
  return wordcounter[i];
}

