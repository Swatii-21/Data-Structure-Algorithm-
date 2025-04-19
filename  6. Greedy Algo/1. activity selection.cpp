#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std ; 

int maxact(vector<int> start , vector<int> end ){
    int n = start.size();
    
    // Step 1: Pair each activity's end time with start time
    vector<pair<int , int>> activities;
    for(int i =0 ; i < n ; i++){
        activities.push_back({end[i] , start[i]});
    }
    // Step 2: Sort activities by end time
    sort(activities.begin() , activities.end());
    
     // Step 3: Select the first activity
    cout << "selecting activity A0\n";
    int count = 1 ; 
    int currendtime = end[0];
     // Step 4: Check remaining activities
    for(int i = 1 ; i <n ; i++){
        if(start[i] >= currendtime){
            cout << "selecting activity A" << i << endl;
            count ++;
            currendtime= end[i];
        }
    }
    return count ; 
}

int main(){
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end  =  {2, 4, 6, 7, 9, 9};
    
    cout <<  maxact(start , end) << endl ;
     
    return 0 ; 
}