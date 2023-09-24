#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; scanf("%d%d", &n, &m);
    double sum = 0;
    map<string,double> mp;
    mp["JD"] = 1;

    char a[11]; double b;
    for(int i = 0; i < n; i++)
        scanf("%s%lf", a, &b), mp[a] = b;

    for(int i = 0; i < m; i++)
        scanf("%lf%s", &b, a), sum += b*mp[a];

    printf("%.6lf\n", sum); 
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}


