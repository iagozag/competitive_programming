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

void solve(){
    int n, m, x; cin >> n >> m >> x;

    set<int> pp; pp.insert(x);
    rep(i, 0, m){
        int t; char c; cin >> t >> c;

        set<int> tmp;
        forr(y, pp){
            int cw = y+t, ccw = y-t;
            if(cw > n) cw -= n;
            if(ccw <= 0) ccw += n;

            if(c == '?'){
                tmp.insert(cw);
                tmp.insert(ccw);
            }
            else if(c == '0') tmp.insert(cw);
            else tmp.insert(ccw);
        }

        pp = tmp;
    }
    
    cout << pp.size() << endl;
    forr(y, pp) cout << y << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
