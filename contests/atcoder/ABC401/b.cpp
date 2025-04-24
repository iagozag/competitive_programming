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
	int cnt = 0, login = 0;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		if(s == "login") login = 1;
		else if(s == "logout") login = 0;
		else if(s == "private") cnt += !login;
	}

	cout << cnt << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
