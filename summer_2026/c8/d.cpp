#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	string s, t; cin >> s >> t; int n = s.size(), m = t.size();

	map<char, int> qnt; int j = m-1;
	for(int i = n-1; i >= 0 and j >= 0; i--){
		if(s[i] == t[j]){
			if(qnt[s[i]]){ cout << "NO" << endl; return; }
			qnt[s[i]]--, j--;
		}

		qnt[s[i]]++;
	}

	cout << (j == -1 ? "YES" : "NO") << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


