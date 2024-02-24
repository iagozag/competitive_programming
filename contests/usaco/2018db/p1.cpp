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
    int ca, aa, cb, ab, cc, ac; cin >> ca >> aa >> cb >> ab >> cc >> ac;
    
    rep(i, 0, 33){
        if(ab+aa > cb) aa-=cb-ab, ab = cb;
        else ab+=aa, aa = 0;
        if(ac+ab > cc) ab-=cc-ac, ac = cc;
        else ac+=ab, ab = 0;
        if(aa+ac > ca) ac-=ca-aa, aa = ca;
        else aa+=ac, ac = 0;
    }
    if(ab+aa > cb) aa-=cb-ab, ab = cb;
    else ab+=aa, aa = 0;

    cout << aa << endl << ab << endl << ac << endl;
}

int main(){ _
    if (fopen("mixmilk.in", "r")) {
		freopen("mixmilk.in", "r", stdin);
		freopen("mixmilk.out", "w", stdout);
	}

    int t = 1;

    while(t--) solve();

    exit(0);
}

