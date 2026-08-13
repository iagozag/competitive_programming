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

int n;
vi v;

pair<vi, ll> get_ans(int mid){
    vi pos(n); pos[mid] = v[mid]; ll sum = v[mid];
    int l = mid-1, r = mid+1;
    while(l >= 0 or r < n){
        if(l >= 0) pos[l] = min(v[l], pos[l+1]), sum += pos[l], l--;
        if(r < n) pos[r] = min(v[r], pos[r-1]), sum += pos[r], r++;
    }

    return {pos, sum};
}

void solve(){
    cin >> n;
    v = vi(n); forr(x, v) cin >> x;

    vi ans; ll sum = 0;
    rep(i, 0, n){
        pair<vi, ll> pos = get_ans(i);
        if(pos.ss > sum) sum = pos.ss, ans = pos.ff;
    }

    forr(x, ans) cout << x << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
