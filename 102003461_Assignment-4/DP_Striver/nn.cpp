#include <iostream>
#include<bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
   vector<int>v;
   for(int i=0;i<4;i++)
   {
   	int x;
   	cin>>x;
   	v.push_back(x);
   }
   unordered_map<int,int> m1;
   unordered_map<int,int> m2;
   vector<int>ans;
   for(int i=0;i<v.size();i++)
   {
       if(m1.find(v[i])!=m.end())
       {
           int x=i-m1[v[i]];
           m2[v[i]]=x;
       }
       m1[v[i]]=i;
   }
   for(int i=0;i<v.size();i++)
   {
       if(m.find(v[i])!=m.end())
       {
           ans.push_back(m[v[i]]);
       }
       else
       {
           ans.push_back(0);
       }
   }
   for(auto x:ans)
   cout<<x<<" ";

    return 0;
}
