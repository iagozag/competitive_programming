#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10, MOD = 1e9+7;

vector<int> cnt(MAX);

void fact(int n){
	for(int i = 1; i*i <= n; i++) if(n%i == 0){
		cnt[i]++;
		if(i*i != n) cnt[n/i]++;
	}
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		fact(a);
	}
	int ma = 1;
	for(int i = 0; i < 1e6+1; i++) if(cnt[i] > 1) ma = i;
	cout << ma << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
