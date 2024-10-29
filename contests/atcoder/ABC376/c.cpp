#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> toys(n), boxes(n-1);
	for(auto &x: toys) cin >> x;
	for(auto &x: boxes) cin >> x;
	boxes.emplace_back(-1);

	sort(toys.begin(), toys.end()), sort(boxes.begin(), boxes.end());

	int i = n-1, j = n-1, need = -1;
	while(i >= 0){
		if(toys[i] <= boxes[j]) i--, j--;
		else if(need != -1){ cout << -1 << endl; return; }
		else need = toys[i], i--;
	}
	cout << need << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
