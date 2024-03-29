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
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

bool comp(string s, string r){
    int cnt = 0, m = r.size();

    string buffer = "";
    rep(i, 0, s.size()/m) buffer += r;
    r = buffer;

    rep(i, 0, s.size()){
        if(s[i] != r[i]) cnt++;
        if(cnt > 1) return false;
    }
    return true;
}

void solve(){
    int n; cin >> n; string s; cin >> s;
    string buffer = ""; int mi = INF;
    rep(i, 0, s.size()){
        buffer += s[i]; int m = buffer.size();
        if(n%m == 0 and comp(s, buffer)){ 
            mi = min(mi, m); 
        }
    }
    reverse(all(s)); buffer = "";
    rep(i, 0, s.size()){
        buffer += s[i]; int m = buffer.size();
        if(n%m == 0 and comp(s, buffer)){ 
            mi = min(mi, m);
        }
    }
    cout << mi << endl;
}

int main(){ _
    int ttt; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
