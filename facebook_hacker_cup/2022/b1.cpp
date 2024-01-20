#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
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


void solve(){
    int r, c; cin >> r >> c;
    vector<string> v(r);
    rep(i, 0, r) cin >> v[i];

    bool has_t = false;
    rep(i, 0, r) rep(j, 0, c)
        has_t = has_t || v[i][j] == '^';

    if((r == 1 || c == 1) && has_t){
        if(has_t) cout << "Impossible\n";
        else{
            cout << "Possible\n";
            rep(i, 0, r) cout << v[i] << endl;
        }

        return;
    }

    cout << "Possible\n";
    rep(i, 0, r){
        rep(j, 0, c) cout << '^';
        cout << endl;
    }
}

int main(){ _
    int t; cin >> t;
    rep(i, 1, t+1){
        cout << "Case #" << i << ": ";
        solve();
    }

    exit(0);
}


