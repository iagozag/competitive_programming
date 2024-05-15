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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}


bool is_pal(string s){
    int n = sz(s);
    for(int i = 0, j = n-1; i < j; i++, j--) if(s[i] != s[j]) return false;
    return true;
}

void solve(){
    string s; cin >> s;
    string str = s; str += '$', str += string(s.rbegin(), s.rend());

    int n = sz(str), m = sz(s);
    // cout << n << " " << m << endl;
    vi z(n); int l = 0, r = 0;
    rep(i, 1, n){
        if(i < r) z[i] = min(r-i, z[i-l]);
        while(i+z[i] < n and str[z[i]] == str[i+z[i]]) z[i]++;
        if(i+z[i] > r) l = i, r = i+z[i];
    }

    string a = s.substr(0, z[m+1]), b = s.substr(m-z[m+1]);

    cout << a+b << endl;
}

int main(){ _
    int ttt; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
