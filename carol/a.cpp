#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long

const int INF = 0x3f3f3f3f;

const int MAX = 2e5+10, MOD = 1e9+7;

int r1, r2, r3;
int N, Q;

int32_t main(){
    vector<int> r(3);
    cin >> r[0] >> r[1] >> r[2];
    cin >> N >> Q;


    for(int i=0; i<Q; i++){
        int ci, li, cl, ll; cin >> ci >> li >> cl >> ll;
        ci--; cl--;
        int menor = min(r[ci], r[cl]);
        int maior = max(r[ci], r[cl]);

		long double comp = 2.0*3.14159265359*(long double)menor/(long double)N;

		int dist = min(li+N-ll, ll+N-li);
		dist = min(dist, (li >= ll ? li-ll : ll-li));

		cout << fixed << setprecision(10) << (long double)maior - (long double)menor + comp*(long double)dist << endl;
    }
}
