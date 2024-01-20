#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<long double, long double> pp;

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

int n, MAX = 1e5+10;
vi d(MAX), v(MAX);

bool check(float t){
    long double maxx = -LINF, minn = LINF;
    rep(i, 0, n){
        long double dleft = d[i]-t*v[i], dright = d[i]+t*v[i];
        // dbg(t, x.f, x.s, intersec.f, intersec.s);

        if(dleft > minn || dright < maxx) return false;

        maxx = max(maxx, dleft), minn = min(minn, dright);
    }

    return true;
}

void solve(){
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d%d", &d[i], &v[i]);

    double l = 0, r = 1e9+10, m, eps = 1e-7;
    while(r-l >= eps){
        m = l+(r-l)/2;
        if(check(m)) r = m;
        else l = m;
    }

    printf("%.20f\n", l+(r-l)/2); 
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

