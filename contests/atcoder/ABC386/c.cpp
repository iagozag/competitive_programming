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
	int k; cin >> k;
	string s, t; cin >> s >> t; int n = s.size(), m = t.size();
	if(abs(n-m) > 1){ cout << "No" << endl; return; }
	if(n == m){
		int sum = 0;
		for(int i = 0; i < n; i++) sum += (s[i] != t[i]);
		if(sum <= 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	} else{
		if(n > m) swap(s, t), swap(n, m);

		string tmp = ""; bool can = 1;
		for(int i = 0; i < n; i++){
			if(s[i] != t[i] and can) tmp += t[i], can = 0;
			tmp += s[i];
		}
		if((int)tmp.size() < (int)t.size()) tmp += t.back();
		cout << (tmp == t ? "Yes" : "No") << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
