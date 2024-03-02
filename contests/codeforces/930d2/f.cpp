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

const int MAX = 2e5+10;

int n, v;
vi a, b;
vl sega, segb;

ll builda(int node, int tl, int tr){
    if(tl == tr) return sega[node] = a[tl];

    int tm = tl+(tr-tl)/2;
    return sega[node] = max(builda(node*2, tl, tm), builda(node*2+1, tm+1, tr));
}

ll buildb(int node, int tl, int tr){
    if(tl == tr) return segb[node] = b[tl];

    int tm = tl+(tr-tl)/2;
    return segb[node] = (buildb(node*2, tl, tm) | buildb(node*2+1, tm+1, tr));
}

ll updateb(int node, int tl, int tr, int idx, int val){
    if(idx < tl or idx > tr) return segb[node];
    if(tl == tr) return segb[node] = val;

    int tm = tl+(tr-tl)/2;
    return segb[node] = (updateb(node*2, tl, tm, idx, val) | updateb(node*2+1, tm+1, tr, idx, val));
}

ll query(int node, int tl, int tr, int l, int r){
    if(l > tr or r < tl or segb[node] < v) return INF;
    if(segb[node] >= v) return sega[node];

    int tm = tl+(tr-tl)/2;
    return min(query(node*2, tl, tm, l, r), query(node*2+1, tm+1, tr, l, r));
}

void solve(){
    cin >> n >> v;
    a = vi(n), b = vi(n), sega = vl(4*n), segb = vl(4*n);
    forr(x, a) cin >> x; 
    forr(x, b) cin >> x;

    builda(1, 0, n-1), buildb(1, 0, n-1);
    int q; cin >> q;
    rep(i, 0, q){
        int op, op1, op2; cin >> op;
        if(op == 1){
            cin >> op1 >> op2; op1--;
            updateb(1, 0, n-1, op1, op2);
        } else{
            cin >> op1 >> op2; op1--, op2--;
            ll ans = query(1, 0, n-1, op1, op2);
            cout << (ans != INF ? ans : -1) << " ";
        }
    }

    cout << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
