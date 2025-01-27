#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	string s; cin >> s;
	int n; cin >> n;

	int m = s.size(); int sum = 0;
	for(int i = 0; i < m; i++)
		if(s[i] == '1') sum += (1LL<<(m-i-1));

	if(sum > n){ cout << -1 << endl; return; }

	for(int i = 0; i < m; i++) if(s[i] == '?'){
		if(sum+(1LL<<(m-i-1)) <= n) s[i] = '1', sum += (1LL<<(m-i-1));
		else s[i] = '0';
	}
	cout << sum << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
