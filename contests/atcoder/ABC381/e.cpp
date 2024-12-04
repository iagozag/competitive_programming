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
	int n, q; cin >> n >> q;
	string s; cin >> s;
	vector<vector<int>> pos(3);
	for(int i = 0; i < n; i++) pos[s[i] == '1' ? 0 : s[i] == '/' ? 1 : 2].emplace_back(i);

	for(int i = 0; i < q; i++){
		int L, R; cin >> L >> R; L--, R--;
		int l = 1, r = (R-L+1)/2, ans = 0;
		while(l <= r){
			int m = l+(r-l)/2;

			int lb = lower_bound(pos[0].begin(), pos[0].end(), L)-pos[0].begin();
			lb += m-1;

			if(lb >= (int)pos[0].size() or pos[0][lb] > R){ r = m-1; continue; }

			int ub1 = upper_bound(pos[1].begin(), pos[1].end(), pos[0][lb])-pos[1].begin();
			
			if(ub1 >= (int)pos[1].size() or pos[1][ub1] > R){ r = m-1; continue; }

			int ub2 = upper_bound(pos[2].begin(), pos[2].end(), pos[1][ub1])-pos[2].begin();
			ub2 += m-1;
			
			if(ub2 >= (int)pos[2].size() or pos[2][ub2] > R){ r = m-1; continue; }

			l = m+1, ans = m;
		}

		if(ans == 0){
			int lb = lower_bound(pos[1].begin(), pos[1].end(), L)-pos[1].begin();
			if(lb < (int)pos[1].size() and pos[1][lb] <= R) cout << 1 << endl;
			else cout << 0 << endl;
		} 
		else cout << 2*ans+1 << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
