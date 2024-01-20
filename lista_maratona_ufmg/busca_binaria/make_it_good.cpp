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

int n; 
vi v;

bool check(int m){
    int prev, l = m, r = n-1;
    if(v[l] > v[r]) prev = v[r], r--;
    else prev = v[l], l++;

    while(l <= r){
        if(prev > min(v[l], v[r])) return false;

        if(v[l] < v[r]) prev = v[l], l++;
        else prev = v[r], r--;
    }

    return true;
}

void solve(){
    cin >> n;
    v = vi(n); for(auto& x: v) cin >> x;

    int l = 0, r = n-1, ans;
    while(l <= r){
        int m = l+(r-l)/2;
        if(check(m)) ans = m, r = m-1;
        else l = m+1;
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

