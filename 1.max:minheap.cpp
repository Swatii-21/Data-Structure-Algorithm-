#include<iostream>
#include<string>
#include<vector>
using namespace std ; 

class Heap{
    vector<int> vec; //CBT 
    
public:
//max heap 
    void push(int val){
      //step 1 
      vec.push_back(val);
      
      //fix Heap
      int x = vec.size()-1;
      int parI = (x-1)/2;
      
      while(parI >= 0 && vec[x] > vec[parI]){
          swap(vec[x] , vec[parI]);
          x= parI;
          parI = (x-1)/2;
      }
    }
    
//min heap 
    void push(int val){
      //step 1 
      vec.push_back(val);
      
      //fix Heap
      int x = vec.size()-1;
      int parI = (x-1)/2;
      
      while(parI >= 0 && vec[x] < vec[parI]){
          swap(vec[x] , vec[parI]);
          x= parI;
          parI = (x-1)/2;
      }
    }
    
    void pop(){
        
    }
    
    int top(){
        return vec[0]; //highest prirotiy element 
    }
    
    bool empty(){
        return vec.size() == 0 ;
    }
    
};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);
    
    cout << "top = " << heap.top() << endl;
    return 0 ; 
  
}
