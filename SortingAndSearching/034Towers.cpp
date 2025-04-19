/*
You are given n cubes in a certain order, and your task is to build towers using them. Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.
You must process the cubes in the given order. You can always either place the cube on top of an existing tower, or begin a new tower. What is the minimum possible number of towers?
Input
The first input line contains an integer n: the number of cubes.
The next line contains n integers k_1,k_2,\ldots,k_n: the sizes of the cubes.
Output
Print one integer: the minimum number of towers.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le k_i \le 10^9

Example
Input:
5
3 8 2 1 5

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
    int n;cin>>n;
    vi a(n);
    input(a);

    multiset<int> s;
    for(auto i:a){
        auto it = s.upper_bound(i);
        if(it == s.end()) s.insert(i);
        else {
            s.erase(it);
            s.insert(i);
        }
    }

    cout << s.size() << endl;
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