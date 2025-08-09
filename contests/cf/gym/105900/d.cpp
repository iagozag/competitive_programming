#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
#define int ll

int32_t main(){ _
    int r1, h1, r2, h2; cin >> r1 >> h1 >> r2 >> h2;
    cout << (3*r1*r1*h1 > 2*r2*r2*r2+r2*r2*h2 ? "Injusto" : "Justo") << endl;
    exit(0);
}