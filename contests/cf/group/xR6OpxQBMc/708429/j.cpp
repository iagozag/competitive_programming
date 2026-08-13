#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

const long double pi = acos(-1.0);

void solve(){
	long double a, b, c; cin >> a >> b >> c;
	int sum = a+b+c;
	long double first = pi*sum*sum;
	long double second = 0;
	if(b+c < a) second = a-b-c;
	if(a+b < c) second = c-b-a;
	if(a+c < b) second = b-c-a;

	second = second*second*pi;

	cout << fixed << setprecision(12) << first-second << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

