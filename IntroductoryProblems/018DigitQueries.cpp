/*
Consider an infinite string that consists of all positive integers in increasing order:
12345678910111213141516171819202122232425...
Your task is to process q queries of the form: what is the digit at position k in the string?
Input
The first input line has an integer q: the number of queries.
After this, there are q lines that describe the queries. Each line has an integer k: a 1-indexed position in the string.
Output
For each query, print the corresponding digit.
Constraints

1 \le q \le 1000
1 \le k \le 10^{18}

Example
Input:
3
7
19
12

Output:
7
4
1
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

int binpow(int a, int b, int mod){
    if(b==0) return 1;

    int res = binpow(a, b/2, mod)%mod;

    if(b%2 == 0){
        return (res * res)%mod;
    }
    else return ((res * res)%mod * a) %mod;
}

void solve(){
    int k; cin>>k;

    if(k<10) {
        cout << k<< endl;
        return;
    }

    int base = 9;
    int digits = 1;

    while(k - digits*base > 0){
        k -= (digits*base);
        digits++;
        base*= 10;
    }

    int index = k%digits;

    int res = binpow(10, digits-1, 1e18) + (k-1)/digits;

    if(index != 0){
        cout << (res/binpow(10, digits-index, 1e18))%10 << endl;
        return ;
    }
    else {
        cout << res%10 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}