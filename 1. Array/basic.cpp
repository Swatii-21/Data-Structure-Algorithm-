#include<iostream>
using namespace std;


/*
    int arr[25] = {7,5,2,1,3};
    int n = sizeof(arr)/sizeof(int);

    for(int i=0;i<n ; i++){
        cout << arr[i] <<" ";
    }

    cout << endl;
    return 0 ; 
}
*/

/*int main (){
    int arr[5] ;
    int n = sizeof(arr)/ sizeof(int);

    for (int i =0 ; i< n ;i++){
        cin >> arr[i];
    }

    for(int i = 0 ; i <n ;i++){
        cout << arr[i] << " , ";
    }

    cout << endl;
    return 0 ; 
}
    */

//array are passed by refernce 

/*void func1(int arr[]){
    arr[0]= 1000;
}

void func2(int *ptr){
    ptr[0]= 1000;
}

int main(){
    int a = 5;
    int *ptr = &a;
    cout << ptr << endl;

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    func1(arr); //passing array name is eq. to passing the pointer 
    cout << arr[0] << endl;
    return 0;


}
*/

//LINEAR SEARCH 
 /*int linsea(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Return the index if the key is found
        }
    }
    return -1;  // Return -1 if the key is not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};

    int n = sizeof(arr) / sizeof(int); // Calculate number of elements

    cout << linsea(arr, n, 20) << endl; // Searching for 20 (not in array)

    return 0;
}
*/
//REVERSE AN ARRAY 

//with extra space 
/*void printarr(int *arr , int n ){
    for (int i =0 ; i< n ; i++){
        cout << arr[i] << " , ";
    }
    cout << endl;
}
 int main(){
    int arr[]= {5,4,3,9,2};
    int n = sizeof(arr)/sizeof(int);

    int copyarr[n];
    for(int i =0 ; i<n ; i++){
        int j = n- i -1;
        copyarr[i] = arr[j];
    }

    printarr(copyarr , n);
    return 0;
 }
    */

//without extra space 
void printarr(int *arr , int n ){
    for (int i =0 ; i< n ; i++){
        cout << arr[i] << " , ";
    }
    cout << endl;
}

int main (){
int arr [] = { 5 , 4 , 3 , 9 , 2};
int n = sizeof(arr)/sizeof(int);

int start = 0; int end = n-1;

while(start <end){
    int temp = arr[start];
    arr[start]= arr[end];
    arr[end] = temp ; 

    start ++ ;
    end --;
}
printarr(arr , n );
return 0 ; 
}
 
