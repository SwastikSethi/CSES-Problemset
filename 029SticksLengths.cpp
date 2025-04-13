/*
There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.
What is the minimum total cost?
Input
The first input line contains an integer n: the number of sticks.
Then there are n integers: p_1,p_2,\ldots,p_n: the lengths of the sticks.
Output
Print one integer: the minimum total cost.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le p_i \le 10^9

Example
Input:
5
2 3 1 5 2

Output:
5
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
    int n;cin>>n;
    vi a(n);
    input(a);
    
    sorta(a);

    int mid = a[n/2], ans = 0;
    for(auto i:a){
        ans += abs(mid- i);
    }
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