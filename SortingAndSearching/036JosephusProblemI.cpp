/*
Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. During the game, every other child is removed from the circle until there are no children left. In which order will the children be removed?
Input
The only input line has an integer n.
Output
Print n integers: the removal order.
Constraints

1 \le n \le 2 \cdot 10^5

Example
Input:
7

Output:
2 4 6 1 5 3 7
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
    queue<int> q;

    for(int i=1 ;i <= n ;i++){
        q.push(i);
    }

    bool f = false;
    while(!q.empty()){
        if(f){
            cout << q.front() << " ";
            q.pop();
        }else{
            q.push(q.front());
            q.pop();
        }
        f = !f;
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