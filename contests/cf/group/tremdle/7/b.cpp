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
	vector<int> cnt(101);
	for(int i = l; i <= r; i++) cnt[i]++;

	int qnt = r-l+1, can = 1;
	while(qnt > 1 and can){
		can = 0;
		for(int i = 1; i <= r; i++) if(cnt[i]){
			if(cnt[i] > 1){ can = 1, qnt--, cnt[i]--; break; }

			bool ok = 0;
			for(int j = i+1; j <= r; j++) if(cnt[j] and (i+j)%2 == 0){
				cnt[i]--, cnt[j]--, cnt[(i+j)/2]++, qnt--, ok = 1, can = 1;
				break;
			}

			if(ok) break;
		}
	}

	int ans = -1;
	for(int i = r; i >= l; i--) if(cnt[i]){ ans = i; break; }
	cout << (qnt == 1 ? ans : -1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
