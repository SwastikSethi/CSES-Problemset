/*You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
Input
The first input line contains two integers n and x: the number of books and the maximum total price.
The next line contains n integers h_1,h_2,\ldots,h_n: the price of each book.
The last line contains n integers s_1,s_2,\ldots,s_n: the number of pages of each book.
Output
Print one integer: the maximum number of pages.
Constraints

1 \le n \le 1000
1 \le x \le 10^5
1 \le h_i, s_i \le 1000

Example
Input:
4 10
4 8 5 3
5 12 8 1

Output:
13

Explanation: You can buy books 1 and 3. Their price is 4+5=9 and the number of pages is 5+8=13.
*/

#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
    
    vi prices(n), pages(n);
    input(prices);
    input(pages);

    // dp[books from 1 to i][with x money]
    vvi dp(n+1, vi (x+1, 0));

    // base case
    // dp[0][i] = 0 -> no books to choose

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=x; j++) {
            int price = prices[i-1];
            int page = pages[i-1];

            int pick = (j>=price? page + dp[i-1][j-price] : 0);
            int skip = dp[i-1][j];

            dp[i][j] = max(pick, skip);
        }
    }

    // for(auto i:dp){ for(auto j:i) cout << j << " "; cout << endl;}

    cout << dp[n][x] << endl;
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