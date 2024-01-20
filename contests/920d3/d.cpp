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
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    forr(a) cin >> x;
    forr(b) cin >> x;

    sort(all(a)), sort(all(b));

    int la = 0, ra = n-1, lb = 0, rb = m-1; ll ans = 0;
    rep(i, 0, n){
        int l = abs(b[lb]-a[la]),
            r = abs(b[rb]-a[la]),
            l1 = abs(b[lb]-a[ra]),
            r1 = abs(b[rb]-a[ra]);
        vi v = {l, r, l1, r1};

        int ma = max_element(all(v))-v.begin();
        switch(ma){
            case 0:
                lb++, la++, ans += l;
                break;
            case 1:
                rb--, la++, ans += r;
                break;
            case 2:
                lb++, ra--, ans += l1;
                break;
            case 3:
                rb--, ra--, ans += r1;
                break;
        }
    }

    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
