#include "Sorted.hpp"

Sorted::Sorted()
{
  words=new string[1000];
  wordcounter=new int[1000];
  size=0;
}

Sorted::~Sorted()
{
  delete[] words;
  delete[] wordcounter;
  size = 0;
}

void Sorted::remove()
{
   words[size-1] = "";
   wordcounter[size-1] = 0;
   size--;
   moremem(size*sizeof(string));
}

int Sorted::search(string a)
{
  int i;
  i=binarysearch(0,size,a);
  return wordcounter[i];
}

bool Sorted::moremem(int mem)
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
    temp2[i] =wordcounter[i];
  }
  delete [] words;
  delete [] wordcounter;

  words=temp;
  wordcounter = temp2;
  return true;
}

int Sorted::binarysearch(int left,int right,string a)
{
   int mid;
   if(right>=left)
   {
      mid=left+(right-left)/2;
      if(words[mid]==a)
         return mid;
      if(words[mid]>a)
         return binarysearch(left,mid-1,a);
       
         return binarysearch(mid+1,right,a);
   }
   return left;
}

void Sorted::setwordcounter(int pos, int value)
{
  wordcounter[pos]=value;
}

 
string& Sorted::operator[](int pos)
{
  return words[pos];
}

int Sorted::getSize()
{
  return size;
}

string * Sorted::getWords()
{
  return words;
}

int* Sorted::getWordcounter()
{
  return wordcounter;
}


void Sorted::insertS(string element_to_insert)
{
  int a;
  a=binarysearch(0, size-1,element_to_insert);
  for(int i=size-1;i>=a;i--)
  {
     words[i+1]=words[i];
     wordcounter[i+1]=wordcounter[i];
  }
  words[a]=element_to_insert;
  wordcounter[a]=1;
  size++;
}

void Sorted::insert(string a)
{
  
  if(uniqueString(a))
  {
   if(size%1000==0)
      moremem(sizeof(string)*(size+1000));
    insertS(a);
  }
  //cout<<size<<"."<<words[size]<<endl;*/
}

bool Sorted::uniqueString(string a)
{
  int pos=binarysearch(0,size,a);
    if(a==words[pos])
    {
      wordcounter[pos]++;
      return false;
    }
  return true;
}

