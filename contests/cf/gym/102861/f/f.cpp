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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    string s; cin >> s;
    int c1 = 0, c2 = 0, s1 = 0, s2 = 0;
    int t = 1;
    int w = 0;
    forr(x, s){
        if(x == 'Q'){
            if(w){
                cout << s1 << (w == 1 ? " (winner)" : "") << " - " << 
                        s2 << (w == 2 ? " (winner)" : "") << endl;
            }
            else cout << s1 << " (" << c1 << (t==1 ? "*" : "") << ") - " << s2 << " (" <<
                    c2 << (t==2 ? "*" : "") << ")" << endl;
        } else{
            if(x == 'R') t = (t == 1 ? 2 : 1);
            if(t == 1){
                c1++;
                if(c1 == 10 or (c1 >= 5 and c1-c2 >= 2)) s1++, c1 = 0, c2 = 0;
            } else{
                c2++;
                if(c2 == 10 or (c2 >= 5 and c2-c1 >= 2)) s2++, c2 = 0, c1 = 0;
            }

            if(s1 == 2) w = 1;
            else if(s2 == 2) w = 2;
        }
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
