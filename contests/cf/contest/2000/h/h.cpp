#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e6+1, MOD = 1e9+7;

vi seg(MAX<<2), lz(MAX<<2);

int build(int node, int l, int r){
    if(l == r) return seg[node] = l;
    int m = (l+r)>>1;
    return seg[node] = max(build(node<<1, l, m), build((node<<1)+1, m+1, r));
}

void push(int node, int l, int r){
    seg[node<<1] += lz[node], seg[(node<<1)+1] += lz[node];
    lz[node<<1] += lz[node], lz[(node<<1)+1] += lz[node];
    lz[node] = 0;
}

int update(int node, int l, int r, int ul, int ur, int x){
    if(l != r and lz[node]) push(node, l, r);

    if(r < ul or l > ur) return seg[node];
    if(ul <= l and r <= ur){
        lz[node] += x;
        return seg[node] += x;
    }

    int m = (l+r)>>1;
    return seg[node] = max(update(node<<1, l, m, ul, ur, x), update((node<<1)+1, m+1, r, ul, ur, x));
}

int query(int node, int l, int r, int idx){
    if(idx < l or idx > r) return -INF;
    if(l == r) return seg[node];

    if(lz[node]) push(node, l, r);

    int m = (l+r)>>1;
    return max(query(node<<1, l, m, idx), query((node<<1)+1, m+1, r, idx));

}

int query2(int node, int l, int r, int x){
    if(l == r) return l;

    if(lz[node]) push(node, l, r);

    int m = l+(r-l)/2;
    if(seg[node<<1] >= x) return query2(node<<1, l, m, x);
    return query2((node<<1)+1, m+1, r, x);
}

void solve(){
    int n; cin >> n;
    set<int> st;
    rep(i, 0, n){
        int a; cin >> a;
        auto ub = st.upper_bound(a); st.insert(a);
        update(1, 0, MAX-1, a, (ub == st.end() ? MAX-1 : *(ub)-1), -query(1, 0, MAX-1, a));
    }

    int m; cin >> m;
    rep(i, 0, m){
        char c; int a; cin >> c >> a;
        if(c == '+'){
            auto ub = st.upper_bound(a); st.insert(a);
            update(1, 0, MAX-1, a, (ub == st.end() ? MAX-1 : *(ub)-1), -query(1, 0, MAX-1, a));
        } else if(c == '-'){
            auto ub = st.upper_bound(a); st.erase(a);
            update(1, 0, MAX-1, a, (ub == st.end() ? MAX-1 : *(ub)-1), query(1, 0, MAX-1, a-1)+1);
        } else{
            if(seg[1] < a) cout << *(st.rbegin())+1 << " ";
            else cout << query2(1, 0, MAX-1, a)-a+1 << " ";
        }
    }
    cout << endl;

    forr(x, st){
        auto ub = st.upper_bound(x);
        update(1, 0, MAX-1, x, (ub == st.end() ? MAX-1 : *(ub)-1), query(1, 0, MAX-1, x-1)+1);
    }
}

int main(){ _
    int ttt = 1; cin >> ttt;

    build(1, 0, MAX-1);

    while(ttt--) solve();

    exit(0);
}
