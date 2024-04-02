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

void solve(){
    int n; cin >> n;
    vi v(n); forr(x, v) cin >> x;
    map<int,tuple<int,int, int, int, int, int>> past;

    rep(i, 0, n){
        int c = v[i];
        if(!past.count(c)) past[c] = {1, i, i, i, i, 1};
        else{
            auto& [cur, bidxl, idxl, idxr, bidxr, ma] = past[c];
            int new_c = cur-(i-idxr-1);
            if(new_c >= 1){
                cur = new_c+1;
                if(ma < cur) ma = cur, bidxl = idxl, bidxr = i;
            }
            else cur = 1, idxl = i;
            idxr = i;
        }
    }

    int ans = -1, num = -1, bl = 0, br = n-1;
    forr(x, past) if(ans < get<5>(x.ss))
        num = x.ff, bl = get<1>(x.ss), br = get<4>(x.ss), ans = get<5>(x.ss);
    
    cout << num << " " << bl+1 << " " << br+1 << endl;
}

int main(){ _
    int ttt; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
