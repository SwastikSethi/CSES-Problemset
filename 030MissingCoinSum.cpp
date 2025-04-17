/*
You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?
Input
The first line has an integer n: the number of coins.
The second line has n integers x_1,x_2,\dots,x_n: the value of each coin.
Output
Print one integer: the smallest coin sum.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9

Example
Input:
5
2 9 1 2 7

Output:
6
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
    int n; cin>>n;
    vi a(n);
    input(a);

    sorta(a);

    int cur = 1;
    for(auto i:a){
        if(cur < i) break;
        cur += i; 
    }

    cout << cur << endl;
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