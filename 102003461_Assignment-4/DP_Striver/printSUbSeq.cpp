#include<bits/stdc++.h>
using namespace std;
void printSub(int index, vector<int>&ans,int arr[],int n)
{
	
	if(index==n)
	{
		for(int i=0;i<ans.size();i++)
		{
	
			
			cout<<i<<":  "<<ans[i]<< " ";
			
		}
		
		cout<<endl;
		return;
	}
	ans.push_back(arr[index]);
	printSub(index+1,ans,arr,n);
	ans.pop_back();
	printSub(index+1,ans,arr,n);
}
int main()
{
	int arr[]={1,2,1};
	int n=3;
	vector<int>ans;
	printSub(0,ans,arr,n);
}
