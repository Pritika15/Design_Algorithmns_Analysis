
#include <iostream>
using namespace std;
int main() {
	int num;
	cout<<"enter the size of array";
	cin >> num;    //Reading input from STDIN
	//cout << "Input number is " << num << endl;	// Writing output to STDOUT
	int arr[num];
	cout<<"enter the elements of the array";
	for(int i =0;i<num;i++)
	{
		int x;
		cin>>x;
		arr[i]=x;
	}
	for(int i =0;i<num;i++)
	{
		for(int j=num-1;j>0;j--)
		{
		    while(i<j)
		    {
		        if(arr[i]>arr[j])
		        {
		          cout<<i+1;  
		        }
		    }
		}
		
	}
}

