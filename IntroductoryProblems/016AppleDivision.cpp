/*
There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.
Input
The first input line has an integer n: the number of apples.
The next line has n integers p_1,p_2,\dots,p_n: the weight of each apple.
Output
Print one integer: the minimum difference between the weights of the groups.
Constraints

1 \le n \le 20
1 \le p_i \le 10^9

Example
Input:
5
3 2 7 4 1

Output:
1

Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).
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

    int summ =  accumulate(all(a), 0LL);
    int ans = LLONG_MAX;

    function<void(int , int)> rec = [&](int i, int sum){
        ans = min(ans, abs(sum - (summ - sum)));
        if(i == a.size()) return;
        
        rec(i+1, sum);

        rec(i+1, sum + a[i]);
        
    };

    rec(0, 0LL);

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