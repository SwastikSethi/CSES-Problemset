/*
A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

Your task is to find out the number in row y and column x.
Input
The first input line contains an integer t: the number of tests.
After this, there are t lines, each containing integers y and x.
Output
For each test, print the number in row y and column x.
Constraints

1 \le t \le 10^5
1 \le y,x \le 10^9

Example
Input:
3
2 3
1 1
4 2

Output:
8
1
15
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
    int t;cin>>t;

    while(t--){
        int row ,col;
        cin >> row >> col;

        int level = max(row,col);

        int ans = (level-1)*(level-1);

        if(level%2){
            if(row >= col){
                ans += col;
            }
            else ans += (level-row) + col ;
        }
        else {
            if(row <= col) ans += row;
            else ans += row+level-col;
        }

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
