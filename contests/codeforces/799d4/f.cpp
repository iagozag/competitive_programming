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

set<vi> ok;

void solve(){
    int n; cin >> n;
    vector<int> cnt(10); 
    rep(i, 0, n){ string x; cin >> x; cnt[x[x.size()-1]-'0']++; }

    forr(x, ok){
        vi need(10);
        forr(y, x) need[y]++;

        bool can = true;
        rep(i, 0, 10) if(need[i] > cnt[i]) can = false;
        if(can) return yes();
    }
    return no();
}

int main(){ _
    int ttt; cin >> ttt;

    rep(i, 0, 10) rep(j, 0, 10) rep(k, 0, 10){
        string str = to_string(i+j+k);
        if(str[str.size()-1] == '3'){ 
            vi tmp = {i, j, k}; sort(all(tmp));
            ok.insert(tmp);
        }
    }

    while(ttt--) solve();

    exit(0);
}
