#include "dictionary.h"

// ------------------------------------------------
//  IMPORTANT
// ------------------------------------------------
// You must have written dictionary.cpp for earlier problem.
// You need to use the code here again. However, there is
// a type difference in this problem. The key is a string not array.
// Please modify your code as you need.

Dictionary::Dictionary(){
      N=64;
    A=new Entry[N];
   
  
  
  // (ALMOST) COPY from the earlier dictionary problem
};


int Dictionary::hashValue(std::string key){
 long long int hashValue = 0;
    // compute hash  hash(s) = s[0] + s[1]p + s[2]p^2 . . . s[n − 1]p^{n−1}
    long long int encode=0;
    long long int p=31;
    int size=key.size();
   
    encode=key[size-1];
    for(int i=size-2;i>=0;i--){
        encode=encode*p+key[i];
    }
    double A=(sqrt(5)-1)/2;
   hashValue=floor(64*((encode*A)-floor(encode*A)));
   return hashValue;

}

int Dictionary::findFreeIndex(std::string key){
     int pp=hashValue(key);
    for(int i=pp;i!=(pp-1+64)%64;i=(i+1)%64){
        if(A[i].key.size()==0){return i;}
    }
if(A[(pp-1+64)%64].key.size()==0){return (pp-1+64)%64;}
  return -1; 
}

struct Entry* Dictionary::get(std::string key){
  int qq=hashValue(key);bool f=false;
for(int i=qq;i!=(qq-1+64)%64;i=(i+1)%64)
    {if(A[i].key.size()==0){f=true;;break;}
       if(A[i].key.size()!=0){if(A[i].key==key){return A+i;} }
    }
  if(!f&&A[(qq-1+64)%64].key.size()!=0) { if((A[(qq-1+64)%64].key==key)==0){return A+((qq-1+64)%64);}}
   
    return NULL;
}

bool Dictionary::put(Entry e){
      int index=findFreeIndex(e.key);
if(index!=-1){A[index].value=e.value;A[index].key=e.key;return true;}
return false; // Dummy return// Dummy return
}

bool Dictionary::remove(std::string key){
  Entry* xx=get(key);
if(!xx){return false;}


xx->key[1]='$';
return true; // Dummy return
}
