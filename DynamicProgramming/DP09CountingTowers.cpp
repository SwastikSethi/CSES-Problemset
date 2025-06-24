/*
Your task is to build a tower whose width is 2 and height is n. You have an unlimited supply of blocks whose width and height are integers.
For example, here are some possible solutions for n=6:

Given n, how many different towers can you build? Mirrored and rotated towers are counted separately if they look different.
Input
The first input line contains an integer t: the number of tests.
After this, there are t lines, and each line contains an integer n: the height of the tower.
Output
For each test, print the number of towers modulo 10^9+7.
Constraints

1 \le t \le 100
1 \le n \le 10^6

Example
Input:
3
2
6
1337

Output:
8
2864
640403945
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

const int N = 1e6+2;
vvi dp(N, vi (2));
const int mod = 1e9+7;

void dpp(){
    dp[1][0] = dp[1][1] = 1;

    for(int i=2; i<N; i++) {
        dp[i][0] = ((4LL * dp[i-1][0])%mod + dp[i-1][1])%mod;
        dp[i][1] = ((2LL * dp[i-1][1])%mod + dp[i-1][0])%mod;
    }
}

void solve(){
    int n; cin>>n;

    cout << (dp[n][0]+dp[n][1] )%mod << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    dpp();
    while(t--){
        solve();
    }
}