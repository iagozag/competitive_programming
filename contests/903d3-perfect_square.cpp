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
    int n; cin >> n;
    vector<string> v;
    for(int i = 0; i < n; i++){
        string c; cin >> c; v.pb(c);
    }

    ll sum = 0;
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++){
            vi arr;
            arr.pb(v[i][j]-'a');
            arr.pb(v[j][n-i-1]-'a');
            arr.pb(v[n-j-1][i]-'a');
            arr.pb(v[n-i-1][n-j-1]-'a');
            sort(all(arr));

            for(int k = 0; k < 3; k++) sum += arr[3] - arr[k];
        }
    }

    cout << sum << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
