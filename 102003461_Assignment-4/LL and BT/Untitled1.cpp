#include<string>
#include<iostream>
using namespace std;
int subSeq(string input,string output[])
{
	if(input.empty())
	{
		output[0]="";
		return 1;
	}
	string subString=input.substr(1);
	int smallOutput=subSeq(subString,output);
	for(int i=0;i<smallOutput;i++)
	{
		output[i+smallOutput]=input[0]+output[i];
	}
	return 2*smallOutput;
	
}
int main()
{
	string input="abc";
	string output[1000];
	int ans=subSeq(input,output);
	for(int i=0;i<ans;i++)
	{
		cout<<output[i]<<endl;
	}
}
