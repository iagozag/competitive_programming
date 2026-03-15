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
	int n, w, h, s; cin >> n >> w >> h >> s;
	map<char, vector<string>> mp;
	char best; int total = 0;
	for(int i = 0; i < n; i++){
		char C; cin >> C;
		for(int j = 0; j < h; j++){
			string S; cin >> S;
			int on = 0, sum = 0;
			for(int k = 0; k < w; k++){
				if((on and S[k] == '.') or (!on and S[k] == '#')) sum++, on = !on;
			}
			if(on) sum++;
			if(sum > total) total = sum, best = C;
		}
	}

	for(int i = 0; i < (s+total-1)/total; i++) cout << best;
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
