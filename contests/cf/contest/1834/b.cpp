#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

bool val(char c){
	return c >= '0' and c <= '9';
}

void solve(){
	string a, b; cin >> a >> b; int n = b.size();
	while((int)a.size() < (int)b.size()) a = "0"+a;

	int idx = -1;
	for(int i = n-1; i>= 0; i--) if(a[i] != b[i]) idx = i;

	int s1 = abs((a[idx]-'0')-(b[idx]-'0'));
	for(int i = idx+1; i < n; i++) s1 += 9;

	if(idx == -1) cout << 0 << endl;
	else cout << s1 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
