/*
Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
Input
The only input line contains an integer n.
Output
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.
Constraints

1 \le n \le 10^6

Example 1
Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6
Example 2
Input:
6

Output:
NO

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
    int totSum = n*(n+1) /2;
    if(totSum%2) {
        no;
        return ;
    }

    vi s1, s2, vis(n+1, 0);
    int sum = 0, req = totSum/2, max_element = n;

    while(sum < req){

        if(req-sum >= max_element){
            sum += max_element;
            s1.push_back(max_element);
            vis[max_element--] = 1;
        }

        else {
            vis[req-sum] = 1;
            s1.push_back(req-sum);
            sum = req;
        }
    }

    for(int i= 1; i<=n; i++){
        if(vis[i] == 0) s2.push_back(i);
    }

    cout << "YES" << endl << s1.size()<<endl;
    for(auto i:s1) cout << i << " ";
    
    cout << endl << s2.size()<<endl;
    for(auto i:s2) cout << i << " ";

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