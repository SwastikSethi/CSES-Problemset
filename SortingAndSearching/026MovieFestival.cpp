/*
In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?
Input
The first input line has an integer n: the number of movies.
After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.
Output
Print one integer: the maximum number of movies.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a < b \le 10^9

Example
Input:
3
3 5
4 9
5 8

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
    int n; cin>>n;
    vii a(n);
    for(auto &i:a){
        cin>>i.first >> i.second;
    }

    sort(all(a),[](pair<int,int> &c, pair<int,int> &b){
        return c.second < b.second;
    } );

    int curEnd = a[0].second;
    int ans = 1;

    for(int i=1; i<n; i++){
        if(curEnd <= a[i].first) {
            ans ++;
            curEnd = a[i].second;
        }
        else {
            curEnd = min(a[i].second, curEnd);
        }
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