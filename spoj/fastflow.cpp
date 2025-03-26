#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

class Dinitz{
    private:
        struct edge{
            int to, cap, rev, flow;
            bool res;
            edge(int _to, int _cap, int _rev, bool _res):
                to(_to), cap(_cap), rev(_rev), flow(0), res(_res) {}
        };

        vector<vector<edge>> g;
        vector<int> lev, beg;
        long long F;

    public:
        Dinitz(int n);

        void add(int a, int b, int c);

        bool bfs(int s, int t);

        int dfs(int v, int s, int f);

        long long max_flow(int s, int t);

        vector<pair<int, int>> get_cut(int s, int t);
};

Dinitz::Dinitz(int n): g(n), F(0) {}

void Dinitz::add(int a, int b, int c){
    g[a].emplace_back(b, c, g[b].size(), false);
    g[b].emplace_back(a, 0, g[a].size()-1, true);
}

bool Dinitz::bfs(int s, int t){
    lev = vector<int>(g.size(), -1); lev[s] = 0;
    beg = vector<int>(g.size(), 0);
    queue<int> q; q.push(s);
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto& i: g[u]){
            if(lev[i.to] != -1 or i.flow == i.cap) continue;
            lev[i.to] = lev[u]+1;
            q.push(i.to);
        }
    }
    return lev[t] != -1;
}

int Dinitz::dfs(int v, int s, int f = INF){
    if(!f or v == s) return f;
    for(int& i = beg[v]; i < g[v].size(); i++){
        auto& e = g[v][i];
        if(lev[e.to] != lev[v]+1) continue;
        int went = dfs(e.to, s, min(f, e.cap-e.flow));
        if(!went) continue;
        e.flow += went, g[e.to][e.rev].flow -= went;
        return went;
    }
    return 0;
}

long long Dinitz::max_flow(int s, int t){
    while(bfs(s, t))
        while(int ff = dfs(s, t))
            F += ff;
    return F;
}

vector<pair<int, int>> Dinitz::get_cut(int s, int t){
    this->max_flow(s, t);
    vector<pair<int, int>> cut;
    vector<int> vis(g.size(), 0), st = {s};
    vis[s] = 1;
    while(st.size()){
        int u = st.back(); st.pop_back();
        for(auto e: g[u]) if(!vis[e.to] and e.flow < e.cap)
            vis[e.to] = 1, st.push_back(e.to);
    }
    for(int i = 0; i < g.size(); i++) for(auto e: g[i])
        if(vis[i] and !vis[e.to] and !e.res) cut.emplace_back(i, e.to);
    return cut;
}

void solve(){
	int n, m; cin >> n >> m;
	Dinitz D(n);
	for(int i = 0; i < m; i++){ int a, b, c; cin >> a >> b >> c; --a, --b; D.add(a, b, c), D.add(b, a, c); }
	cout << D.max_flow(0, n-1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
