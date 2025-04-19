/*
Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
Input
The first input line has an integer n: the size of the array.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Output
Print one integer: the maximum subarray sum.
Constraints

1 \le n \le 2 \cdot 10^5
-10^9 \le x_i \le 10^9

Example
Input:
8
-1 3 -2 5 3 -5 2 2

Output:
9
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
    
    int cur = 0, ans = LLONG_MIN;
    for(auto i:a){
        cur += i;
        ans = max(ans, cur);
        if(cur < 0) cur = 0;
    }

    cout << ans <<endl;
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