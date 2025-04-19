/*
Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. During the game, repeatedly k children are skipped and one child is removed from the circle. In which order will the children be removed?
Input
The only input line has two integers n and k.
Output
Print n integers: the removal order.
Constraints

1 \le n \le 2 \cdot 10^5
0 \le k \le 10^9

Example
Input:
7 2

Output:
3 6 2 7 5 1 4
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define sorta(v) sort(v.begin(), v.end())
#define sortr(v) sort(v.rbegin(), v.rend())
#define all(v) v.begin(), v.end()
#define input(v)      \
    for (auto &i : v) \
    cin >> i
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

void solve()
{
    int n, k;
    cin >> n >> k;

    int root = sqrt(n);
    vector<vi> a;
    vi temp;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt > root)
        {
            a.push_back(temp);
            temp.clear();
            cnt = 0;
        }
        temp.push_back(i + 1);
        cnt++;
    }

    if (temp.size() > 0)
    {
        a.push_back(temp);
    }

    int row = 0, col = 0;
    for (int i = 0; i < n; i++)
    {
        int j = k % (n - i);

        while(j){

            if (col + j < a[row].size())
            {
                col += j;
                j = 0;
            }
            else
            {
                j -= a[row].size() - col;
                row++;
                col = 0;
            }
            
            if (row >= a.size())
            row = 0;
        }
            
        while (a[row].size() <= col)
        {
            col = 0;
            row++;
            if (row >= a.size())
                row = 0;
        }

        cout << a[row][col] << " ";

        if (i != n - 1)
        {
            a[row].erase(a[row].begin()+ col);
            while (a[row].size() <= col) {
                col = 0;
                row++;
                if (row >= a.size())
                    row = 0;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}