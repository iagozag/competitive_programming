#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e7+1, MOD = 1e9+7;

vector<int> pref(MAX);
vector<bool> is_prime(MAX, 1);

void solve(){
	int n; cin >> n;
	cout << pref[n] << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i < MAX; i++) {
		if (is_prime[i]){
			for (int j = i; j < MAX; j += i)
				is_prime[j] = 0, pref[j]++;
		}
	}

	for(int i = 2; i < MAX; i++) pref[i] += pref[i-1];

    while(ttt--) solve();

    exit(0);
}
