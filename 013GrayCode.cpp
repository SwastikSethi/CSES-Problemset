/*
A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n.
Input
The only input line has an integer n.
Output
Print 2^n lines that describe the Gray code. You can print any valid solution.
Constraints

1 \le n \le 16

Example
Input:
2

Output:
00
01
11
10
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

vector<string> fun(int n){
    if(n==1) return {"0", "1"};
    
    auto prev = fun(n-1);

    int size = prev.size();

    vector<string> res ;
    for(int i=0; i<size; i++){
        res.push_back("0" + prev[i]);
    }
    
    for(int i= size-1; i>=0; i--){
        res.push_back("1" + prev[i]);
    }

    return res;
}

void solve(){
    int n; cin>> n;

    auto res = fun(n);

    for(auto i:res){
        cout << i << endl;
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