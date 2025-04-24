#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){
	cout << "NO" << endl;
}

void solve(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	for(int i = 0; i < n-1; i++){
		bool can = 0;
		for(int j = min(n-1, i+k); j > i; j--) if(s[j] == '.'){ i = j-1, can = 1; break; }
		if(!can) return no();
	}

	cout << "YES" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
