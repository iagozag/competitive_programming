#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(string ans){ cout << "NO" << endl << ans << endl; }

void solve(){
	int n, m, k; cin >> n >> k >> m;
	string s; cin >> s;
	vector<vector<int>> nxt(m+1, vector<int>(k, m));
	for(int i = m-1; i >= 0; i--){
		for(int j = 0; j < k; j++) nxt[i][j] = nxt[i+1][j];
		nxt[i][s[i]-'a'] = i;
	}

	string ans = ""; char f;
	int cur = -1;
	for(int i = 0; i < n; i++){
		int let = 0;
		for(int j = 1; j < k; j++) if(nxt[cur+1][j] > nxt[cur+1][let]) let = j;

		if(nxt[cur+1][let] == m){ f = let+'a'; break; }
		cur = nxt[cur+1][let];

		ans += s[cur];
	}

	if(ans.size() == n){ cout << "YES" << endl; return; }

	ans += string(n-(int)ans.size(), f);

	cout << "NO" << endl << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
