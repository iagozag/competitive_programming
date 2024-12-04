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
	int cnt = 0, i = 0;
	for(i = 0; i < (int)s.size(); i++){
		if(s[i] == '/') break;
		if(s[i] == '1') cnt++;
		else{ cout << "No" << endl; return; }
	}
	i++;
	for(; i < (int)s.size(); i++){
		if(s[i] == '2') cnt--;
		else{ cout << "No" << endl; return; }
	}
	if(cnt == 0) cout << "Yes" << endl;
	else cout << "No" << endl;

}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
