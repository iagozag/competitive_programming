#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10, MOD = 1e9+7;

vector<int> divv(MAX);

void solve(){
	int n, k; cin >> n >> k;

	int m = n-1, d = 1, cnt = 0;
	cout << k << ' ';
	for(int i = 1; i < n; i++, m--, d++){
		cnt += divv[m], cnt -= divv[d];
		cout << k*(cnt == 0) << ' ';
	}

	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	for(int i = 2; i < MAX; i += 2) divv[i] = divv[i/2]+1;

    while(ttt--) solve();

    exit(0);
}
