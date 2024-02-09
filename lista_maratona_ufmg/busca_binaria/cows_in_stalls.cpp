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

const int MAX = 1e5+10;

int n, k;
vi v, pref;

bool check(int x){
    int c = 1, d = 0, i = 0;
    while(true){
        i = upper_bound(pref.begin()+i, pref.end(), d+x)-pref.begin();
        
        if(i == n){
            if(pref[i-1] >= d+x) c++;
            break;
        }

        d = pref[i-1] >= d+x ? pref[i-1] : pref[i], c++;
    } 

    return c >= k;
}

void solve(){
    cin >> n >> k;

    v = pref = vi(n);
    cin >> v[0];

    int prev = v[0], mi = INF;
    rep(i, 1, n) cin >> v[i], mi = min(mi, v[i]-prev), prev = v[i], pref[i] = v[i]-v[0];

    int l = mi, r = 1e9, ans;
    while(l <= r){
        int m = l+(r-l)/2;
        if(check(m)) l = m+1, ans = m;
        else r = m-1;
    }

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
