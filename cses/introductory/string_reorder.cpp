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
	string s; cin >> s; int n = s.size();

	vector<int> qnt(26);
	for(int i = 0; i < n; i++) qnt[s[i]-'A']++;

	string ans = string(n+1, ' ');
	for(int i = 1; i <= n; i++){
		for(int c = 0; c < 26; c++) if(qnt[c]){
			char ch = c+'A';
			if(ans[i-1] == ch) continue;
			
			qnt[c]--;
			int ma = *max_element(qnt.begin(), qnt.end());
			if(ma <= (n-i+1)/2){ ans[i] = ch; break; }
			else qnt[c]++;
		}

		if(ans[i] == ' '){ cout << -1 << endl; return; }
	}

	for(int i = 1; i <= n; i++) cout << ans[i];
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
