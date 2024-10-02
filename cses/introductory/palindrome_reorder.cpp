#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    map<char, int> mp;
    string s; cin >> s;
    for(auto x: s) mp[x]++;
    int odd = 0; char c;
    for(auto x: mp) if(x.second&1) odd++, c = x.first;
    if(odd > 1){ cout << "NO SOLUTION" << endl; return; }
    
    int n = s.size();
    string ans = string(n, '0');
    if(n&1) ans[n/2] = c, mp[c]--;

    int i = 0, j = n-1;
    for(auto x: mp){
        while(x.second) ans[i++] = x.first, ans[j--] = x.first, x.second -= 2;
    }
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
