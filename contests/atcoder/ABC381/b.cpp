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
	int n = s.size(); set<char> st;
	for(int i = 0; i < n; i += 2){
		if(st.count(s[i]) or s[i] != s[i+1]){ cout << "No" << endl; return; }
		st.insert(s[i]);
	}

	cout << "Yes" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
