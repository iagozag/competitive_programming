#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
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
    vector<string> v(10); forr(x, v) cin >> x;
    ii idxb, idxl, idxr;
    rep(i, 0, 10) rep(j, 0, 10){
        if(v[i][j] == 'B') idxb = {i, j};
        else if(v[i][j] == 'L') idxl = {i, j};
        else if(v[i][j] == 'R') idxr = {i, j};
    }

    int ans = abs(idxl.ff-idxb.ff)+abs(idxl.ss-idxb.ss);
    if((idxl.ff == idxb.ff or idxl.ss == idxb.ss) and 
        ans == abs(idxr.ff-idxb.ff)+abs(idxr.ss-idxb.ss)+abs(idxl.ff-idxr.ff)+abs(idxl.ss-idxr.ss)) 
        cout << ans+1;
    else cout << ans-1;
    cout << endl;
}

int main(){ _
    if (fopen("buckets.in", "r")) {
		freopen("buckets.in", "r", stdin);
		freopen("buckets.out", "w", stdout);
	}

    int t = 1;

    while(t--) solve();

    exit(0);
}
