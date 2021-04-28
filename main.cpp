#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
using namespace std;

bool removeSpecialChars(string& a)
{
  for(int i=0;i<a.size();i++)
    {
      if(a[i]>=65 && a[i]<=92)
      {
         a[i] += 32;
      } 
      
      if(a[i]>122 || a[i]<97) 
       {
        
         a.erase(a.begin()+i);
         --i;
       }
    } 
    if(size(a)==0)
      return false;
    return true;
}

int main()
{
   string *words,a;
   int i=0,size=0;
   words=nullptr;
   ifstream ifs;
   ifs.open("b.txt");
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
   }
   else
   {
    cout<<"File Error!"<<endl;
   }
   for(int j=0;j<i;j++)
     cout<<words[j]<<endl;
}  
