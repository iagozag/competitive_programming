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

const int MAX = 1e4+10;

int n, m;
vector<vi> g(MAX);
vi dist(MAX, -1);

int bfs(){
    queue<int> q; q.push(n);
    dist[n] = 0;

    while(!q.empty()){
        int v = q.front(); q.pop();
        if(v == m) break;
        forr(ve, g[v]){
            if(dist[ve] != -1) continue;
            q.push(ve), dist[ve] = dist[v]+1;
        }
    }

    return dist[m];
}

void solve(){
    cin >> n >> m;
    rep(i, 1, MAX){
        g[i].eb(i-1);
        g[i].eb(i*2);
    }

    cout << bfs() << endl;
}

int main(){ _
    int t = 1;

    while(t--) solve();

    exit(0);
}
