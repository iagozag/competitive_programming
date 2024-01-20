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

void solve(){
    int n, ans = 0; cin >> n;
    vi a(n), b(n), c(n); 
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
  
    vi idxa(n), idxb(n), idxc(n);
    iota(all(idxa), 0); iota(all(idxb), 0); iota(all(idxc), 0);
    sort(all(idxa),
        [&](int i, int j){
            return a[i] > a[j];
        });
    sort(all(idxb),
        [&](int i, int j){
            return b[i] > b[j];
        });
    sort(all(idxc),
        [&](int i, int j){
            return c[i] > c[j];
        });

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++){
                int ia = idxa[i], ib = idxb[j], ic = idxc[k];
                if(ia != ib && ib != ic && ia != ic)
                    ans = max(ans, a[ia]+b[ib]+c[ic]);
            }

    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

