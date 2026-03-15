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
	int a[n], b[n], c[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) cin >> c[i];

	int cntab = 0, cntbc = 0;
	for(int j = 0; j < n; j++){
		bool ok = 1; int it1 = 0, it2 = j;
		for(int k = 0; k < n; k++) if(a[(it1+k)%n] >= b[(it2+k)%n]) ok = 0;
		if(ok) cntab++;
	}

	for(int j = 0; j < n; j++){
		bool ok = 1; int it1 = 0, it2 = j;
		for(int k = 0; k < n; k++) if(b[(it1+k)%n] >= c[(it2+k)%n]) ok = 0;
		if(ok) cntbc++;
	}

	cout << cntab*cntbc*n << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
