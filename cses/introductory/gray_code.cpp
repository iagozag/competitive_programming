#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<string> ans = {""};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (1<<i); j++)
            ans[j] += '0';
        for(int j = (1<<i)-1; j >= 0; j--) ans.emplace_back(ans[j]), ans[ans.size()-1][i] = '1';
    }
    for(auto x: ans) cout << x << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
