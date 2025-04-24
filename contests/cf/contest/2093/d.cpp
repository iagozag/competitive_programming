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
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		string op; cin >> op;
		int x, y, d;
		if(op == "->"){
			cin >> x >> y;

		} else{
			cin >> d; x = 1, y = 1;
			if(d > 4) d--;
			int x2 = 1LL<<n, y2 = 1LL<<n;
			while(x != x2 or y != y2){
				int div = (d >= 4 ? d/4 : d-1);
				int xmean = (x+x2)/2+1, ymean = (y+y2)/2+1;

				if(div == 0) x2 = xmean-1, y2 = ymean-1;
				else if(div == 1) x = xmean, y = ymean;
				else if(div == 2) x = xmean, y2 = ymean-1;
				else x2 = xmean-1, y = ymean;

				d /= 4;
			}

			cout << x << ' ' << y << endl;
		}
	}
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
