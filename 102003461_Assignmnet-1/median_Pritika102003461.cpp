#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    for(int k=0;k<n-2;k++)
    { int min=999;
    for(int i=0;i<arr.size();i++)
    {
        int count=0;
        for(int j=i;j<arr.size();j++)
        {
            count++;
            if(count>2 && count%2!=0)
            {
                vector<int>v;
                for(int k=i;k<=j;k++)
                {
                    v.insert(v.begin(),arr[k]);
                }
                    sort(v.begin(),v.end());
                    int mid = v.size()/2; // index
                    if(min>v[mid]) min=v[mid];
            }
        }
    }
    //cout<<min;
    auto it = find(arr.begin(),arr.end(),min);
    //cout<<*it;
    arr.erase(it);
    // for(int i=0;i<arr.size();i++)
    // {
    //     cout<<arr[i];
    // }
    }
    //cout<<arr.size();
    // for(int i=0;i<arr.size();i++)
    // {
    //     cout<<arr[i];
    // }
    cout<<accumulate(arr.begin(),arr.end(),0);
}