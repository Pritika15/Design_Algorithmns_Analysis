#include<bits/stdc++.h>
using namespace std;
void SubseqKsum(int index, vector<int>&ans,int arr[],int n,int k,int sum)
{
	
	if(index==n)
	{
		
		//int count=0;
		if(sum==k)
		{
			for(int i=0;i<ans.size();i++)
			{
				cout<<ans[i]<<" ";
			}
			cout<<endl;
			
		}
		return;
	}
	ans.push_back(arr[index]);
	sum+=arr[index];
	SubseqKsum(index+1,ans,arr,n,k,sum);
	ans.pop_back();
	sum-=arr[index];
	SubseqKsum(index+1,ans,arr,n,k,sum);
}
int main()
{
	int arr[]={1,2,1};
	int n=3;
	int k=2;
	int sum=0;
	vector<int>ans;
	SubseqKsum(0,ans,arr,n,k,sum);
}
