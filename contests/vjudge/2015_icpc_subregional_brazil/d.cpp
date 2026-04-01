#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define sz(x) (int)x.size()
const int LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(int n, int m){

    map<string, int> mp;
    int timer = 0;
    int grid[n+1][m+1];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            string s; cin >> s;
            if(not mp.count(s)) mp[s]=timer++;
            grid[i][j]=mp[s];
        }
        int el; cin >> el;
        grid[i][m]=el;
    }
    for(int j = 0; j < m; j ++) cin >> grid[n][j];

    vector<int> rs;
    vector<map<int, int>> eqs; // equation i has (var, qtd_mul)
    for(int i = 0; i < n; i ++){
        eqs.push_back({});
        auto& eq = eqs.back();
        for(int j = 0; j < m; j ++){
            eq[grid[i][j]]++;
        }
        rs.push_back(grid[i][m]);
    }

    for(int j = 0; j < m; j ++){
        eqs.push_back({});
        auto& eq = eqs.back();
        for(int i = 0; i < n; i ++){
            eq[grid[i][j]]++;
        }
        rs.push_back(grid[n][j]);
    }

    vector<int> ord(n+m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int& l, int& r){ 
        return eqs[l].size() < eqs[r].size();
    });

    vector<int> res(n+m, -LINF);    

    for(int k = 0; k < sz(ord); k ++){
        int i = ord[k];

        if(sz(eqs[i]) == 0) continue;
        assert(sz(eqs[i]) == 1); 

        pair<int, int> it = *eqs[i].begin();
        int fr = it.first, sn = it.second;
        
        int val = res[fr] = rs[i]/sn;
        for(int l = k + 1; l < sz(ord); l ++){
            int j = ord[l];
            if(not eqs[j].count(fr)) continue;
            rs[j] -= eqs[j][fr]*val;
            eqs[j].erase(fr);
        }


        sort(ord.begin()+k+1, ord.end(), [&](int& l, int& r){ 
            return eqs[l].size() < eqs[r].size();
        });
    }

    for(pair<string, int> it: mp){
        cout << it.first << " " << res[it.second] << endl;
    }
}

int32_t main(){ _
    int n, m;
    while(cin >> n >> m) {
        solve(n,m);
    }
    exit(0);
}