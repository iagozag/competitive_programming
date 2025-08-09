#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int query(int op, int n){
	cout << (op ? 'C' : 'L') << ' ' << n << endl;
	int ans; cin >> ans;
	return ans;
}

void solve(){
	int n; cin >> n;
	int f = query(0, 1), j = 1;
	bool b = 1;
	while(f != 0 and f != n){
		query(1, j);
		int s = query(0, 1);

		if(b and s > n-f) query(1, j), s--;
		else if(!b and s < n-f) query(1, j), s++;

		j++, b = !b, f = s;
	}

	if(f == 0) query(0, 1);

	for(int i = 2; i <= n; i++)
		if(query(0, i) == 0) query(0, i);

	cout << "FIM" << endl;
}

int32_t main(){ // _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
