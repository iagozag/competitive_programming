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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(n <= 2){ cout << stoi(s) << endl; return; }

    vector<vi> pos(n-1);
    rep(i, 0, n-1){
        rep(j, 0, n){
            string a = "";
            if(i == j){
                a += s[j]; a += s[j+1];
                pos[i].eb(stoi(a));
                j++;
            }
            else a += s[j], pos[i].eb(stoi(a));
        }
    }

    int mi = INF;
    rep(i, 0, n-1){
        int sum = 0;
        forr(x, pos[i]){
            if(x == 0){ sum = 0; break; }
            else if(x == 1) continue;
            sum += x;
        }
        set<int> st(all(pos[i]));
        if(st.size() == 1 and *st.begin() == 1) sum = 1;
        mi = min(mi, sum);
    }

    cout << mi << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
