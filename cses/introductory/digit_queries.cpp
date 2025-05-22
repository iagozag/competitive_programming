#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef unsigned long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int Q; cin >> Q;
	for(int q = 0; q < Q; q++){
		int k; cin >> k;
		if(k <= 9){ cout << k << endl; continue; }

		int qnt = 1, sum = 0, pot = 1;
		while(sum+9*pot*qnt < k) sum += 9*pot*qnt, pot *= 10, qnt++;
		k -= sum+1;

		int num = (qnt == 1 ? 0 : pot) + k/qnt;
		string s = to_string(num);
		cout << s[k%qnt] << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
