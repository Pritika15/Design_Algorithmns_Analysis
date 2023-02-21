#include<bits/stdc++.h>
using namespace std;
int KthJump(int index, int k, int height[],vector<int>&dp)
{
	if(index==0)
	return 0;
	if(dp[index]!= -1)
	return dp[index];
	int mini=INT_MAX;
	int jump1;
	for(int i=1;i<=k;i++)
	{
		if(index-i >=0)
		{
			jump1=KthJump(index-i,k,height,dp)+abs(height[index]-height[index-i]);
		    mini=min(mini,jump1);
		}
		
	}
	
	return dp[index]=min(mini,jump1);
	//return mini;
	
}
int main()
{
	int n=5;
	int k=3;
	int arr[5]={10,30,40,50,20};
//	int n=3;
//	int k=1;
//	int arr[3]={10,20,10};
//	int n=2;
//	int k=100;
//	int arr[5]={10,10};
	
	
	vector<int>dp(n, -1);
	cout<<KthJump(n-1,k,arr,dp);
}
