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
#define pb push_back
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

void no(){ cout << "NO" << endl; }
void yes(double ans){ cout << fixed << setprecision(6) << ans << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n, k;
vector<double> s, d;

double f(double t){
    vector<double> values; 
    rep(i, 0, n) values.eb(d[i]+t*s[i]);
    double ma = -1, mi = INF;
    forr(x, values) ma = max(ma, x), mi = min(mi, x);
    return ma-mi;
}

void solve(){
    cin >> n >> k; s = d = vector<double>(n);
    rep(i, 0, n) cin >> s[i] >> d[i];

    double l = 0, r = k;
    rep(i, 0, 100){
        double ml = l+(r-l)/3.0, mr = r-(r-l)/3.0;
        double a1 = f(ml), a2 = f(mr);
        if(a1 > a2) l = ml;
        else r = mr;
    }

    cout << fixed << setprecision(6) << f(l) << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
