#include <iostream>

/*
In this exercise, we will implement heap as discussed in the class.
We need to implement the following functions.


ONLY THIS FILE MUST BE MODIFIED FOR SUBMISSION

You may edit main.cpp for writing more test cases.
But your code must continue to work with the original main.cpp


THERE IS ONLY ONE TEST CASE ONLY FOR YOUR UNDERSTANDING.

-- You may need to generate more random tests to get your tests right
-- Print will not work until you have a good printing function
*/


#include "heap.h"


int Heap::parent(int i) {
  
  
  return (i-1)/2; // dummy return
}

int Heap::left(int i) {
  return 2*i+1; // dummy return
}

int Heap::right(int i) {
  return 2*i+2; //dummy
}

int Heap::max() {
 return store[0];
//dummy
}

void Heap::swap(int i, int j) {
  std::swap(store[i],store[j]);
  swap_count+=1;
}

void Heap::insert(int v) {
  if(store.size()==sz){store.push_back(v);}
  else store[sz]=v;
  sz=sz+1;
}

void Heap::heapify(int i) {
  int indexmax=i;
  if(right(i)<sz&&store[left(i)]>store[right(i)]){indexmax=left(i);}
  else if(right(i)<sz&&store[right(i)]>store[left(i)]){indexmax=right(i);}
  else if(right(i)>sz-1&&left(i)>sz-1){return;}
  else if(right(i)>sz-1){if(store[i]<store[left(i)]){indexmax=left(i);}}
  if(store[i]<store[indexmax]){swap(i,indexmax);
  heapify(indexmax);}
 }


void Heap::deleteMax() {
swap(0,sz-1);
  sz-=1;
  heapify(0);
}

void Heap::buildHeap() {
  for(int i=sz-1;i>=0;i--){heapify(i);}
}

void Heap::heapSort() {
  int q=sz;
  for(int i=0;i<q;i++){
    deleteMax();
  }
}


