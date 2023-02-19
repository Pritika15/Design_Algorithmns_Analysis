#include<iostream>
using namespace std;
int candy(int* A, int n1) {
    // Stores total count of candies
    int sum = 0;
 
    // Stores the amount of candies
    // allocated to a student
    int ans[n1];
 
    // If the value of N is 1
    if (n1 == 1) {
        return 1;
    }
 
    // Initialize with 1 all array
    // element
    for (int i = 0; i < n1; i++)
        ans[i] = 1;
 
    // Traverse the array arr[]
    for (int i = 0; i < n1 - 1; i++) {
 
        // If arr[i+1] is greater than
        // arr[i] and ans[i+1] is
        // at most ans[i]
        if (A[i + 1] > A[i]
            && ans[i + 1] <= ans[i]) {
 
            // Assign ans[i]+1 to
            // ans[i+1]
            ans[i + 1] = ans[i] + 1;
        }
    }
 
    // Iterate until i is atleast 0
    for (int i = n1 - 2; i >= 0; i--) {
 
        // If arr[i] is greater than
        // arr[i+1] and ans[i] is
        // at most ans[i+1]
        if (A[i] > A[i + 1]
            && ans[i] <= ans[i + 1]) {
 
            // Assign ans[i+1]+1 to
            // ans[i]
            ans[i] = ans[i + 1] + 1;
        }
 
        // If arr[i] is equals arr[i+1]
        // and ans[i] is less than
        // ans[i+1]
        else if (A[i] == A[i + 1]
                 && ans[i] < ans[i + 1]) {
 
            // Assign ans[i+1]+1 to
            // ans[i]
            ans[i] = ans[i + 1] + 1;
        }
 
        // Increment the sum by ans[i]
        sum += ans[i];
    }
 
    sum += ans[n1 - 1];
 
    // Return the resultant sum
    return sum;
}

 
// Function to count the minimum number
// of candies that is to be distributed
 
// Driver Code
int main()
{
    int A[] = { 1, 2 };
    int n1 = sizeof(A) / sizeof(A[0]);
    cout << candy(A,n1);
 
    return 0;
}

