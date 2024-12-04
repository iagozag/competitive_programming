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
	vector<vector<int>> pos(k);
	for(int i = 0; i < m; i++) pos[s[i]-'a'].emplace_back(i);

	for(int i = 0; i < k; i++) if(pos[i].size() == 0) return no(string(n, (char)(i+'a')));
	
	string ans = ""; vector<bool> vis(k);
	for(int i = 0; i < m; i++) if(!vis[s[i]-'a']){
		vis[s[i]-'a'] = 1;
		for(int j = 0; j < k; j++){
			int ub = upper_bound(pos[j].begin(), pos[j].end(), i)-pos[j].begin();
			if(pos[j].size()-ub < n-1) return no(string(1, s[i])+string(n-1, j+'a'));
		}
	}

	cout << "YES" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
