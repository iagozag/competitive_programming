#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
#define eb emplace_back

typedef long long ll;
typedef unsigned long long int ull;
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

const int MAX = 5e6+1;

vector<bool> bs(MAX, 1);
vl primefact(MAX, 1);
vl pref(MAX, 1);

void sieve(){
    bs[0] = bs[1] = 0;
    primefact[0] = primefact[1] = 0;

    for(ll i = 2; i < MAX; i++){
        if(bs[i])
            for(ll j = i*i; j < MAX; j += i)
                bs[j] = false, primefact[j] = primefact[i]+primefact[j/i]; 
    }
}

void solve(){
    ll a, b; cin >> a >> b;
    cout << pref[a]-pref[b] << endl;
}

int main(){ _
    int t; cin >> t;

    sieve();

    pref[1] = 0;
    rep(i, 2, MAX) pref[i] = pref[i-1]+primefact[i];

    while(t--) solve();

    exit(0);
}
