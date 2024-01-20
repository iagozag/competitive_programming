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

string st; int n;
// {A, H, I, M, O, T, U, V, W, X, Y}
unordered_set<char> let = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

bool is_pal(string str){
    for(int i = 0, j = str.size()-1; i <= j; i++, j--)
        if(str[i] != str[j] || !let.count(str[i])) return false;

    return true;
}

bool check(int x){
    int l = 0;
    while(l+x-1 < n){
        if(is_pal(st.substr(l, x))) return true;
        l++;
    }

    return false;
}

int bin_search(vi& v){
    int l = 0, r = v.size()-1, ans;
    while(l <= r){
        int m = l+(r-l)/2;
        if(check(v[m])) ans = v[m], l = m+1;
        else r = m-1;
    }

    return ans;
}

void solve(){
    cin >> st; n = st.size();
    vi odd, even;
    for(int i = 0; i <= n; i++){
        if(i&1) odd.pb(i);
        else even.pb(i);
    }

    cout << max(bin_search(odd), bin_search(even)) << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

