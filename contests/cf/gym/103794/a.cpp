#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define ff first 
#define ss second
#define sz(x) (int)x.size()
#define int ll

int32_t main() { _
    int n, m, t, r, c; cin >> n >> m >> t >> r >> c;
    r --, c--;
    int walls = 0;
    vector<vector<bool>> grid(n, vector<bool>(m, false));
    for(int i = 0; i < n; i ++){
        string s; cin >> s;
        for(int j = 0; j < m; j ++){
            grid[i][j] = (s[j] == '.');
            if(!grid[i][j])walls ++;
        }
    }
    vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<pair<int, int>> q; q.push({r, c});
    dist[r][c] = 0;
    auto valid = [&](int i, int j) -> bool{
        return (min(i, j) >= 0 and i < n and j < m and dist[i][j] == INF and grid[i][j]);
    };
    ll cnt = 1;
    while(sz(q)){
        auto [i, j] = q.front(); q.pop();
        for(auto [newi, newj]: mvs){
            newi += i, newj += j;
            // cout << newi << " " << newj << endl;
            if(valid(newi, newj)) {
                dist[newi][newj] = dist[i][j] + 1;
                if(dist[i][j] < t) cnt ++;
                q.push({newi, newj});
            }
        } 
    }

    ll dem = 1ll* n * m - walls;
    ll g = __gcd(dem, cnt);
    while(g > 1){
        
        dem /= g, cnt /= g;
        g = __gcd(dem, cnt);
    }
    cout << cnt << " " << dem << endl;

}