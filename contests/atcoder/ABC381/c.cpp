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
	string s; cin >> s;

	int ans = 1;
	for(int i = 0; i < n; i++) if(s[i] == '/'){ 
		int l = i-1, r = i+1; int ma = 1;
		while(l >= 0 and r < n and s[l] == '1' and s[r] == '2') l--, r++, ma += 2;
		ans = max(ans, ma);
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
