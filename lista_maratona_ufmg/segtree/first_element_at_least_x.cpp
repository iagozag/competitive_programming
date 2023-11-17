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

int MAX = 1e5+10;
vi v(MAX), seg(MAX*4, -1);

int build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = v[tl];

    int tm = (tl+tr)>>1;
    return seg[node] = max(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

int update(int node, int tl, int tr, int idx, int x){
    if(idx > tr || idx < tl) return seg[node];
    if(tl == tr) return seg[node] = x;

    int tm = (tl+tr)>>1;
    return seg[node] = max(update(node*2, tl, tm, idx, x), update(node*2+1, tm+1, tr, idx, x));
}

int query(int node, int tl, int tr, int x){
    if(seg[node] < x) return -1;
    if(tl == tr) return tl;

    int tm = (tl+tr)>>1;
    if(seg[node*2] >= x) return query(node*2, tl, tm, x);
    else return query(node*2+1, tm+1, tr, x);
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n-1);

    for(int i = 0; i < m; i++){
        int op, a, b; cin >> op;
        if(op == 1){
            cin >> a >> b;
            update(1, 0, n-1, a, b);
        } else{
            cin >> a;
            cout << query(1, 0, n-1, a) << endl;
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

