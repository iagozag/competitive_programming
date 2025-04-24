#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void alice(){
	cout << "Alice" << endl;
}
void bob(){
	cout << "Bob" << endl;
}
void draw(){
	cout << "Draw" << endl;
}

void solve(){
	int h, w, a[2], b[2]; cin >> h >> w >> a[0] >> a[1] >> b[0] >> b[1];
	if(a[0] >= b[0]) return draw();

	if((b[0]-a[0])&1){
		while(a[0] <= b[0]){
			if(a[1] != b[1]){
				a[1] += (a[1] < b[1] ? 1 : -1);
				a[1] = max(a[1], 1LL);
				a[1] = min(a[1], w);
			}
			a[0]++;
			a[0] = min(a[0], h);

			if(a[0] == b[0] and a[1] == b[1]) return alice();

			b[1] += (b[1] < a[1] ? -1 : 1);
			b[1] = max(b[1], 1LL);
			b[1] = min(b[1], w);
			b[0]--;
			b[0] = max(b[0], 1LL);
		}
	} else{
		while(a[0] <= b[0]){
			a[1] += (a[1] < b[1] ? -1 : 1);
			a[1] = max(a[1], 1LL);
			a[1] = min(a[1], w);
			a[0]++;
			a[0] = min(a[0], h);

			if(b[1] != a[1]){
				b[1] += (b[1] < a[1] ? 1 : -1);
				b[1] = max(b[1], 1LL);
				b[1] = min(b[1], w);
			}
			b[0]--;
			b[0] = max(b[0], 1LL);

			if(a[0] == b[0] and a[1] == b[1]) return bob();

		}
	}
	return draw();
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
