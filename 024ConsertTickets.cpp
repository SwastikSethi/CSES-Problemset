/*
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.
Input
The first input line contains integers n and m: the number of tickets and the number of customers.
The next line contains n integers h_1,h_2,\ldots,h_n: the price of each ticket.
The last line contains m integers t_1,t_2,\ldots,t_m: the maximum price for each customer in the order they arrive.
Output
Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
If a customer cannot get any ticket, print -1.
Constraints

1 \le n, m \le 2 \cdot 10^5
1 \le h_i, t_i \le 10^9

Example
Input:
5 3
5 3 7 8 5
4 8 3

Output:
3
8
-1
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
    int n, m;cin>>n>>m;
    vi p(n), t(m);
    
    input(p);
    input(t);

    // multiset<int> s(p.begin(), p.end());
    map<int,int> s;
    for(auto i:p) {
        s[i]++;
    }
    
    for(auto i: t){
        auto it = s.lower_bound(i);

        if(it == s.begin() ){
            if(it->first != i){
                cout << -1 << endl;
                continue;
            }
        }
        
        if(it->first != i) {
            it--;
        }
        
        cout << it->first << endl;
        if(--(it->second) == 0) {
            s.erase(it);
        }
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