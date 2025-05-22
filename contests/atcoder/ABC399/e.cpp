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
	int n; cin >> n;
	string s, t; cin >> s >> t;
	vector<int> a, b;
	for(auto c: s) a.emplace_back(c-'a');
	for(auto c: t) b.emplace_back(c-'a');

	vector<int> match(26, -1);
	for(int i = 0; i < n; i++){
		if(match[a[i]] == -1) match[a[i]] = b[i];
		else if(match[a[i]] != b[i]){ cout << -1 << endl; return; }
	}

	int ans = 0;
	for(int i = 0; i < 26; i++) ans += (match[i] != -1 and match[i] != i);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
