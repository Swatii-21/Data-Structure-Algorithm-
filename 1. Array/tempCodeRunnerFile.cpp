int  linsea(int arr[] ,int n , int key){
    
    for(int i = 0; i < n ; i++){
        if(arr[i] == key){
             return i;
        }
         
    }
    return -1 ; 
}

int main (){
    int arr[]= {2,4,6,8,10,12,14,16};

    int n = sizeof(arr) / sizeof(int);
     
     cout << linsea(arr , n , 20) << endl ; 
     return 0;
}
