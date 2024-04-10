#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vector<vector<pair<int,ii>>> g;
vl dist; vi vis;

void dijkstra(int s, int de){
	priority_queue<pair<ll, int>> pq; pq.push({0, s}), dist[s] = 0;
	while(!pq.empty()){
		auto [w, v] = pq.top(); pq.pop(); w *= -1;
		if(vis[v]) continue;
		if(v == de) break;

		vis[v] = 1;
		for(auto x: g[v]){
			int ve = x.ff; auto [d, k] = x.ss;
			if(w == 0 and d < dist[ve]) dist[ve] = d, pq.push({-dist[ve], ve});
			else if(w%k == 0 and w+d < dist[ve]) dist[ve] = w+d, pq.push({-w-d, ve});
			else if(w+d+(k-(w%k)) < dist[ve]) dist[ve] = w+d+(k-(w%k)), pq.push({-dist[ve], ve});
		}	
	}
}

void solve(){
	int n, m, x, y; cin >> n >> m >> x >> y; --x, --y;
	g = vector<vector<pair<int,ii>>>(n), dist = vl(n, LINF), vis = vi(n); 
	rep(i, 0, m){
		int a, b, w, k; cin >> a >> b >> w >> k; --a, --b;
		g[a].pb({b, {w, k}}), g[b].pb({a, {w, k}});
	}

	dijkstra(x, y);
	cout << (dist[y] == LINF ? -1 : dist[y]) << endl;
}

int main(){ _ 
	solve();
    exit(0);
}
