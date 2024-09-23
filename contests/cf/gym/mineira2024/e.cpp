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
typedef pair<long double, long double> ii;
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

#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

double dist(long double x1, long double y1, long double x2, long double y2){
    return sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
}

bool check(ii p1, ii p2, ii p3){
    long double a = dist(p1.ff, p1.ss, p2.ff, p2.ss), b = dist(p2.ff, p2.ss, p3.ff, p3.ss), c = dist(p1.ff, p1.ss, p3.ff, p3.ss);
    if(a+b <= c or a+c <= b or b+c <= a) return false;
    return true;
}

void solve(){
    ll n; cin >> n;
    vector<pair<ii, ll>> v(n); rep(i, 0, n) cin >> v[i].ff.ff >> v[i].ff.ss, v[i].ss = i+1;
    sort(all(v));
    
    vl ans = { v[0].ss, v[1].ss };
    rep(i, 2, n){
        if(check(v[0].ff, v[1].ff, v[i].ff)){ ans.eb(v[i].ss); break; }
    }

    rep(i, 0, ans.size()) cout << ans[i] << " \n"[i == 2]; 
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
