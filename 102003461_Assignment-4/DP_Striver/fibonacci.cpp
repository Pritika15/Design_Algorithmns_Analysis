#include<bits/stdc++.h>
using namespace std;
int fib(int n) {
       // Using recursion
         if(n<=1)
             return n;
         return fib(n-1)+fib(n-2);
     }
// Using Memoization: Top-Down TC: O(n) SC:O(n)+O(n) (Recursion call stack +vector)
int fibMem(int n, vector<int> &dp)
{
	if(n<=1)
	{
		return n;
	}
	if(dp[n]!= -1)
	return dp[n];
	
	return dp[n]=fibMem(n-1,dp)+fibMem(n-2,dp);       
	 
 }  
 //Using tabulation  TC:O(n) SC:O(n)
 int fibTab(int n, vector<int>&dp)
 {
 	dp[0]=0;
 	dp[1]=1;
 	for(int i=2;i<n;i++)
 	{
 		dp[i]=dp[i-1]+dp[i-2];
	 }
	 return dp[n];
  } 
  //Space Optimization: Maintain two pointers
  int fibo(int n)
  {
  	int prev2=0;
  	int prev1=1;
  	for(int i=2;i<=n;i++)
  	{
  		int curr=prev1+prev2;
  		prev2=prev1;
  		prev1=curr;
	  }
	  return prev1;
  }
  int main()
  {
  	int n=5;
  	vector<int>dp(n+1, -1);
  	cout<<"Using recursion"<<endl;
  	cout<<fib(n);
  	cout<<endl;
  	cout<<"Using Memoization"<<endl;
  	cout<<fibMem(n,dp);
  	cout<<endl;
  	cout<<"Using Tabulation"<<endl;
  	cout<<fibTab(n,dp);
  	cout<<endl;
  	cout<<"Using Space optimization"<<endl;
  	cout<<fibo(n);
  	cout<<endl;
  	
  }
