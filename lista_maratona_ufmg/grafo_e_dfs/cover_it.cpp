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

void solve(){
    int n, m; scanf("%d%d", &n, &m);
    vector<vi> g(n); vi dist(n, -1);

    rep(i, 0, m){
        int a, b; scanf("%d%d", &a, &b); a--, b--;
        g[a].pb(b), g[b].pb(a);
    }

    int odd[n], even[n], k = 0, j = 0;
    dist[0] = 0;

    queue<int> q; q.push(0);
    while(!q.empty()){
        int v = q.front(); q.pop();

        if(dist[v]&1) odd[k] = v+1, k++;
        else even[j] = v+1, j++;

        for(auto& ve: g[v]) if(dist[ve] == -1){
            dist[ve] = dist[v]+1;
            q.push(ve);
        }
    }

    if(k <= j){ printf("%d\n", k); rep(i, 0, k) printf("%d ", odd[i]); printf("\n"); }
    else { printf("%d\n", j); rep(i, 0, j) printf("%d ", even[i]); printf("\n"); }
}

int main(){ _
    int t; scanf("%d", &t);
    while(t--){
        solve();
    }

    exit(0);
}

