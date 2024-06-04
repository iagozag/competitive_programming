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

int main(){ _
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int a; cin >> a; v.pb(a);
        }

        vector<int>v1(v.begin(), v.end());
        sort(v.begin(), v.end());

        if(v == v1){
            cout << 0 << endl;
            continue;
        }

        int ans;
        for(int i = n-1; i >= 1; i--){
            if(v[i] != v1[i]){
                ans = v[i];
                break;
            }
        }

        cout << ans << endl;
    }

    exit(0);
}
