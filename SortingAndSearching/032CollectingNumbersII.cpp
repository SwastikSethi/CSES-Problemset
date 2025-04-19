/*
You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible.
Given m operations that swap two numbers in the array, your task is to report the number of rounds after each operation.
Input
The first line has two integers n and m: the array size and the number of operations.
The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
Finally, there are m lines that describe the operations. Each line has two integers a and b: the numbers at positions a and b are swapped.
Output
Print m integers: the number of rounds after each swap.
Constraints

1 \le n, m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
4 2 1 5 3
2 3
1 5
2 3

Output:
2
3
4
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
    vi a(n);
    input(a);

    vector<int> mpp(n+1,0);
    vector<int> mpp2(n+1,0);

    for(int i=0; i<n; i++){
        if(mpp[a[i]-1]){
            mpp[a[i]] = mpp[a[i]-1] + 1;
        }
        else mpp[a[i]] = 1;
        mpp2[a[i]] = i;
    }

    int ans = 0;
    for(auto i: mpp){
        if(i == 1) ans++;
    }
    while(m--){
        int b, c; cin>>b>>c;

        set<pair<int,int>> s;
        int cnt = 0;
        if(a[b-1]-1 > 0) s.insert({a[b-1], a[b-1]-1});
        if(a[b-1]+1 <= n) s.insert({a[b-1]+1, a[b-1]});
        if(a[c-1]-1 > 0) s.insert({a[c-1], a[c-1]-1});
        if(a[c-1]+1 <= n) s.insert({a[c-1]+1, a[c-1]});
        
        for(auto i:s){
            cnt -= (mpp2[i.first] < mpp2[i.second]);
        }
        
        swap(a[b-1], a[c-1]);
        mpp2[a[b-1]] = b-1;
        mpp2[a[c-1]] = c-1;
        
        for(auto i:s){
            cnt += (mpp2[i.first] < mpp2[i.second]);
        }

        ans += cnt;
        cout << ans << endl;
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