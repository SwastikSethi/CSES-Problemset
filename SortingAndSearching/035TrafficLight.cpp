/*
There is a street of length x whose positions are numbered 0,1,\ldots,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.
Your task is to calculate the length of the longest passage without traffic lights after each addition.
Input
The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.
Then, the next line contains n integers p_1,p_2,\ldots,p_n: the position of each set of traffic lights. Each position is distinct.
Output
Print the length of the longest passage without traffic lights after each addition.
Constraints

1 \le x \le 10^9
1 \le n \le 2 \cdot 10^5
0 < p_i < x

Example
Input:
8 3
3 6 2

Output:
5 3 3
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
    int x, n;
    cin>>x>>n;

    set<int> s;
    s.insert(0);
    s.insert(x);

    multiset<int> dif;
    dif.insert(x);

    int a;
    while(n--){
        cin>>a;

        auto it = s.lower_bound(a);
        auto it2 = it;
        --it2;

        dif.erase(dif.find(*it-*it2));
        dif.insert(*it-a);
        dif.insert(a-*it2);

        cout << *--dif.end() << " ";
        s.insert(a);
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