#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    string s; cin >> s;
    string in = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<char, int> mp;
    for(int i = 0; i < s.size(); i++) mp[s[i]] = i;
    int ans = 0, beg = mp['A'];
    for(int i = 0; i < in.size(); i++){
        ans += abs(beg-mp[in[i]]), beg = mp[in[i]]; 
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
