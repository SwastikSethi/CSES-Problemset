/*
You know that an array has n integers between 1 and  m, and the absolute difference between two adjacent values is at most 1.
Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.
Input
The first input line has two integers n and m: the array size and the upper bound for each value.
The next line has n integers x_1,x_2,\dots,x_n: the contents of the array. Value 0 denotes an unknown value.
Output
Print one integer: the number of arrays modulo 10^9+7.
Constraints

1 \le n \le 10^5
1 \le m \le 100
0 \le x_i \le m

Example
Input:
3 5
2 0 2

Output:
3

Explanation: The arrays [2,1,2], [2,2,2] and [2,3,2] match the description.
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
    int n; int m;
    cin>>n>>m; 
    
    vi a(n);
    input(a);

    // dp[number of prefixes till i][s.t. last element is j]
    vvi dp(n+1, vi (m+1, 0));

    for(int i=1; i<=m; i++) if(a[0] == 0 || a[0] == i) dp[1][i] = 1;

    const int mod = 1e9+7;

    auto valid = [&] (int i) {
        return i>=1 && i<= m;
    };
    for(int i = 2; i<=n; i++ ){
        for(int j = 1; j<=m ; j++) {
            if(a[i-1] != 0 && a[i-1] != j) continue;

            for(int prev = j-1; prev <= j+1; prev++) {
                if(!valid(prev)) continue;
                dp[i][j] = (dp[i][j] + dp[i-1][prev]) % mod;
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=m ;i++) ans = (ans + dp[n][i])%mod;

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