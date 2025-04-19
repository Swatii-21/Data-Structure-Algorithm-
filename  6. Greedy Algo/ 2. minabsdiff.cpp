#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
	vector<int>A = {4 , 1 , 8 , 7 };
	vector<int>B = {2 , 3 , 4 , 5 };
	
	sort(A.begin() , A.end());
	sort(B.begin() , B.end());
	
	int absDiff = 0 ;
	 int n = A.size(); 
	
	for(int i = 0 ; i< n ; i++){
	    absDiff += abs(A[i]-B[i]);
	}
	
	cout << "MIN abs diff = " << absDiff << endl;
	return 0 ; 
	

}
