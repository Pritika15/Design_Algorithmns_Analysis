#include <bits/stdc++.h> 
int f(int index,vector<int> &heights, vector<int>&dp)
{
     if(index==0)
        return 0;
    if(dp[index]!= -1)
        return dp[index];
    int jump1=f(index-1,heights,dp)+abs(heights[index]-heights[index-1]);
   int jump2=INT_MAX;
    if(index>1)
    {
        jump2=f(index-2,heights,dp)+abs(heights[index]-heights[index-2]);
    }
     return dp[index]= min(jump1,jump2);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n+1, -1);
   return f(n-1,heights,dp);
    
}
//Tabulation
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n, -1);
//    return f(n-1,heights,dp);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int jump1=dp[i-1]+abs(heights[i]-heights[i-1]);
         int jump2=INT_MAX;
        if(i>1)
        {
             jump2=dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        
        dp[i]=min(jump1,jump2);
    }
    return dp[n-1];
    
}
