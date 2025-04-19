/*
There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.
Input
The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.
The next line contains n integers a_1, a_2, \ldots, a_n: the desired apartment size of each applicant. If the desired size of an applicant is x, they will accept any apartment whose size is between x-k and x+k.
The last line contains m integers b_1, b_2, \ldots, b_m: the size of each apartment.
Output
Print one integer: the number of applicants who will get an apartment.
Constraints

1 \le n, m \le 2 \cdot 10^5
0 \le k \le 10^9
1 \le a_i, b_i \le 10^9

Example
Input:
4 3 5
60 45 80 60
30 60 75

Output:
2
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
    int n, m,k;
    cin>>n>>m>>k;

    vi a(n), b(m);

    input(a);
    input(b);

    sort(all(a));
    sort(all(b));

    // for(auto i:a) cout << i << " "; cout << endl;
    // for(auto i:b) cout << i << " "; cout << endl;

    int i=0, j = 0, ans = 0;
    while(i<n && j< m){
        if(a[i] >= b[j]){
            if(a[i]-k <= b[j]){
                ans++;
                i++;j++;
            }
            else {
                j++;
            }
        }
        else {
            if(a[i]+k >= b[j]){
                ans++;
                i++; j++;
            }
            else {
                i++;
            }
        }
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