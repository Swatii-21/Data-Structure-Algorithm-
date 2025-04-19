 #include <bits/stdc++.h>
using namespace std;

// Custom comparator to sort pairs based on their second value (end time)
bool compare(pair<int,int> p1 , pair<int , int> p2){
    // Sort in ascending order of the second element
    return p1.second < p2.second;
}

// Function to find the maximum length of chain that can be formed
int maxchainlength(vector<pair<int,int>> pairs){
    int n = pairs.size();
    
    // Sort the pairs using the custom comparator
    sort(pairs.begin(), pairs.end(), compare);

    // At least one pair will always be in the chain
    int ans = 1;

    // Track the end time of the last included pair
    int currEnd = pairs[0].second;
    
    // Traverse the rest of the pairs
    for(int i = 1; i < n; i++){
        // If the current pair starts after the last included pair ends
        if(pairs[i].first > currEnd){
            ans++; // Include this pair in the chain
            currEnd = pairs[i].second; // Update the end to current pair's end
        }
    }
    
    // Print the result
    cout << "Max chain length: " << ans << endl;
    return 0; 
}

int main() {
    int n = 5;

    // Initialize a vector of 5 pairs with dummy values
    vector<pair<int, int>> pairs(n, make_pair(0, 0));

    // Assign actual values to each pair
    pairs[0] = make_pair(5 , 24);
    pairs[1] = make_pair(39 , 60);
    pairs[2] = make_pair(5 , 28);
    pairs[3] = make_pair(27 , 40);
    pairs[4] = make_pair(50 , 90);
   
    // Call the function to get max chain length
    maxchainlength(pairs);

    return 0;
}
