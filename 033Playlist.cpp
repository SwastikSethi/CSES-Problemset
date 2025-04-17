/*
You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
What is the longest sequence of successive songs where each song is unique?
Input
The first input line contains an integer n: the number of songs.
The next line has n integers k_1,k_2,\ldots,k_n: the id number of each song.
Output
Print the length of the longest sequence of unique songs.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le k_i \le 10^9

Example
Input:
8
1 2 1 3 2 7 4 2

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
    int n; cin>>n;
    vi a(n);
    input(a);

    map<int,int> mpp;

    int l=0, r =0, ans = 0;;
    while(r<n){
        mpp[a[r]]++;
        while(l<r && mpp[a[r]] > 1 ){
            mpp[a[l++]]--;
        }
        ans = max(ans, r-l+1);
        r++;
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