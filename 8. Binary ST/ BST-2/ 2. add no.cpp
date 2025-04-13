#include <iostream>
using namespace std;


// Function to add two numbers
int addTwoNumber(int a, int b)
{
    // Return sum of a and b
    int sum = a + b;
    return sum;
}
 
// Driver Code
int main()
{
    // Given two number
    int a = 3, b = 2;
 
    // Function call
    cout << "sum of " <<a<<" and "<<b<< " = "<< addTwoNumber(a, b)<<endl;
    cout << "sum of " <<799<<" and "<<1<< " = "<< addTwoNumber(799, 1)<<endl;
    return 0;
}