 #include <iostream>
#include <vector>
using namespace std;

// Function to find the minimum number of coins needed to make amount V
int getminchange(vector<int> coins, int V) {
    int ans = 0;
    int n = coins.size();

    // Iterate over coins from largest to smallest
    for (int i = n - 1; i >= 0 && V > 0; i--) {
        if (V >= coins[i]) {
            // Use as many coins of denomination coins[i] as possible
            ans += V / coins[i];
            V = V % coins[i]; // Update the remaining amount
        }
    }
    cout << "min coins for change = " << ans << endl;
    return ans;
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000}; // Coin denominations
    int V = 590; // Amount to make change for
    getminchange(coins, V);
    return 0;
}
