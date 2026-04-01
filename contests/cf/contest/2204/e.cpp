#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int sum = 0, j;
vector<int> qnt(10), dig(1e6+10);

bool f(int x, string& ans){
	if(x <= 9){
		if(qnt[x] == 0 or (sum-x != 0 and sum-x != j)) return false;

		qnt[x]--;
		ans = to_string(x);
		return true;
	}

	int cur = x, can = 1;
	while(cur){
		if(!qnt[cur%10]) can = 0;
		qnt[cur%10]--, sum -= cur%10, cur /= 10;
	}

	if(can and f(dig[x], ans)){
		ans = to_string(x)+ans;
		return true;
	}

	cur = x;
	while(cur) qnt[cur%10]++, sum += cur%10, cur /= 10;

	return false;
}

void solve(){
	sum = 0; qnt = vector<int>(10);

	string s; cin >> s;
	for(auto c: s) qnt[c-'0']++, sum += int(c-'0');

	string ans = "";
	for(j = 1; j <= sum; j++){
		if(f(j, ans)) break;
	}

	string begin = "";
	for(int i = 9; i >= 0; i--) while(qnt[i]) begin += to_string(i), qnt[i]--;

	ans = begin+ans;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	for(int i = 1; i < 1e6+10; i++){
		int cur = i;
		while(cur) dig[i] += cur%10, cur /= 10;
	}

    while(ttt--) solve();

    exit(0);
}
