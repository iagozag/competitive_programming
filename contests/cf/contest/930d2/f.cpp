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

const int MAX = 2e5+10, k = 35;

int n, v;
vi va, vb;

struct segt{
	int pn, sn;
	ii p[k], s[k];
	int all, ans, mx;
 
	segt(){
		pn = sn = 0;
		all = -1;
	}
 
	segt(int a, int b){
		pn = sn = 0, ans = INF, all = b, mx = a;
		p[pn++] = {b, a}, s[sn++] = {b, a};
		if(b >= v) ans = min(ans, a);
	}
} seg[4*MAX];

segt combine(segt a, segt b){
	if (a.all == -1) return b;
	if (b.all == -1) return a;

	segt c;
	c.all = (a.all | b.all);
	c.ans = min(a.ans, b.ans);
	c.mx = max(a.mx, b.mx);
 
	rep(i, 0, a.pn){
		int x = a.p[i].ff, y = a.p[i].ss;
		if(c.pn > 0 && c.p[c.pn - 1].ff == x) continue;
		c.p[c.pn++] = {x, y};
	}

	rep(i, 0, b.pn){
		int x = (a.all | b.p[i].ff), y = max(a.mx, b.p[i].ss);
		if(c.pn > 0 && c.p[c.pn - 1].ff == x) continue;
		c.p[c.pn++] = {x, y};
	}
 
	rep(i, 0, b.sn){
		int x = b.s[i].ff, y = b.s[i].ss;
		if(c.sn > 0 && c.s[c.sn - 1].ff == x) continue;
		c.s[c.sn++] = {x, y};
	}
 
	rep(i, 0, a.sn){
		int x = (b.all | a.s[i].ff), y = max(b.mx, a.s[i].ss);
		if(c.sn > 0 && c.s[c.sn - 1].ff == x) continue;
		c.s[c.sn++] = {x, y};
	}
 
	for(int i = 0, j = b.pn - 1; i < a.sn; i++){
		while(j >= 0 && (b.p[j].ff | a.s[i].ff) >= v) j--;
		if (j + 1 < b.pn) c.ans = min(c.ans, max(a.s[i].ss, b.p[j + 1].ss));
	}
	return c;
}

segt build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = segt(va[tl], vb[tl]);

    int tm = tl+(tr-tl)/2;
    return seg[node] = combine(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

void update(int node, int tl, int tr, int idx){
    if(tl == tr){ seg[node] = segt(va[tl], vb[tl]); return; }

    int tm = tl+(tr-tl)/2;
    if(idx <= tm) update(node*2, tl, tm, idx);
    else update(node*2+1, tm+1, tr, idx);

    seg[node] = combine(seg[node*2], seg[node*2+1]);
}

segt query(int node, int tl, int tr, int l, int r){
    if (r < tl or l > tr) return segt();
    if(l <= tl and r >= tr) return seg[node];

    int tm = (tl+tr)/2;
    return combine(query(node*2, tl, tm, l, r), query(node*2+1, tm+1, tr, l, r));
}

void solve(){
    cin >> n >> v;
    va = vi(n), vb = vi(n);
    forr(x, va) cin >> x; 
    forr(x, vb) cin >> x;

    build(1, 0, n-1);

    int q; cin >> q;
    rep(i, 0, q){
        int op, op1, op2; cin >> op;
        if(op == 1){
            cin >> op1 >> op2; op1--, vb[op1] = op2;
            update(1, 0, n-1, op1);
        } else{
            cin >> op1 >> op2; op1--, op2--;

            auto ans = query(1, 0, n-1, op1, op2);
            cout << (ans.all >= v ? ans.ans : -1) << " ";
        }
    }

    cout << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
