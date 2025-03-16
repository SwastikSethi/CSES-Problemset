/*
Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
Input
The only input line has a string of length n consisting of characters A–Z.
Output
Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example
Input:
AAAACACBA

Output:
AACABACAA
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
    string s;cin>>s;

    sort(s.begin(), s.end());
    string ans = s;

    int i =0, n = s.size(), j = 0;
    bool flag = false;
    while(i<n){

        if(i+1 == n || s[i] != s[i+1]) {
            if(n%2 && !flag){
                ans[n/2] = s[i];
                i++;
                flag = true;
                continue;
            }
            else {
                cout << "NO SOLUTION" << endl;
                return;
            }
        }
        
        ans[j] = ans[n-j-1] = s[i];
        j++;
        i += 2;
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