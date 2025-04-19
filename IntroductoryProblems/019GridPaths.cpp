/*
There are 88418 paths in a 7 \times 7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).
For example, the path

corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.
You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.
Input
The only input line has a 48-character string of characters ?, D, U, L and R.
Output
Print one integer: the total number of paths.
Example
Input:
??????R??????U??????????????????????????LD????D?

Output:
201
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
    string s;
    cin>>s;

    vector<vector<bool>> vis(9, vector<bool> (9,0));

    for (int i = 0; i < 9; i++) {
		vis[0][i] = true;
		vis[8][i] = true;
		vis[i][0] = true;
		vis[i][8] = true;
	}

    int ans = 0;
    
    auto dfs = [&](int i, int r, int c, auto &dfs){
        if(i == s.size()) {
            if(r == 7 && c == 1) ans++;
            // cout << ans << endl;
            return;
        }
        
        if(r == 7 && c == 1) return;

        if( vis[r-1][c] && vis[r+1][c] && (!vis[r][c+1]) && (!vis[r][c-1]) ) return;
        
        if( !vis[r-1][c] && !vis[r+1][c] && vis[r][c+1] && vis[r][c-1] ) return;

        vis[r][c] = 1;

        if(s[i] == 'D'){
            if(r+1 < 9 && vis[r+1][c] == 0 ){
                dfs(i+1, r+1, c, dfs);
            }
        }

        else if(s[i] == 'U'){
            if(r-1 > 0 && vis[r-1][c] == 0 ){
                dfs(i+1, r-1, c, dfs);
            }
        }
        else if(s[i] == 'L'){
            if(c-1 > 0 && vis[r][c-1] == 0 ){
                dfs(i+1, r, c-1, dfs);
            }
        }
        else if(s[i] == 'R'){
            if(c+1 < 9 && vis[r][c+1] == 0 ){
                dfs(i+1, r, c+1, dfs);
            }
        }
        
        else {
            if(r+1 < 9 && vis[r+1][c] == 0 ){
                dfs(i+1, r+1, c, dfs);
            }
            if(r-1 > 0 && vis[r-1][c] == 0 ){
                dfs(i+1, r-1, c, dfs);
            }
            if(c-1 > 0 && vis[r][c-1] == 0 ){
                dfs(i+1, r, c-1, dfs);
            }
            if(c+1 < 9 && vis[r][c+1] == 0 ){
                dfs(i+1, r, c+1, dfs);
            }
        }
        vis[r][c] = 0;
    };

    dfs(0,1,1, dfs);

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