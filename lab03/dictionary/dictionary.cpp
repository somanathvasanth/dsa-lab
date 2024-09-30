#include "dictionary.h"

Dictionary::Dictionary(){
    N=64;
    A=new Entry[N];
    for(int i=0;i<64;i++){
        A[i].key=nullptr;
    }
    };


int Dictionary::hashValue(char key[]){
    long long int hashValue = 0;
    // compute hash  hash(s) = s[0] + s[1]p + s[2]p^2 . . . s[n − 1]p^{n−1}
    long long int encode=0;
    long long int p=31;
    int size=0;
    for(int i=0;key[i]!='\0';i++){
        size=size+1;
    }
    encode=key[size-1];
    for(int i=size-2;i>=0;i--){
        encode=encode*p+key[i];
    }
    // Used to map a key to an index in the hash table. We use
//
//           h(k) = ⌊ m {kA} ⌋
double A=(sqrt(5)-1)/2;
   hashValue=floor(64*((encode*A)-floor(encode*A)));
   return hashValue;
}

int Dictionary::findFreeIndex(char key[]){
    int pp=hashValue(key);
    for(int i=pp;i!=(pp-1+64)%64;i=(i+1)%64){
        if(A[i].key==nullptr){return i;}
    }
if(A[(pp-1+64)%64].key==nullptr){return (pp-1+64)%64;}
  return -1;   
}

struct Entry* Dictionary::get(char key[]){
int qq=hashValue(key);bool f=false;
for(int i=qq;i!=(qq-1+64)%64;i=(i+1)%64)
    {if(!A[i].key){f=true;;break;}
       if(A[i].key){if(strcmp(A[i].key,key)==0){return A+i;} }
    }
  if(!f&&A[(qq-1+64)%64].key) { if(strcmp(A[(qq-1+64)%64].key,key)==0){return A+((qq-1+64)%64);}}
   
    return NULL;
}

bool Dictionary::put(Entry e) {
   
    int index=findFreeIndex(e.key);
if(index!=-1){A[index].value=e.value;A[index].key=new string(1);strcpy(A[index].key,e.key);return true;}
return false; // Dummy return
}

bool Dictionary::remove(char key[]){
Entry* xx=get(key);
if(!xx){return false;}


xx->key[1]='$';
return true;
}
