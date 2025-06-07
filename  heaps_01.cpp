#include<iostream>
#include<queue>
using namespace std ; 

//max heap 
/*int main(){
    priority_queue<int> pq;
    
    pq.push(5);
    pq.push(10);
    pq.push(9);
    pq.push(7);
    pq.push(3);
    
    while(!pq.empty()){
        cout << "top : " << pq.top() << endl ; 
        pq.pop();
    }
    
    return 0 ; 
}
*/

//min heap 
int main(){
    priority_queue<int , vector<int> , greater<int>> pq;
    
    pq.push(5);
    pq.push(10);
    pq.push(9);
    pq.push(7);
    pq.push(3);
    
    while(!pq.empty()){
        cout << "top : " << pq.top() << endl ; 
        pq.pop();
    }
    
    return 0 ; 
    
}