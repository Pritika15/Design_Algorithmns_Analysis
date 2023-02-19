#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // with sorting
    sort(arr,arr+n,greater<int>());
    int sum=0;
    for(int i=k;i<n;i++)
    {
        sum+=arr[i];
    }
    cout<<sum;

}