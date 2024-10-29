#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m, q;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool val(int i, int j){
    return i >= 0 and i < n and j >= 0 and j < m;
}

void solve(){
    cin >> n >> m >> q;
    vector<vector<int>> v(n, vector<int>(m));

    vector<tuple<int, int, int, int>> queries;
    for(int k = 0; k < q; k++){
        int a, b, c, d; cin >> a >> b >> c >> d; --a, --b, --c, --d;
        if(a > c) swap(a, c);
        if(b > d) swap(b, d);

        if(a == c) for(int j = b; j <= d; j++){ if(!v[a][j])  v[a][j]++; }
        else for(int j = a; j <= c; j++){ if(!v[j][b])  v[j][b]++; }

        vector<vector<bool>> vis(n, vector<bool>(m)); int cnt = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) 
        if(!vis[i][j] and !v[i][j]){
            cnt++;
            queue<pair<int, int>> qu; qu.push({i, j}), vis[i][j] = 1;
            while(!qu.empty()){
                auto [vx, vy] = qu.front(); qu.pop();

                for(auto [x, y]: moves) if(val(vx+x, vy+y) and !vis[vx+x][vy+y] and !v[vx+x][vy+y]) 
                    qu.push({vx+x, vy+y}), vis[vx+x][vy+y] = 1;
            }
        }
        cout << cnt << endl;
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
