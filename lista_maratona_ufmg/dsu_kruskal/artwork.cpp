#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m, q;
vector<int> id, sz;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool val(int i, int j){
    return i >= 0 and i < n and j >= 0 and j < m;
}

int pos(int i, int j){
    return m*i+j;
}

int find(int x){
    return x == id[x] ? x : id[x] = find(id[x]);
}

void unio(int x, int y, unordered_set<int>& s){
    x = find(x), y = find(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    id[y] = x, sz[x] += sz[y], s.erase(y);
}

void solve(){
    cin >> n >> m >> q;
    vector<vector<int>> v(n, vector<int>(m));

    unordered_set<int> s; for(int i = 0; i < n*m; i++) s.insert(i);
    id = vector<int>(n*m), sz = vector<int>(n*m, 1); iota(id.begin(), id.end(), 0);

    vector<tuple<int, int, int, int>> queries;
    for(int i = 0; i < q; i++){
        int a, b, c, d; cin >> a >> b >> c >> d; --a, --b, --c, --d;
        if(a > c) swap(a, c);
        if(b > d) swap(b, d);

        queries.emplace_back(a, b, c, d);

        if(a == c) for(int j = b; j <= d; j++){ if(!v[a][j]) s.erase(id[pos(a, j)]); v[a][j]++; }
        else for(int j = a; j <= c; j++){ if(!v[j][b]) s.erase(id[pos(j, b)]); v[j][b]++; }
    }

    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) 
        if(!vis[i][j] and !v[i][j]){
            queue<pair<int, int>> qu; qu.push({i, j}), vis[i][j] = 1;
            while(!qu.empty()){
                auto [vx, vy] = qu.front(); qu.pop();

                for(auto [x, y]: moves) if(val(vx+x, vy+y) and !vis[vx+x][vy+y] and !v[vx+x][vy+y]) 
                    unio(pos(vx, vy), pos(vx+x, vy+y), s), qu.push({vx+x, vy+y}), vis[vx+x][vy+y] = 1;
            }
        }

    vector<int> ans;
    for(int i = q-1; i >= 0; i--){
        ans.emplace_back((int)s.size());

        auto [a, b, c, d] = queries[i];
        if(a == c){ 
            for(int j = b; j <= d; j++) if(v[a][j]){
                v[a][j]--;
                if(!v[a][j]){ 
                    s.insert(find(pos(a, j)));
                    for(auto [x, y]: moves) if(val(x+a, y+j) and !v[x+a][y+j]) 
                        unio(pos(a, j), pos(x+a, y+j), s);
                }
            }
        }
        else{ 
            for(int j = a; j <= c; j++) if(v[j][b]){
                v[j][b]--;
                if(!v[j][b]){
                    s.insert(find(pos(j, b)));
                    for(auto [x, y]: moves) if(val(x+j, y+b) and !v[x+j][y+b]) 
                        unio(pos(j, b), pos(x+j, y+b), s);
                }
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for(auto x: ans) cout << x << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
