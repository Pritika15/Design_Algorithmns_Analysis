#include <bits/stdc++.h>
using namespace std;
#define segment pair < int , int >
const int N = 1e5 + 6;
const int OO = 1e6 + 5;
int n , q;
int sp[N][20];
bool comp1(segment a , segment b)
{
if(a.second == b.second) return a.first > b.first;
return a.second < b.second;
}
int main()
{
ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
cin >> n >> q;
vector < segment > rng, rng2;
for(int i = 0 ; i < n ; i++)
{
int st , ed; cin >> st >> ed;

rng.push_back({st , ed});
}
sort(rng.begin() , rng.end() , comp1);
int last = -1;
for(int i = 0 ; i < n ; i++)
if(rng[i].first > last)
rng2.push_back(rng[i]) , last = rng[i].first;
rng = rng2;
n = rng.size();
rng.push_back({OO , OO});
sp[n][0] = n;
for(int i = 0 ; i < n ; i++)
sp[i][0] = lower_bound(rng.begin() , rng.end() , make_pair(rng[i].second, OO)) -
rng.begin();
for(int j = 1 ; j < 20 ; j++)
for(int i = 0 ; i <= n ; i++)
sp[i][j] = sp[sp[i][j-1]][j-1];
while(q--)
{
int st , ed; cin >> st >> ed;
int idx = lower_bound(rng.begin() , rng.end() , make_pair(st , -OO)) - rng.begin();
if(rng[idx].second > ed) cout << "0\n";
else
{
int res = 1;
for(int j = 19 ; j >= 0 ; j--)
if(rng[sp[idx][j]].second <= ed)
res += (1<<j) , idx = sp[idx][j];
cout << res << '\n';
}
}
return 0;
}
