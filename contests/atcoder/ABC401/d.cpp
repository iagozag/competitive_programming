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
	int n, k; cin >> n >> k;
	string s; cin >> s;

	for(int i = 0; i < n; i++) if(s[i] == 'o'){
		k--;
		if(i) s[i-1] = '.';
		if(i < n-1) s[i+1] = '.';
	}

	if(k == 0){
		for(int i = 0; i < n; i++) if(s[i] == '?') s[i] = '.';
		cout << s << endl;
		return;
	}

	vector<int> diff(n);

	int can = 0, l = 0, r = 0;
	while(l < n){
		while(l < n and s[l] != '?') l++;
		if(l == n) break;

		r = l;
		while(r < n and s[r] == '?') r++;

		can += (r-l+1)/2;

		for(int i = l; i < r; i++) diff[i] = (r-l)%2;

		l = r;
	}

	if(can == k){
		for(int i = 0; i < n; i++){
			if(s[i] == '?' and diff[i]){
				s[i] = 'o';
				if(i) s[i-1] = '.';
				if(i < n-1) s[i+1] = '.';
			}
		}
	}

	cout << s << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
