#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 

class Jobs{
    public:
    int idx ; 
    int deadline ; 
    int profit;
    
    Jobs(int idx , int deadline ,  int profit){
        this-> idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};
 
 

int maxprofit(vector<pair<int,int>> pairs){
     int n = pairs.size();
     vector<Jobs>jobs;
     
     for(int i = 0 ; i<n ; i++){
         jobs.emplace_back(i , pairs[i].first , pairs[i].second) ;//idx , deadlien , profit
     }
     
     sort(jobs.begin() , jobs.end() , [](Jobs &a, Jobs &b){
         return a.profit>b.profit;
     }); //desceidning prder on the basis of profit
     
     cout << "selecting jobs\n " << jobs[0].idx << endl;
     int profit = jobs[0].profit;
     int safedeadline = 2;
     
     for(int i = 1 ; i < n ; i++){
         if(jobs[i].deadline >= safedeadline){
             cout << "selecting jobs : " << jobs[i].idx <<endl;
             profit += jobs[i].profit;
             safedeadline++;
         }
     }
     cout << "max profit " << profit << endl;
     return profit;
}

int main() {
	 int n = 4 ; 
	 vector<pair<int , int >> jobs(n,make_pair(0,0));
	 jobs[0] = make_pair(4 , 20);
	 jobs[1] = make_pair(1 , 10);
	 jobs[2] = make_pair(1 , 40);
	 jobs[3] = make_pair(1 , 30);
	 
	 maxprofit(jobs);
	 
	 return 0 ; 

}
