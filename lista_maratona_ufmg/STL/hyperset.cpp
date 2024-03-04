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
    int n, k; cin >> n >> k;
    vector<vector<char>> v(k, vector<char>(n));
    rep(i, 0, n) rep(j, 0, k) cin >> v[j][i];

    sort(all(v));

    rep(i, 0, n){
        rep(j, i+1, n){
            rep(l, 0, k){
                set<char> s; s.insert(v[l][i]); s.insert(v[l][j]);
                char c;
                if(s.size() == 1) c = *s.begin();
                else{
                    if(!s.count('S')) c = 'S';
                    else if(!s.count('E')) c = 'E';
                    else c = 'T';
                }


            }
        }
    }
}

int main(){ _
    int t = 1;

    while(t--) solve();

    exit(0);
}
