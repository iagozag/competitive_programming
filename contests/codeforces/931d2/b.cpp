#include <bits/stdc++.h>
#include <sys/types.h>
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

const int MAX = 1e9+1;

// 8 5
// 35

void solve(){
    int n; cin >> n; int m = n%15;
    if(m == 0) cout << n/15;
    else if(m == 14) cout << n/15+3;
    else if(m == 13 or m == 11 or m == 9 or m == 7 or m == 4) cout << n/15+2;
    else if(m%3 == 0) cout << n/15+m/6+(m-(m/6)*6)/3;
    else if(m == 10) cout << n/15+1;
    else if(m == 8) cout << (n > 15 ? n/15+2 : 3);
    else if(m == 5) cout << (n > 15 ? n/15+1 : 3);
    else if(m<=2) cout << n/15+m;

    cout << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
