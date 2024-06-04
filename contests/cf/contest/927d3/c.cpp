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

int n, m;
vi v(MAX), seg(4*MAX);

ll combine(ll a, ll b){
    return ((a%m)*(b%m))%m;
}

ll build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = v[tl];

    int tm = tl+(tr-tl)/2;
    return seg[node] = combine(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

ll query(int node, int tl, int tr, int a, int b){
    if(a > tr or b < tl) return 1;
    if(a <= tl and b >= tr) return seg[node];

    int tm = tl+(tr-tl)/2;
    return combine(query(node*2, tl, tm, a, b), query(node*2+1, tm+1, tr, a, b));
}

void solve(){
    cin >> n >> m;
    rep(i, 0, n) cin >> v[i];

    build(1, 0, n-1);

    string s; int l = 0, r = n-1; cin >> s;
    if(n == 1){ cout << v[0]%m << endl; return; }

    rep(i, 0, n){
        cout << query(1, 0, n-1, l, r) << " \n"[i == n-1];
        if(s[i] == 'L') l++;
        else r--;
    }

    v.clear(), seg.clear();
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
