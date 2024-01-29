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

void solve(){
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;
    vector<vi> pref(k, vi(m));
    pref[s[m-1]-'a'][m-1] = 1;

    repr(i, m-2, 0){
        pref[s[i]-'a'][i] = pref[s[i]-'a'][i+1]+1;
        rep(j, 0, k){
            if(j == s[i]-'a') continue;
            pref[j][i] = pref[j][i+1];
        }
    }

    for(int i = 0; i < k; i++){
        for(int j = 0; j < m; j++) cout << pref[i][j] << " ";
        cout << endl;
    } 

    rep(i, 0, k){
        if(pref[i][0] < n){
            cout << "NO" << endl << string(n, i+'a') << endl;
            return;
        }

        int l = 0, r = m-1, idx;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(pref[i][mid] < pref[i][0]) r = mid-1;
            else idx = mid, l = mid+1;
        }

        rep(j, 0, k){
            if(i == j) continue;
            if(pref[j][idx] < n-1){
                cout << "NO" << endl << char(i+'a') << string(n-1, j+'a') << endl;
                return;
            }
        } 
    }

    cout << "YES" << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
