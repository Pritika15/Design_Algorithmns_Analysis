#include <bits/stdc++.h>
using namespace std;

class customers{
  public:
  int s;
  int f;
  int comp;
  
  customers(){}
  customers(int a, int b, int c){
      s=a;
      f=b;
      comp = c;
  }
};

bool comparator(customers c1, customers c2){
    if (c1.comp == c2.comp) return c1.f < c2.f;
    return c1.comp < c2.comp;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    customers* customer= new customers[n];
	    
	    for(int i=0; i < n; i++){
	        cin >> customer[i].s;
	        cin >> customer[i].f;
	        cin >> customer[i].comp;
	    }
	    
	    sort(customer , customer + n, comparator);
	    
	   // for(int i=0; i < n; i++){
	   //     cout << customer[i].s <<" "<< customer[i].f <<" " <<customer[i].comp<<endl;
	   // }
	    
	    int count= (n>0) ? 1 : 0;
	    int j=0;
	    for(int i=1; i<n; i++){
	        if(customer[i].comp != customer[j].comp) {
	            count++;
	            j=i;
	        }
	        else if(customer[i].s >= customer[j].f){
	          count++;
	          j=i;
	        }
	    }
	    
	    cout << count << endl;
	    
	}
	
	return 0;
}








