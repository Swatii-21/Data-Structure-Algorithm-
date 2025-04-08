#include<iostream>
using namespace std;
  

//tske input and print the array 
// int main (){
//   int arr [5]  ;
//   int n = sizeof(arr) / sizeof(int);
   
//    cout << "enter elemnt " ;

//    for(int i = 0; i < 5 ; i++){
//     cin >> arr[i];
//    }
//    cout << "the array elements are : ";
//    for(int i = 0 ; i< 5 ; i++){
//     cout << arr[i] << " ";
//    }
//    return 0 ;
// }

//larghest in an marry 
 int main (){
    int arr [5] = { 5 , 4 , 9 , 3 , 1} ;
    int n = sizeof(arr) / sizeof(int);
    
    int max = arr[0] ; 
    for ( int i = 0 ; i < n ; i++) {
        if(arr[i]>max) {
             max = arr[i];
        }
    }
    cout << "laregest elemnt is : " <<  max << endl ;
   
 }

