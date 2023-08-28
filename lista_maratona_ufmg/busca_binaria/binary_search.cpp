#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a; cin >> a; v.pb(a);
    }

    for(int i = 0; i < k; i++){
        int a; cin >> a;

        bool flag = false;
        int l = 0, r = v.size()-1;
        for(int j = 0; j < 18; j++){
            int m = (l+r)/2;

            if(v[m] < a) l = m+1;
            else if(v[m] > a) r = m;
            else flag = true;
        }

        (flag) ? cout << "YES" : cout << "NO";
        cout << endl;
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
