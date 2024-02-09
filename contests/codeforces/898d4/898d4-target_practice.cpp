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
    int idx1, idx2; ll sum = 0; char c;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> c;
            if(c == 'X'){
                (i > 4) ? idx1 = 9-i : idx1 = i;
                (j > 4) ? idx2 = 9-j : idx2 = j;

                sum += min(idx1+1,idx2+1);
            }
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
