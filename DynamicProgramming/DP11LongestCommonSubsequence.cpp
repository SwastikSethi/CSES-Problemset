/*
Given two arrays of integers, find their longest common subsequence.
A subsequence is a sequence of array elements from left to right that can contain gaps. A common subsequence is a subsequence that appears in both arrays.
Input
The first line has two integers n and m: the sizes of the arrays.
The second line has n integers a_1,a_2,\dots,a_n: the contents of the first array.
The third line has m integers b_1,b_2,\dots,b_m: the contents of the second array.
Output
First print the length of the longest common subsequence.
After that, print an example of such a sequence. If there are several solutions, you can print any of them.
Constraints

1 \le n,m \le 1000
1 \le a_i, b_i \le 10^9

Example
Input:
8 6
3 1 3 2 7 4 8 2
6 5 1 2 3 4

Output:
3
1 2 4
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
    int n, m; cin>>n>>m;
    vi a(n), b(m);

    input(a);
    input(b);

    vvi dp(n+1, vi(m+1));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i=n, j= m;
    vi  res;
    int cur = dp[i][j];
    while(i>0 && j > 0) {
        if(cur == 0) break;
        while(j>0 && dp[i][j-1] == cur) j--;
        while(i>0 && dp[i-1][j] == cur) i--;

        res.push_back(a[i-1]);
        cur--;
        if(cur == 0) break;
        else if(cur && j>0 && dp[i][j-1] == cur) j--;
        if(cur && i>0 && dp[i-1][j] == cur) i--;
        else break;
    }

    // for(auto i:dp) {for(auto j:i) cout << j << " "; cout << endl;}

    cout << dp[n][m] << endl;
    reverse(all(res));
    if(res.size()) for(auto i:res) cout << i << " "; cout << endl;
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