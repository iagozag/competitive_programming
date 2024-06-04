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

vector<string> v(7);
vector<ii> moves = {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}};

bool is_valid(int i, int j){
    return i >= 0 and i < 7 and j >= 0 and j < 7 and v[i][j] == 'B';
}

bool is_center(int i, int j){
     for(auto u: moves) if(!is_valid(u.ff+i, u.ss+j)) return false;
     return true;
}

struct cmp{
    bool operator() (pair<ii, int>& a, pair<ii, int>& b) {
        return a.ss > b.ss;
    }
};

void solve(){
    rep(i, 0, 7) cin >> v[i]; 
    vector<vi> qnt(7, vi(7));

    rep(i, 1, 6) rep(j, 1, 6)
        if(v[i][j] == 'B'){
            if(!is_center(i, j)) continue;
            qnt[i][j]++; for(auto u: moves) qnt[u.ff+i][u.ss+j]++;
        }

    set<pair<ii, int>, cmp> st;
    rep(i, 0, 7) rep(j, 0, 7)
        st.insert({{i, j}, qnt[i][j]});

    while(st.begin()->second > 0){
        auto it = st.begin();
        int i = it->ff.ff, j = it->ff.ss;
        if(is_center(i, j)){
            st.insert({{i, j}, it->ss-1});
            st.erase(it);

            for(auto u: moves)
        }
    }
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
