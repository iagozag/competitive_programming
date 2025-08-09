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
	int l, r; cin >> l >> r;
	int ans = r-l+1;

	vector<int> pr = {2, 3, 5, 7};
	for(int i = 1; i < 16; i++){
		int d = ((__builtin_popcount(i)&1) ? -1 : 1);
		int num = 1;
		for(int j = 0; j < 4; j++) if(i&(1<<j)) num *= pr[j];
		
		int dl = l/num, fl = num*dl;
		if(fl < l) fl += num;

		int dr = r/num, fr = num*dr;

		int sum = (fr-fl)/num;

		ans += sum*d;
	}

	cout << ans-1 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
