#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;
const long double eps = 1e-12;

int n, k;
string s;
vector<int> nxtl;

bool f(long double p){
	int l = 0; long double suml = 0, sumr = 0, mi = 0;
	for(int r = 0; r < n; r++){
		sumr += (s[r] == 'o')-p;

		while(l < nxtl[r]) suml += (s[l] == 'o')-p, mi = min(mi, suml), l++;

		if(nxtl[r] != -1 and sumr-mi > -eps) return true;
	}

	return false;
}

void solve(){
	cin >> n >> k;
	cin >> s;

	deque<int> dq; nxtl = vector<int>(n, -1);
	for(int i = 0; i < n; i++){
		if(i) nxtl[i] = nxtl[i-1];

		if(s[i] == 'o'){
			dq.push_back(i);
			if(dq.size() == k) nxtl[i] = dq.front(), dq.pop_front();
		}
	}

	long double l = .0, r = 1.0, ans = 0;
	while(r-l > eps){
		long double m = (l+r)/2.0;

		if(f(m)) ans = m, l = m;
		else r = m;
	}

	cout << fixed << setprecision(12) << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
