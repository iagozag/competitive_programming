#include <bits/stdc++.h>
#include <queue>
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

void no(){ cout << "-1" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 100;

vector<vector<ii>> g(MAX);
vector<ll> dist(MAX);
int memo[100][100];

void dijkstra(int o, int d){
    priority_queue<pair<ll,int>> pq; pq.push({0, o});
    while(!pq.empty()){
        auto [w, v] = pq.top(); w -= 2*w; pq.pop();
        if(w >= dist[v]) continue;
        dist[v] = w;
        if(v == d) break;
        forr(ve, g[v]) if(ve.ss+w < dist[ve.ff]) pq.push({-ve.ss-w, ve.ff});
    }
}

void solve(){
    string a, b; cin >> a >> b; int n = a.size();
    memset(memo, -1, sizeof(memo));
    int m; cin >> m; map<char,int> mp;
    rep(i, 0, m){
        char o, d; int c; cin >> o >> d >> c;
        int idx1, idx2;
        if(mp.count(o)) idx1 = mp[o]; else idx1 = mp.size(), mp[o] = idx1;
        if(mp.count(d)) idx2 = mp[d]; else idx2 = mp.size(), mp[d] = idx2;
        g[idx1].eb(idx2, c);
    }

    ll ans = 0;
    rep(i, 0, n){
        if(a[i] != b[i]){
            if(!mp.count(a[i]) or !mp.count(b[i])) return no();
            if(memo[mp[a[i]]][mp[b[i]]] != -1){ ans += memo[mp[a[i]]][mp[b[i]]]; continue; }
            dist = vl(MAX, LINF);
            dijkstra(mp[a[i]], mp[b[i]]); if(dist[mp[b[i]]] == LINF) return no();
            ans += dist[mp[b[i]]], memo[mp[a[i]]][mp[b[i]]] = dist[mp[b[i]]];
        }
    }
    cout << ans << endl;
}

int main(){ _
    int t = 1;

    while(t--) solve();

    exit(0);
}
