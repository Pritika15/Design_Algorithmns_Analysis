#include<cstdio>
#include<iostream>
#include<ios>
    using namespace std;
    typedef unsigned long long ll;

    int check(ll side, ll w, ll h, ll n) {
        if((side/h) * (side/w) >= n) return 1;
        else return 0;
    }

    int main() {    

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t = 0;
        cin >> t;
        while(t--) {
            ll n = 0, w = 0, h = 0;
            cin >> n >> h >> w;

            ll area = n * w * h;

            ll mx = 0;
            mx = max(h, w) * n;
            ll mn = 0;
            // cout << mx < mn + 1) {
                ll mid = (mx + mn)/2;
                if(check(mid, w, h, n)) {
                    mx = mid;
                }
                else mn = mid;
                //cout << mx << " " << mn << endl;
            
            cout << mx << endl;
        }

        return 0;
    }
