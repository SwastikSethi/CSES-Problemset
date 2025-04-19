/*
A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.
Input
The only input line contains an integer n.
Output
Print a beautiful permutation of integers 1,2,\ldots,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example 1
Input:
5

Output:
4 2 5 3 1
Example 2
Input:
3

Output:
NO SOLUTION
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
    if(n<=3 && n>1) {
        cout << "NO SOLUTION" << endl; 
        return;
    }

    int l = 0, r = n-1;
    int i = 1;

    while(l<r){
        a[l++] = i++;
        a[r--] = i++;
    }
    if(l == r) a[l] = i;
    // swap(a[0], a[n/2]);

    if(n%2) reverse(a.begin(), a.begin()+(n/2) + 1);
    else reverse(a.begin(), a.begin()+(n/2));

    for(auto j:a) cout << j << " ";
    cout << endl;
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