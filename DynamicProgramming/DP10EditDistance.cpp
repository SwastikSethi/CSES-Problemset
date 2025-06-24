/*
The edit distance between two strings is the minimum number of operations required to transform one string into the other.
The allowed operations are:

Add one character to the string.
Remove one character from the string.
Replace one character in the string.

For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.
Your task is to calculate the edit distance between two strings.
Input
The first input line has a string that contains n characters between A–Z.
The second input line has a string that contains m characters between A–Z.
Output
Print one integer: the edit distance between the strings.
Constraints

1 \le n,m \le 5000

Example
Input:
LOVE
MOVIE

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
    string s, t;
    cin>>s>>t;

    int n = s.size(), m = t.size();

    vvi dp(n+1, vi(m+1));

    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int i=0; i<=m; i++) dp[0][i] = i;

    for(int i=1; i<=n; i++) {

        for(int j = 1; j<=m; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else if(s[i-1] != t[j-1]) {
                
                // add in s
                int op1 = 1+dp[i][j-1];
                // add in t
                int op2 = 1+dp[i-1][j];
                
                //remove in s
                int op3 = 1+dp[i-1][j];
                //remove in t
                int op4 = 1+dp[i][j-1];

                //replace
                int op5 = 1+dp[i-1][j-1];

                dp[i][j] = min({op1,op2,op3,op4,op5});
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