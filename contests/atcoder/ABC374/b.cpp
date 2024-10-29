#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    string s, t; cin >> s >> t;
    if(s == t){ cout << 0 << endl; return; }
    for(int i = 0; i < min(s.size(), t.size()); i++) if(s[i] != t[i]){ cout << i+1 << endl; return; }
    cout << min(s.size(), t.size())+1 << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
