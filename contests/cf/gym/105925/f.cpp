#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int) x.size()
#define ff first
#define ss second
#define int ll

int32_t main() { _
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i:v) {cin >> i; i+=1000;}

    vector<vector<int>> q(4,vector<int>(8001,0));
    
    q[0][v[0]] = 1;
    q[0][v[1]] += 1;
    q[0][v[2]] += 1;
    q[1][v[0]+v[1]] += 1;
    q[1][v[0]+v[2]] += 1;
    q[1][v[1]+v[2]] += 1;
    q[2][v[0]+v[1]+v[2]] = 1;

    for(int i=3;i<n;i++) {
        for(int j=0;j<=6000;j++) q[3][j+v[i]]+=q[2][j];
        for(int j=0;j<=4000;j++) q[2][j+v[i]]+=q[1][j];
        for(int j=0;j<=2000;j++) q[1][j+v[i]]+=q[0][j];
        q[0][v[i]]++;
    }

    int qq;
    cin >> qq;
    while(qq--) {
        int x;
        cin >> x;
        x+=4000;
        cout << q[3][x] << '\n';
    }
    return 0;
}
