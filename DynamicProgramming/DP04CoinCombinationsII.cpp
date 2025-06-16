/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

2+2+5
3+3+3
2+2+2+3

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
Constraints

1 \le n \le 100
1 \le x \le 10^6
1 \le c_i \le 10^6

Example
Input:
3 9
2 3 5

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
    int n, x, mod = 1e9+7; 
    cin>>n>>x;

    vi a(n);
    input(a);

    // vvi dp(n+1, vi (x+1, 0));
    // for(int i=0; i<n; i++) dp[i][0] = 1;

    vi prev(x+1);
    prev[0] = 1;
    
    for(int i=n-1; i>=0; i--) {
        vi cur(x+1);
        cur[0] = 1;
        for(int j = 1; j<=x; j++) {
            int skip = prev[j];

            int pick = 0;
            if(a[i] <= j) pick = cur[j- a[i]];

            cur[j] = (pick + skip)% mod;
        }
        prev = cur;
    }

    cout << prev[x] << endl;
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