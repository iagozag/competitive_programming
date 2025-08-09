#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
#define int ll

int a,b,c;

int f(int x) {
    int cc = x*x*x;
    return abs((a+c)*cc-b*x*x+b*c*x+(x+c)*(x-a));
}

int32_t main(){ _
    cin >> a >> b >> c;
    int ans = 0;
    
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        ans^=f(x);
    }

    cout << ans << '\n';
    exit(0);
}