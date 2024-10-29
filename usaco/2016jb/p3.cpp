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
    int n; cin >> n;
    map<ii, int> mp;
    map<char, ii> moves = {{'N', {1, 0}}, {'S', {-1, 0}}, {'W', {0, -1}}, {'E', {0, 1}}};

    ii cord = {0, 0}; int t = 0, ans = INF; mp[cord] = t;
    rep(i, 0, n){
        char c; int m; cin >> c >> m;
        while(m--){
            cord.ff+=moves[c].ff, cord.ss += moves[c].ss, t++;
            if(mp.count(cord)) ans = min(ans, t-mp[cord]);
            mp[cord] = t;
        } 
    }

    cout << (ans == INF ? -1 : ans) << endl;
}

int main(){ _
    if (fopen("mowing.in", "r")) {
		freopen("mowing.in", "r", stdin);
		freopen("mowing.out", "w", stdout);
	}

    int t = 1;

    while(t--) solve();

    exit(0);
}

