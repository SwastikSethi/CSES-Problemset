/*
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?
Input
The first input line has an integer n: the number of customers.
After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.
You may assume that all arrival and leaving times are distinct.
Output
Print one integer: the maximum number of customers.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a < b \le 10^9

Example
Input:
3
5 8
2 4
3 9

Output:
2
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int,int>>
#define sorta(v) sort(v.begin(), v.end())
#define sortr(v) sort(v.rbegin(), v.rend())
#define all(v) v.begin(), v.end()
#define input(v) for(auto &i:v) cin>>i
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

void solve(){
    int n;cin>>n;
    vii a;

    for(int i=0; i<n; i++ ){
        int x;
        cin>>x;
        a.push_back({x,1});
        cin>>x;
        a.push_back({x,-1});
    }
    
    sort(all(a));
    
    int cur =0 ,ans = 0;
    for(auto i:a){
        cur += i.second;
        ans = max(cur, ans);
    }
    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}