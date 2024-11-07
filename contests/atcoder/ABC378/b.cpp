#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<ll> q(n), r(n);
	for(int i = 0; i < n; i++){
		cin >> q[i] >> r[i];
	}
	int Q; cin >> Q;
	for(int qq = 0; qq < Q; qq++){
		int i; ll d; cin >> i >> d; --i;
		cout << r[i]+q[i]*((max(d-r[i], 0LL)+q[i]-1)/q[i]) << endl;
	}
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
