#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

set<string> ans;
string s;

void create(string now, int vis){
    if(now.size() == s.size()){ ans.insert(now); return; }
    for(int i = 0; i < s.size(); i++)
        if(!(vis&(1<<i))) create(now+s[i], vis|(1<<i));
}

void solve(){
    cin >> s;
    create("", 0);

    cout << ans.size() << endl;
    for(auto x: ans) cout << x << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
