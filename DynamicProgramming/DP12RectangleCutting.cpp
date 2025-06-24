/*
Given an a \times b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?
Input
The only input line has two integers a and b.
Output
Print one integer: the minimum number of moves.
Constraints

1 \le a,b \le 500

Example
Input:
3 5

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
    int n, m;
    cin>>n>>m;

    vvi dp(n+1, vi(m+1, 1e9));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++){

            if(i==j) dp[i][j] = 0;

            for(int k=1; k<i; k++ ) {
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
            }

            for(int k=1; k<j; k++) {
                dp[i][j] = min(dp[i][j], 1+dp[i][k] + dp[i][j-k]);
            }
        }
    }

    cout << dp[n][m] << endl;
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