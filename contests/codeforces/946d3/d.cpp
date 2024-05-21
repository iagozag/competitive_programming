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
    map<char, int> mp;
    rep(i, 0, n) mp[s[i]]++;

    if(s == "SN" or s == "NS" or s == "WE" or s == "EW") return no();

    vector<pii> ans(4);
    ans[0] = {mp['N']/2, mp['N']/2};
    if(mp['N']&1){
        if(!mp['S']) return no();
        ans[0].ff++, ans[1].ff++, mp['S']--;
    }

    if(mp['S']&1) return no();
    ans[1].ff += mp['S']/2, ans[1].ss += mp['S']/2;

    ans[2] = {mp['E']/2, mp['E']/2};
    if(mp['E']&1){
        if(!mp['W']) return no();
        ans[2].ss++, ans[3].ss++, mp['W']--, mp['E'] = 0;
    }
    if(mp['W']&1) return no();
    ans[3].ss += mp['W']/2, ans[3].ff += mp['W']/2;

    map<char, int> pos; pos['N'] = 0, pos['S'] = 1, pos['E'] = 2, pos['W'] = 3;

    rep(i, 0, n){
        if(ans[pos[s[i]]].ff) cout << 'R', ans[pos[s[i]]].ff--;
        else cout << 'H';
    }
    cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
