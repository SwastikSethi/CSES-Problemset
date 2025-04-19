/*
You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible. What will be the total number of rounds?
Input
The first line has an integer n: the array size.
The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
Output
Print one integer: the number of rounds.
Constraints

1 \le n \le 2 \cdot 10^5

Example
Input:
5
4 2 1 5 3

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
    int n; cin>>n;
    vi a(n);
    input(a);
    map<int,int> mpp;

    for(int i=0; i<n; i++){
        if(mpp.count(a[i]-1)){
            mpp[a[i]] = mpp[a[i]-1] + 1;
        }
        else mpp[a[i]] = 1;
    }

    int ans = 0;
    for(auto i: mpp){
        if(i.second == 1) ans++;
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