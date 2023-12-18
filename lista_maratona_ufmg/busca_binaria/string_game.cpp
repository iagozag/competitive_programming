#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

string st, res;
int n, rs; vi v;

bool check(int x){
    vector<bool> set(n);
    for(int i = 0; i < x; i++) set[v[i]-1] = 1; 
   
    int i = 0, j = 0;
    while(i < n && j < res.size()){
        if(!set[i] && st[i] == res[j]) j++;
        i++;
    }

    return j == res.size();
}

void solve(){
    cin >> st >> res;
    n = st.size(), rs = res.size();
    v = vi(n); for(auto& x: v) cin >> x;

    int l = 0, r = n, ans = 0;
    while(l <= r){
        int m = l+(r-l)/2;
        if(check(m)) ans = m, l = m+1;
        else r = m-1;
    }

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

