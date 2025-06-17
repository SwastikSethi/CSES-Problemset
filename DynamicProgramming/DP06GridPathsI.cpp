/*
Consider an n \times n grid whose squares may have traps. It is not allowed to move to a square with a trap.
Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
Input
The first input line has an integer n: the size of the grid.
After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.
Output
Print the number of paths modulo 10^9+7.
Constraints

1 \le n \le 1000

Example
Input:
4
....
.*..
...*
*...

Output:
3
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
    
    vector<string> a(n);
    input(a);

    vvi dp(n+1, vi (n+1, 0));
    const int mod = 1e9+7;

    dp[0][0] = 1;
    if(a[0][0] == '*') dp[0][0] = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(a[i][j] == '*') continue;
            if(i>0) dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
            if(j>0) dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
        }
    }
    cout << dp[n-1][n-1] << endl;
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