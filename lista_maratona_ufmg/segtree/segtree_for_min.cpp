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

vi a, t;

void build(int node, int tl, int tr){
    if(tl == tr){
        t[node] = a[tl];
        return;
    }

    int tm = (tl+tr)>>1;
    build(node*2+1, tl, tm);
    build(node*2+2, tm+1, tr);
    t[node] = min(t[node*2+1], t[node*2+2]);
}

void update(int node, int tl, int tr, int idx, int val){
    if(tl == tr){
        t[node] = val;
        return;
    }
    int tm = (tl+tr)>>1;
    if(tl <= idx && idx <= tm) update(node*2+1, tl, tm, idx, val);
    else update(node*2+2, tm+1, tr, idx, val);

    t[node] = min(t[node*2+1], t[node*2+2]);
}

int query(int node, int tl, int tr, int l, int r){
    if(l > tr || r < tl) return INF;
    if(l <= tl && r >= tr) return t[node];

    int tm = (tl+tr)>>1;
    return min(query(node*2+1, tl, tm, l, r), query(node*2+2, tm+1, tr, l, r));
}

void solve(){
    int n, m; cin >> n >> m;
    a = vi(n), t = vi(4*n);
    for(auto& x: a) cin >> x;
    build(0, 0, n-1);

    for(int i = 0; i < m; i++){
        int op; int a, b; cin >> op;
        if(op == 1){
            cin >> a >> b;
            update(0, 0, n-1, a, b);
        }
        else{
            cin >> a >> b;
            cout << query(0, 0, n-1, a, b-1) << endl;
        }
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

