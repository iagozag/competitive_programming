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
    int n; cin >> n;
    vi v(n); forr(v) cin >> x;

    vector<vi> pref(n+1, vi(30)); 
    rep(i, 0, n)
        rep(j, 0, 30){
            if(v[i] & (1<<j)) pref[i+1][j] = pref[i][j]+1;
            else pref[i+1][j] = pref[i][j];
        }

    // rep(i, 0, n){ rep(j, 0, 30) cout << pref[i][j] << " "; cout << endl; }

    int m; cin >> m;
    rep(i, 0, m){
        int l, k; cin >> l >> k; l--;
        if(v[l] < k){ cout << -1 << " "; continue; }

        int ll = l, r = n, ans;
        while(ll <= r){
            int m = ll+(r-ll)/2, sum = 0;
            rep(j, 0, 30){
                if(pref[m][j]-pref[l][j] == m-l) sum += (1<<j);
            }

            if(sum >= k) ans = m, ll = m+1;
            else r = m-1;
        }

        cout << ans << " ";
    }

    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
