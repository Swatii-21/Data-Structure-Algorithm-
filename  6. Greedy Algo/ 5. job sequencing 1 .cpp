#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 

bool compare(pair<int , int> p1, pair<int , int>p2){
    return p1.second > p2.second ; 
}

//How compare function works:
//Hum pair (deadline, profit) ke second value (profit) ko compare karte hain.
//p1.second > p2.second ka matlab hai sort in descending order based on profit. //Agar p1 ka profit zyada hai, toh p1 ko pehle rakhna.

int maxprofit(vector<pair<int,int>> jobs){
    sort(jobs.begin() , jobs.end() , compare);
    //{(1,40), (1,30), (4,20), (1,10)}
    int profit  = jobs[0].second;  
    //40
    int safedeadline = 2;
    //Safedeadline ka kaam hai next available time slot ko track karna.
    //first -> deadline , second ->profit
    for(int i = 1 ; i<jobs.size() ; i++){
        if(jobs[i].first >= safedeadline){
            profit += jobs[i].second;
            safedeadline++;
        }
    }
    cout << "maximum profit from job  : " << profit << endl ;
    return profit ;
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
