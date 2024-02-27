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

struct cmp{
    bool operator ()(const ii& a, const ii& b) const{
        if(a.ff != b.ff) return a.ff < b.ff;
        return a.ss < b.ss;
    }
};

struct cmp2{
    bool operator ()(const ii& a, const ii& b) const{
        if(a.ss != b.ss) return a.ss < b.ss;
        return a.ff < b.ff;
    }
};

void solve(){
    int q; cin >> q;

    map<ii,int,cmp> mp; map<ii,int,cmp2> mp2;
    rep(i, 0, q){
        char c; int a, b; cin >> c >> a >> b;
        if(c == '+') mp[{a, b}]++, mp2[{a, b}]++;
        else{
            mp[{a, b}]--, mp2[{a, b}]--;
            if(mp[{a, b}] == 0) mp.erase({a, b}), mp2.erase({a, b});
        }
        
        cout << (mp.size() > 1 and mp.rbegin()->ff.ff > mp2.begin()->ff.ss ? "YES\n" : "NO\n");
    }
}

int main(){ _
    int t = 1;

    while(t--) solve();

    exit(0);
}
