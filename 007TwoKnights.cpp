/*
Your task is to count for k=1,2,\ldots,n the number of ways two knights can be placed on a k \times k chessboard so that they do not attack each other.
Input
The only input line contains an integer n.
Output
Print n integers: the results.
Constraints

1 \le n \le 10000

Example
Input:
8

Output:
0
6
28
96
252
550
1056
1848

https://youtu.be/uHAGgpa2qwA?feature=shared
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
    int k; cin>>k;
    for (int n = 1; n <= k; n++)
    {
        cout << ( ((n*n ) * (n*n -1)) / 2 - 4 * (n-1) * (n-2) ) << endl;
    }
    
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