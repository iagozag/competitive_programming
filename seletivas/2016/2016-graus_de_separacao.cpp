#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void DBG() {
    cerr << "]" << endl;
}

void DBGC() {
    cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t)) cerr << ", ";
    DBG(t...);
}

template<class H, class... T> void DBGC(H h, T... t) {
    for(auto& x: h) cerr << x << " ";
    if(sizeof...(t)) cerr << "], [ ";
    DBGC(t...);
}

#ifndef _DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
#else
#define dbg(...) 0
#define dbgc(...) 0
#endif

const int MAX = 1e5+10;
vector<vi> g(MAX);
vi dist;

int bfs(int x){
    int ma = 0; dist[x] = 0;

    queue<int> q; q.push(x);
    while(!q.empty()){
        int v = q.front(); q.pop();
        
        for(auto ve: g[v]) if(dist[ve] == -1){
            ma = dist[ve] = dist[v]+1;
            q.push(ve);
        }
    }

    return ma;
}

void solve(){
    int n, m; cin >> n >> m;
    dist = vi(n, -1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].pb(b), g[b].pb(a);
    }

    bfs(0);
    if(find(all(dist), -1) != dist.end()) { cout << 'N' << endl; return; }

    int idx = 0;
    for(int i = 1; i < n; i++) if(dist[idx] < dist[i]) idx = i;

    fill(all(dist), -1);
    bfs(idx);

    cout << (*max_element(all(dist)) > 6 ? 'N' : 'S') << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
