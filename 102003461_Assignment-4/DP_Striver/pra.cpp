#include<bits/stdc++.h>
using namespace std;

//void reverse(int l, int r,int v[],int n)
//{
//	if(l>=r)
//	{
//		for(int i=0;i<n;i++)
//		cout<<v[i]<<" ";
//		return;
//	}
//	swap(v[l],v[r]);
//	reverse(l+1,r-1,v,n);
//}
bool checkPalindrome(int l , int r,string s)
{
	if(s[l]!=s[r]) return false;
	if(l>=r) return true;
	checkPalindrome(l+1,r-1,s);
}
int main()
{
//	int v[6]={1,2,3,2,4,5};
//	int n=6;
//	reverse(0,n-1,v,n);
string s="madamv";
int n=s.length();
cout<< checkPalindrome(0,n-1,s);
}
