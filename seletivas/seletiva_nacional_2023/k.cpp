#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "IMPOSSIBLE" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int k; cin >> k;
    string s; cin >> s;
    int n = sz(s);
    int qnt = 0; 
    set<char> st;
    rep(i, 0, k) st.insert('a'+i);
    int i = 0, j = n-1;
    while(i <= j){
        if(st.count(s[i])) st.erase(s[i]);
        if(st.count(s[j])) st.erase(s[j]);
        if(s[i] != '?' and s[j] != '?'){ if(s[i] != s[j]) return no(); }
        else if(s[i] == '?' and s[j] != '?') s[i] = s[j];
        else if(s[j] == '?' and s[i] != '?') s[j] = s[i];
        else qnt++;
        i++, j--;
    }

    if(st.size() > qnt) return no();

    int need = st.size();
    i = 0, j = n-1;
    while(i <= j){
        if(s[i] == '?'){
            if(need < qnt) s[i] = s[j] = 'a';
            else s[i] = s[j] = *st.begin(), st.erase(*st.begin());
            qnt--;
        }
        i++, j--;
    }
    
    cout << s << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
