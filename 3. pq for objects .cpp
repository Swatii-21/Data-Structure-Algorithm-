#include<iostream>
#include<string>
#include<vector>
#include<queue>
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
    /*void push(int val){
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
    */
    
    void heapify(int i ){
        if(i >= vec.size()){
            
            return ; 
        }
        
        int l = 2*i + 1;
        int r = 2*i + 2;
        
        int maxIdx = i ;
        if(l < vec.size() && vec[l] > vec[maxIdx]){
            maxIdx = l;
        }
        
        if(r < vec.size() && vec[r] > vec[maxIdx]){
            maxIdx = r;
        }
        
        swap(vec[i] , vec[maxIdx]);
        if(maxIdx != i){ //swapping with child node 
            heapify(maxIdx);
        }
    }
    
    
    void pop(){
       //step 1 
       swap(vec[0] , vec[vec.size()-1]);
       
       //step2 
       vec.pop_back();
       
       //step3
       heapify(0);
    }
    
    int top(){
        return vec[0]; //highest prirotiy element 
    }
    
    bool empty(){
        return vec.size() == 0 ;
    }
    
};

class Student { //"<" overload
    public:
    string name;
    int marks ; 
    
    Student(string name , int marks ){
        this -> name = name ; 
        this -> marks = marks;
    }
    
    bool operator < (const Student &obj) const {
        return this -> marks < obj.marks;
    }
};

int main(){
     priority_queue<Student> pq;
     
     pq.push(Student("AMAN",75));
     pq.push(Student("BHUMI",95));
     pq.push(Student("CHTEIN",65));
     
     while(!pq.empty()){
         cout << "top = " << pq.top().name<<" , " << pq.top().marks<< endl ; 
         pq.pop();
     }
    return 0 ; 
  
}
