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
	string s; cin >> s; bool can = 0;
	for(int i = 0; i < n; i++) if(s[i] == '1' and s[i+1] == '1') can = 1;

	if(s[0] == '1' or s[n-1] == '1' or can) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
