/*
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output
Print one integer: the number of ways you can place the queens.

Example
Input:

........
........
..*.....
........
........
.....**.
...*....
........
Output:

65
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
    vector<string> a(8);
    input(a);

    unordered_set<int>  diagsum, diagsub;
    vector<int> row(8,0), col(8,0);

    int ans = 0;
    auto func = [&](int i, int r, auto &func){
        if(i == 8) ans++;
        if(r == 8) return;

        for(int c=0; c<8; c++){
            if(a[r][c] == '*' || row[r] || col [c] || diagsum.count(r+c) || diagsub.count(r-c)){
                continue;
            }

            row[r] = col[c] = 1;
            diagsum.insert(r+c);
            diagsub.insert(r-c);
            
            func(i+1, r+1, func);

            row[r] = col[c] = 0;
            diagsum.erase(r+c);
            diagsub.erase(r-c);
        }
    };

    func(0, 0, func);

    cout << ans <<endl;
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