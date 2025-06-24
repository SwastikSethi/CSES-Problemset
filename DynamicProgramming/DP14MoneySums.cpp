/*
You have n coins with certain values. Your task is to find all money sums you can create using these coins.
Input
The first input line has an integer n: the number of coins.
The next line has n integers x_1,x_2,\dots,x_n: the values of the coins.
Output
First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.
Constraints

1 \le n \le 100
1 \le x_i \le 1000

Example
Input:
4
4 2 5 2

Output:
9
2 4 5 6 7 8 9 11 13
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

    vi a(n); input(a);
    sort(all(a));

    set<int> s;
    s.insert(a[0]);

    for(int i=1; i<n; i++) {
        int cur = a[i];
        vi temp = {cur};
        for(auto j:s) temp.push_back(j+cur);

        s.insert(all(temp));
    }

    cout << s.size() << endl;
    for(auto i:s) cout << i << " " ; cout << endl;

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