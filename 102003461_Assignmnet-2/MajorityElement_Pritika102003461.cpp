#include <bits/stdc++.h>
using namespace std;
int majorityElement(const int* A, int n1) {
    // Function to find Majority element// in an array
    int maxCount = 0;
    int index = -1; // sentinels
    for (int i = 0; i < n1; i++) {
        int count = 0;
        for (int j = 0; j < n1; j++) {
            if (A[i] == A[j])
                count++;
        }
 
        // update maxCount if count of
        // current element is greater
        if (count > maxCount) {
            maxCount = count;
            index = i;
        }
    }
 
    // if maxCount is greater than n/2
    // return the corresponding element
    if (maxCount > n1 / 2)
        return A[index] ;
 
    else
        return 0;
}
 
// Driver code
int main()
{
    int A[] = { 2,1,2 };
    int n1 = sizeof(A) / sizeof(A[0]);
 
    // Function calling
    majorityElement(A, n1);
 
    return 0;
}


