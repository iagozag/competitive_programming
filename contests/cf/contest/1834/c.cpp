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
	string s, t; cin >> s >> t;

	int cnt = 0, cnt2 = 0;
	for(int i = 0; i < n; i++) if(s[i] != t[i]) cnt++;
	reverse(s.begin(), s.end());
	for(int i = 0; i < n; i++) if(s[i] != t[i]) cnt2++;
	reverse(s.begin(), s.end());

	if(cnt == 0){ cout << 0 << endl; return; }

	int s1 = 0, s2 = 0;

	s1 += cnt*2-1+!(cnt&1);

	reverse(s.begin(), s.end()), s2 += 2;
	if(cnt2) cnt2--;
	s2 += cnt2*2-1+!(cnt2&1);	
	
	cout << min(s1, s2) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
