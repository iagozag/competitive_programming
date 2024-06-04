#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n;
    vector<vi> v;
    for(int i = 0; i < n; i++){
        cin >> m;
        vi el(m);
        for(int j = 0; j < m; j++) cin >> el[j];
        sort(el.begin(), el.end());

        v.pb(el);
    }
    sort(v.begin(), v.end());

    int index, min = INF;
    for(int i = 0; i < n; i++){
        if(v[i][1] < min){
            min = v[i][1];
            index = i;
        }
    }

    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(i == index) sum += v[0][0];
        else sum += v[i][1];
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
