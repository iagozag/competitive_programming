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
	vector<vector<int>> v(MAX, vector<int>(22));
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		for(int j = 2; j <= x/j; j++) if(x%j == 0){
			int pot = 0;
			while(x%j == 0) x /= j, pot++;
			v[j][pot]++;
		}
		if(x > 1) v[x][1]++;
	}

	int ans = 1;
	for(int i = 2; i < MAX; i++){
		int qnt = 0;
		for(int j = 1; j < 22; j++) qnt += v[i][j];
		if(qnt == 0) continue;

		v[i][0] = n-qnt;

		int num = 1, can = 0;

		if(v[i][0] > 1) continue;
		else if(v[i][0] == 1) can = 1;

		for(int j = 1; j < 22 and num < MAX; j++){
			num *= i;

			if(v[i][j] > 1){ ans *= num; break; }
			else if(v[i][j] == 1){
				if(!can) ans *= num, can = 1, num = 1;
				else{
					ans *= num;
					break;
				}
			}
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
