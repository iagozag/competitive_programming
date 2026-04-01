#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

const int LINF = 0x3f3f3f3f3f3f3f3fll;

string s; 
int m, n;
vector<int> magic;
vector<vector<pair<int, int>>> memo;

pair<int, int> dp(int i, int j){
    if(i > j) return {0, 0};
    if(i == j) return {magic[i], 1};

    auto& x = memo[i][j];
    if(x.first != -1) return memo[i][j];

    pair<int, int> y;
    // equal
    if(s[i] == s[j]){
        y = dp(i+1, j-1);
        if(x.first < y.first+magic[i]+magic[j] or (x.first == y.first+magic[i]+magic[j] and x.second < y.second+2))
            x = {y.first+magic[i]+magic[j], y.second+2};
    }

    // move left
    y = dp(i+1, j);
    if(x.first < y.first or (x.first == y.first and x.second < y.second))
        x = {y.first, y.second};

    // move right
    y = dp(i, j-1);
    if(x.first < y.first or (x.first == y.first and x.second < y.second))
        x = {y.first, y.second};

    return x;
}

int32_t main(){ _
    while(cin >> s){
        n = s.size();
        magic = vector<int>(n);

        cin >> m;
        for(int i = 0; i < m; i++){ int x; cin >> x; --x; magic[x] = 1; }

        memo = vector<vector<pair<int, int>>>(n+1, vector<pair<int, int>>(n+1, {-1, 0}));
        cout << dp(0, n-1).second << endl;
    }

    exit(0);
}