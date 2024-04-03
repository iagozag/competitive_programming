#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
#define forr(v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
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

const int MAX = 2e5+10;

int n, m, a, b;
vector<vi> dist;

void bfs(int s, int u, vector<vi>& g){
	vi&d = dist[u];
	fill(all(d), INF), d[s] = 0;

    queue<int> q; q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();

        for(auto ve: g[v]){
			if(d[v]+1 < d[ve])
	            d[ve] = d[v]+1, q.push(ve);
        }
    }
}

void solve(){
    cin >> n >> m >> a >> b;
	vector<vi> g(n+1), g_t(n+1); dist = vector<vi>(3, vi(n+1));
    rep(i, 0, m){
        int va, vb; cin >> va >> vb;
        g[va].pb(vb), g_t[vb].pb(va);
    }

	bfs(0, 0, g);
	bfs(a, 1, g_t);
	bfs(b, 2, g_t);

	int mi = INF;
	rep(i, 0, n){
		mi = min(mi, dist[0][i]+dist[1][i]+dist[2][i]);
	}

	cout << mi << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
