
#include <iostream>
using namespace std;
int BinarySearch(int arr[],int x,int l, int h)
{ int mid= l+(h-l)/2;
   if(h>=l)
   {
     if(arr[mid]==x)
     {
	   return mid;
      }
     else if(arr[mid]<x)
     {
	   return BinarySearch(arr, x,mid+1,h );
     }
     else
     {
	    return BinarySearch(arr, x,l,mid-1 );
     }

  }

	
}

int main() {
	int num;
	//cout<<"enter the size of the array:";
	cin >> num;    //Reading input from STDIN
	int arr[num];
	//cout<<"enter the elements of the array";
	for(int i=0;i<num;i++)
	{
		int y;
		cin>>y;
		arr[i]=y;
	}
	int q;
	//cout<<"Enter the number of queries to be run";
	cin>>q;
	while(q!=0)
	{
      int x;
	  cin>>x;
	 int b= BinarySearch(arr, x,0,num-1 );
	 cout<< b+1<<endl;
	  
	  q--;
	}
	//cout<<endl;
}

