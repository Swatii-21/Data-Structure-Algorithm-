#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<int , string> m;
    
    m[101] = "rahul";
    m[110] = "neha";
    m[131] = "rahul";
    
    m[101] = "rajat"; //purani value update ho jayegi aur print rajat hoga 
     
     //rahul same map mei jaakr store honge 
     cout << m[101] <<endl;
     cout << m[10] <<endl;
     
     for(auto it : m ){
         cout << "key = " << it.first << " , " << "value = " << it.second << endl; 
     }
     return 0;
     
    
}