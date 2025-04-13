/*
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.
What is the minimum number of gondolas needed for the children?
Input
The first input line contains two integers n and x: the number of children and the maximum allowed weight.
The next line contains n integers p_1,p_2,\ldots,p_n: the weight of each child.
Output
Print one integer: the minimum number of gondolas.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x \le 10^9
1 \le p_i \le x

Example
Input:
4 10
7 2 3 9

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
    int n, x;
    cin>>n>>x;

    vi a(n);
    input(a);

    sort(all(a));

    int i=0, j = n-1, ans = 0;
    while(i<j){
        if(a[i]+a[j] > x){
            ans++;
            j--;
        }
        else {
            i++;j--; ans++;
        }
    }
    if(i==j) ans++;

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