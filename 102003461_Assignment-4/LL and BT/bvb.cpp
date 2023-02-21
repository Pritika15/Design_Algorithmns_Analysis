#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>nums;
	for(int k=0;k<nums.size();k++)
	{
		cin>>nums[k];
	}
	
	
	int d=2;
	for(int i=nums.size()-1;i>=0;i--)
	{
		int count=d;
		int j=0;
		while(count!=0)
		{
			j=i;
			j--;
			count++;
		}
		nums[j]=nums[i];
	}
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<" ";
	}
	
}
