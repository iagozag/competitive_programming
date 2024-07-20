#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

string s;
vector<pair<int, pii>> seg;

pair<int, pii> combine(pair<int, pii> a, pair<int, pii> b){
    pair<int, pii> c;

    int mi = min(a.ss.ff, b.ss.ss)*2;
    c.ff = a.ff+b.ff+mi; 
    a.ss.ff -= mi/2, b.ss.ss -= mi/2;
    c.ss.ff = a.ss.ff+b.ss.ff, c.ss.ss = a.ss.ss+b.ss.ss; 
    
    return c;
}

pair<int, pii> build(int node, int l, int r){
    if(l == r) return seg[node] = {0, {s[l] == '(', s[l] == ')'}};
    int m = (l+r)>>1;
    return seg[node] = combine(build(node*2, l, m), build(node*2+1, m+1, r));
}

pair<int, pii> query(int node, int l, int r, int ql, int qr){
    if(l > qr or r < ql) return {0, {0, 0}};
    if(ql <= l and r <= qr) return seg[node];
    int m = (l+r)>>1;
    return combine(query(node*2, l, m, ql, qr), query(node*2+1, m+1, r, ql, qr));
}

void solve(){
    cin >> s;
    int n = sz(s); seg = vector<pair<int, pii>>(4*n);

    build(1, 0, n-1);

    int m; cin >> m;
    rep(i, 0, m){
        int a, b; cin >> a >> b; --a, --b;
        cout << query(1, 0, n-1, a, b).ff << endl;
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
