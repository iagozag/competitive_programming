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
    int n, k; cin >> n >> k; k *= 2;
    vi v(2*n); forr(x, v) cin >> x;

    map<int, int> mp;
    rep(i, 0, n) mp[v[i]]++;
    int tmp = k;
    forr(x, mp) if(x.ss == 2 and tmp) cout << x.ff << " " << x.ff << " ", tmp -= 2;
    vi rest;
    if(tmp){ forr(x, mp) if(x.ss == 1 and tmp) cout << x.ff << " ", rest.eb(x.ff), tmp--; }
    cout << endl;
    mp.clear();
    rep(i, n, 2*n) mp[v[i]]++;
    tmp = k;
    forr(x, mp) if(x.ss == 2 and tmp) cout << x.ff << " " << x.ff << " ", tmp -= 2;
    if(tmp) forr(x, rest) cout << x << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
