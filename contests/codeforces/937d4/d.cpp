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

vl alls;
bool ok;

void get_all(string s, int n){
    if(s.size() == 5){
        string buffer = "";
        int i = 0; while(s[i] == '0') i++;
        rep(j, i, s.size()) buffer += s[j];
        if(buffer.size() == 0) return;
        int number = stoi(buffer);
        alls.eb(number); return; 
    } 

    get_all(s+'1', n+1), get_all(s+'0', n+1);
}

bool is_b(int n){
    string s = to_string(n);
    rep(i, 0, s.size()) if(s[i] != '0' and s[i] != '1') return false;
    return true;
}

void solve(){
    ll n; cin >> n;
    if(is_b(n) or n == 1) return yes();

    int ma = alls.size(); ll mult;
    rep(i, 0, ma){
        rep(j, 0, ma){
            mult = alls[i]*alls[j];
            if(mult > 100000) break;
            if(n/mult == 1 and n%mult == 0) return yes();
            rep(k, 0, ma){
                mult = alls[i]*alls[j]*alls[k];
                if(mult > 100000) break;
                if(n/mult == 1 and n%mult == 0) return yes();
                rep(l, 0, ma){
                    mult = alls[i]*alls[j]*alls[k]*alls[l];
                    if(mult > 100000) break;
                    if(n/mult == 1 and n%mult == 0) return yes();
                    rep(h, 0, ma){
                        mult = alls[i]*alls[j]*alls[k]*alls[l]*alls[h];
                        if(mult > 100000) break;
                        if(n/mult == 1 and n%mult == 0) return yes();
                    }
                }
            }
        }
    }
    return no();
}

int main(){ _
    int ttt; cin >> ttt;

    get_all("", 0);
    sort(all(alls));

    while(ttt--) solve();

    exit(0);
}
